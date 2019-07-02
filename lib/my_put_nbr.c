/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "mylib.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = - nb;
        my_putchar('-');
    }
    if (nb > 9)
        my_put_nbr(nb/10);
    my_putchar(nb % 10 + '0');
    return (0);
}
