/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** main
*/

#include <stdio.h>
#include <stdarg.h>
#include "mylib.h"

int cond_for_s_up(char *str, int const *j)
{
    if (str[*j] < 32 || str[*j] > 126) {
        if (str[*j] < 8) {
            my_putchar('\\');
            my_putstr("00");
        }
        if (str[*j] > 8 && str[*j] < 32) {
            my_putchar('\\');
            my_putchar('0');
        }
        if (str[*j] > 126)
            my_putchar('\\');
        my_put_nbr_base(str[*j], "01234567");
    }
    else
        my_putchar(str[*j]);
    return (0);
}

int handle_flags_base_for_s_up(char *format, int *i, va_list ap)
{
    if (format[*i + 1] == 'S') {
        char *str = va_arg(ap, char *);
        for (int j = 0; str[j] != '\0'; j++) {
            cond_for_s_up(str, &j);
        }
    }
    else if (format[*i + 1] == '%') {
        my_putchar('%');
    }
    return (0);
}

int handle_space(char *format, int *i)
{
    while (format[*i + 1] == 32)
        (*i)++;
    return (0);
}

int handle_zero(char *format, int *i)
{
    if (format[*i + 1] == '0') {
        (*i)++;
        handle_space(format, i);
    }
    return (0);
}

int my_printf(char *format, ...)
{
    va_list ap;
    int i = 0;

    va_start(ap, format);
    for (; format[i] != '\0' ; i++) {
        switch (format[i]) {
            case '%' :
                handle_cond(format, &i, ap);
                i++;
                break;
            default:
                my_putchar(format[i]);
        }
    }
    va_end(ap);
    return (0);
}