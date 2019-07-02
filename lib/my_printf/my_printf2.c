/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** second file
*/

#include <stdio.h>
#include <stdarg.h>
#include "mylib.h"

void handle_flags(char *format, int *i, va_list ap)
{
    switch (format[*i + 1]) {
        case 'd' :
            my_put_nbr(va_arg(ap, int));
            break;
        case 'i' :
            my_put_nbr(va_arg(ap, int));
            break;
        case 's' :
            my_putstr(va_arg(ap, char *));
            break;
        case 'c' :
            my_putchar(va_arg(ap, int));
            break;
        case 'b' :
            my_put_nbr_base(va_arg(ap, int), "01");
            break;
        case 'p' :
            my_putstr("0x");
            my_put_nbr_base(va_arg(ap, int), "0123456789abcdef");
    }
}

int handle_flag_positive(char *format, int *i)
{
    if (format[*i + 1] == '+') {
        (*i)++;
        handle_space(format, i);
        if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
            my_putchar('+');
    }
    return (0);
}

int handle_flags_base(char *format, int *i, va_list ap)
{
    switch (format[*i + 1]) {
        case 'o' :
            my_put_nbr_base(va_arg(ap, int), "01234567");
            break;
        case 'u' :
            my_put_nbr_base(va_arg(ap, int), "0123456789");
            break;
        case 'x':
            my_put_nbr_base(va_arg(ap, int), "0123456789abcdef");
            break;
        case 'X':
            my_put_nbr_base(va_arg(ap, int), "0123456789ABCDEF");
            break;
        default:
            return (0);
    }
    return (0);
}

int handle_hashtag(char *format, int *i)
{
    if (format[*i + 1] == '#') {
        (*i)++;
        handle_space(format, i);
        if (format[*i + 1] == 'o')
            my_putchar('0');
        if (format[*i + 1] == 'x')
            my_putstr("0x");
        if (format[*i + 1] == 'X')
            my_putstr("0X");
    }
    return (0);
}

int handle_cond(char *format, int *i, va_list ap)
{
    handle_space(format, i);
    handle_hashtag(format, i);
    handle_zero(format, i);
    handle_flag_positive(format, i);
    handle_flags(format, i, ap);
    handle_flags_base(format, i, ap);
    handle_flags_base_for_s_up(format, i, ap);
    return (0);
}