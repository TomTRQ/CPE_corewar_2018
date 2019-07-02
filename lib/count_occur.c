/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** count_occur
*/

#include "stdio.h"

int count_occur(char *str, char c)
{
    int count = 0;

    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            count++;
    }
    return (count);
}