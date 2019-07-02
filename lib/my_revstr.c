/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** tak03
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mylib.h"

char *my_revstr(char *str)
{
    int len = 0;
    char *revstr = NULL;
    int i = 0;

    if (!str)
        return (NULL);
    len = my_strlen(str);
    revstr = malloc(sizeof(char) * (len + 1));
    for (int max = len - 1; i < len; i++, max--)
        revstr[i] = str[max];
    revstr[i] = '\0';
    return (revstr);
}