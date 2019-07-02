/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** error_label
*/

#include "data.h"
#include "mylib.h"
#include "error.h"

char **clean_label_char(char **label)
{
    char **clean_label = NULL;
    int len = 0;
    int i = 0;

    len = arrlen(label);
    clean_label = malloc(sizeof(char *) * (len + 1));
    for (; label[i]; i++)
        clean_label[i] = cut_end_string(label[i], 1);
    clean_label[i] = NULL;
    free_arr(label);
    return (clean_label);
}

int error_label(data_t **data_arr)
{
    char **label = init_label_array(data_arr);

    label = clean_label_char(label);
    if (error_undeclared_label(data_arr, label) == 84 ||
        error_multiple_def_label(label) == 84)
        return (84);
    free_arr(label);
    return (0);
}