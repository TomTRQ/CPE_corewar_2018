/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** cut_str
*/

#include "mylib.h"

char *cut_str(char *str)
{
    static int i = 0;
    int j = i;
    int size = 0;
    int a = 0;
    char *lign = NULL;

    if (str == NULL)
        return (NULL);
    for (; str[j] != '\0' && str[j] != ' ' && str[j] != ','; j++, size++);
    lign = malloc(sizeof(char) * (size + 2));
    for (a = 0; str[i] != ' ' && str[i] != ','; i++, a++) {
        if (str[i] == '\0') {
            i = -1;
            break;
        }
        lign[a] = str[i];
    }
    i++;
    lign[a] = '\0';
    return (lign);
}