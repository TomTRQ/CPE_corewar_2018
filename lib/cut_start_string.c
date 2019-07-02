/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** cut_start_string
*/

#include <stdlib.h>
#include <string.h>
#include "mylib.h"

char *cut_start_string(char *str, int i)
{
    char *dest = NULL;
    int length = 0;
    int j = 0;

    if (!str)
        return (NULL);
    length = my_strlen(str);
    if (length <= i)
        return (NULL);
    dest = malloc(sizeof(char) * (length - i + 1));
    if (!dest)
        return (NULL);
    for (; i < length; i++, j++)
        dest[j] = str[i];
    dest[j] = '\0';
    return (dest);
}