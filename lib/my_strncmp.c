/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** my_strncmp.c
*/

#include <stdlib.h>

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (1);
    while (s1[i] != '\0' && s2[i] != '\0' && i < n) {
        if (s1[i] != s2[i])
            return (1);
        i++;
    }
    return (0);
}