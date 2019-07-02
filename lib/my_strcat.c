/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** my_strcat.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

char *my_strcat(char *s1, char *s2)
{
    char *dest = NULL;
    int i = 0;
    int a = 0;

    if (s1 == NULL || s2 == NULL)
        return (NULL);
    dest = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
    for (; s1[i] != '\0'; i++, a++)
        dest[a] = s1[i];
    for (i = 0; s2[i] != '\0' && s2[i] != '\n'; i++, a++)
        dest[a] = s2[i];
    dest[a] = '\0';
    return (dest);
}