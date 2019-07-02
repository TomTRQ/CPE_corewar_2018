/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** init_parameters_bytcode
*/

#include <stdlib.h>
#include "op.h"
#include "data.h"
#include "mylib.h"

data_t *fill_parameters_bytcode(data_t *data)
{
    if (my_strcmp(data->cmd[0], COMMENT_CMD_STRING) == 0 ||
        my_strcmp(data->cmd[0], NAME_CMD_STRING) == 0) {
        for (int i = 1; data->cmd && data->cmd[i]; i++)
            data->bytcode[i] = 0;
        return (data);
    }
    for (int i = 1; data->cmd && data->cmd[i]; i++) {
        if (data->cmd[i][0] == 'r')
            data->bytcode[i] = 1;
        else if (data->cmd[i][0] == '%' && my_strcmp(STI, data->cmd[0]) == 1 &&
            my_strcmp(ZJMP, data->cmd[0]) == 1 &&
            my_strcmp(FORK, data->cmd[0]) == 1)
            data->bytcode[i] = DIR_SIZE;
        else
            data->bytcode[i] = IND_SIZE;

    }
    return (data);
}

data_t **init_parameters_bytcode(data_t **data_arr)
{
    for (int i = 0; data_arr[i] != NULL; i++)
        data_arr[i] = fill_parameters_bytcode(data_arr[i]);
    return (data_arr);
}