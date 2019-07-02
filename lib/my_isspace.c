/*
** EPITECH PROJECT, 2019
** my_isspace
** File description:
** my_isspace
*/

#include <stddef.h>
#include <stdlib.h>

int my_isspace(char str)
{
    if (str == ' ' || str == '\t' || str == '\n')
        return (1);
    return (0);
}