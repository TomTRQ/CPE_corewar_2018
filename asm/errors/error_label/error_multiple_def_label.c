/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** error_multiple_def_label
*/

#include "mylib.h"

int check_multiple_label(char **label_arr, char *label)
{
    int occur = 0;

    for (int i = 0; label_arr[i]; i++)
        if (my_strcmp(label_arr[i], label) == 0)
            occur++;
    if (occur == 1)
        return (0);
    return (84);
}

int error_multiple_def_label(char **label)
{
    for (int i = 0; label[i]; i++)
        if (check_multiple_label(label, label[i]) == 84)
            return (84);
    return (0);
}