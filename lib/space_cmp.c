/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** space_cmp
*/

#include <stdlib.h>

int space_cmp(char *s1, char *s2)
{
    if (s1 == NULL || s2 == NULL)
        return (1);
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0' &&
        s1[i] != ' ' && s2[i] != ' '; i++)
        if (s1[i] != s2[i])
            return (1);
    return (0);
}