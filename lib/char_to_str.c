/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** char_to_str
*/

#include "stdlib.h"

char *char_to_str(char c)
{
    char *str = NULL;

    str = malloc(sizeof(char) * (2));
    if (!str)
        return (NULL);
    str[0] = c;
    str[1] = '\0';
    return (str);
}