/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** calcul_label_range
*/

#include "data.h"
#include "mylib.h"
#include "op.h"

int add_empty_size(int size, data_t *data)
{
    for (int i = arrlen(data->cmd) - 1; i >= 0; i--)
        size += data->bytcode[i];
    return (size);
}

int check_label_after(data_t **data_arr, int idx, char *name)
{
    int size = 0;
    int arr_len = 0;

    for (; data_arr[idx]; idx++) {
        arr_len = arrlen(data_arr[idx]->cmd);
        if (my_strcmp(data_arr[idx]->cmd[0], name) == TRUE)
            return (size);
        for (int i = 0; i < arr_len; i++)
            size += data_arr[idx]->bytcode[i];
    }
    return (0);
}

int check_label_before(data_t **data_arr, int idx, char *name)
{
    int size = 0;
    int arr_len = 0;

    for (idx -= 1; idx > 0; idx--) {
        arr_len = arrlen(data_arr[idx]->cmd) - 1;
        if (my_strcmp(data_arr[idx]->cmd[0], name) == TRUE) {
            size = add_empty_size(size, data_arr[idx]);
            return (256 - size);
        }
        for (int i = 0; i <= arr_len; i++)
            size += data_arr[idx]->bytcode[i];
    }
    return (0);
}

int calcul_label_range(data_t **data_arr, int idx, char *name)
{
    int range = 0;

    if (name[0] == DIRECT_CHAR)
        name = cut_start_string(name, 1);
    name = cut_start_string(name, 1);
    name = my_strcat(name, ":");
    range = check_label_after(data_arr, idx, name);
    if (range == 0) {
        range = check_label_before(data_arr, idx, name);
        return (range);
    }
    else
        return (range);
    return (0);
}