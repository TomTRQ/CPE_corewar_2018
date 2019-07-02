/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** error_undeclared_label
*/

#include <stdlib.h>
#include "data.h"
#include "mylib.h"

int check_if_declared(char *label_call, char **label_arr, int type)
{
    char *clean_label = NULL;

    if (type == LABEL_CALL_D)
        clean_label = cut_start_string(label_call, 2);
    else
        clean_label = cut_start_string(label_call, 1);
    for (int i = 0; label_arr[i]; i++) {
        if (my_strcmp(label_arr[i], clean_label) == 0) {
            free(clean_label);
            return (0);
        }
    }
    free(clean_label);
    return (84);
}

int check_label_type(data_t *data, int i, char **label)
{
    if (data->type[i] == LABEL_CALL_D) {
        if (check_if_declared(data->cmd[i], label, LABEL_CALL_D) == 84)
            return (84);
    }
    else if (data->type[i] == LABEL_CALL_I) {
        if (check_if_declared(data->cmd[i], label, LABEL_CALL_I) == 84)
            return (84);
    }
    return (0);
}

int check_if_label(data_t *data, char **label)
{
    for (int i = 0; data->cmd[i]; i++)
        if (check_label_type(data, i, label) == 84)
            return (84);
    return (0);
}

int error_undeclared_label(data_t **data_arr, char **label)
{
    for (int i = 0; data_arr[i]; i++)
        if (check_if_label(data_arr[i], label) == 84)
            return (84);
    return (0);
}
