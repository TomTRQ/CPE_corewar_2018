/*
** EPITECH PROJECT, 2018
** my_put_nbr_base
** File description:
** tool
*/

#include "mylib.h"

int my_put_nbr_base(int nb, char *base)
{
    int result = nb / my_strlen(base);
    if (nb >= my_strlen(base)) {
        my_put_nbr_base(result, base);
        my_putchar(base[nb % my_strlen(base)]);
    }
    else
        my_putchar(base[nb]);
    return (0);
}