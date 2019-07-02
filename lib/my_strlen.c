/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** my_strlen
*/

#include "mylib.h"
#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
