/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_putstr
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    write(1, str, i);
    return (0);
}
