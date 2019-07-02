/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** my_atoi
*/

#include <stdlib.h>

int check_atoi(char const *tab)
{
    if (tab == NULL)
        return (-1);
    for (int i = 0; tab[i] != '\0'; i++) {
        if ((tab[i] > '9' || tab[i] < '0') && tab[i] != '-')
            return (-1);
    }
    return (0);
}

int my_atoi(char *tab)
{
    int pows = 1;
    int raws = 0;
    int neg = 0;
    int j = 0;
    int i = 0;

    if (check_atoi(tab) == -1)
        return (-1);
    if (tab[0] == '-') {
        j++;
        i++;
        neg = 1;
    }
    for (; tab[i] != '\0'; i++, pows *= 10);
    pows = pows / 10;
    for (; tab[j] != '\0'; j++, pows /= 10)
        raws = raws + (tab[j] - 48) * pows;
    raws *= (neg == 1) ? (-1) : (1);
    return (raws);
}