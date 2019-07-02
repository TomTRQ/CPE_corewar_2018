/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** No description
*/

#include <stdio.h>
#include "mylib.h"

char *my_strdup(char *str)
{
    int len = 0;
    char *data = NULL;
    int i = 0;

    if (!str)
        return (NULL);
    len = my_strlen(str);
    data = malloc(sizeof(char) * (len + 1));
    if (!data)
        return (NULL);
    for (; str[i] != '\0' && str[i] != '\n'; i++)
        data[i] = str[i];
    data[i] = '\0';
    return (data);
}