/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** parse_getline
*/

#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

char *remove_tab(char *buff)
{
    for (int k = 0; buff[k] != '\0'; k++) {
        if (buff[k] >= 7 && buff[k] <= 13)
            buff[k] = ' ';
    }
    return (buff);
}

char *remove_spaces(char *buff, char *tab, int i)
{
    int j = 0;

    for (; buff[i] != '\n' && buff[i] != '\0'; i++) {
        if (buff[i] == ' ' && (buff[i + 1] != ' ' &&
            buff[i + 1] != '\n' && buff[i + 1] != '\0')) {
            tab[j] = buff[i];
            j++;
        }
        else if (buff[i] != ' ') {
            tab[j] = buff[i];
            j++;
        }
    }
    tab[j] = '\0';
    return (tab);
}

char *parse_getline(char *buff)
{
    char *tab = NULL;
    int i = 0;
    int size = 0;

    if (!buff)
        exit(84);
    size = my_strlen(buff);
    tab = malloc(sizeof(char) * (size + 1));
    if (tab == NULL)
        exit(84);
    buff = remove_tab(buff);
    if (buff[i] == ' ')
        for (; buff[i] == ' '; i++);
    tab = remove_spaces(buff, tab, i);
    free(buff);
    return (tab);
}