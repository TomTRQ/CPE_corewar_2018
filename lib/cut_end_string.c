/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** cut_end_string
*/

#include <stdlib.h>
#include "mylib.h"

char *cut_end_string(char *str, int idx)
{
    int len = 0;
    char *cut_str = NULL;
    int i = 0;

    if (!str)
        return (NULL);
    len = my_strlen(str);
    if (idx >= len)
        return (NULL);
    cut_str = malloc(sizeof(char) * (len - idx + 1));
    if (!cut_str)
        return (NULL);
    for (; i < (len - idx); i++)
        cut_str[i] = str[i];
    cut_str[i] = '\0';
    return (cut_str);
}