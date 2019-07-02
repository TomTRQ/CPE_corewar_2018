/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** error_null_header
*/

#include "data.h"

int error_null_header(data_t **data_arr, int type)
{
    int i = 0;

    for (; data_arr[i] && data_arr[i]->type[0] != type; i++);
    if (!data_arr[i])
        return (0);
    if (!data_arr[i]->cmd[1])
        return (84);
    if (data_arr[i]->cmd[1][0] && data_arr[i]->cmd[1][0] == '"' &&
        data_arr[i]->cmd[1][1] && data_arr[i]->cmd[1][1] == '"')
            return (84);
    return (0);
}