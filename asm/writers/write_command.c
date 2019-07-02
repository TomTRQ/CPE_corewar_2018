/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** write_command
*/

#include <stdlib.h>
#include "data.h"

void write_command(data_t **data_arr, int fd)
{
    char *param = NULL;

    for (int i = SKIP_HEADER; data_arr[i]; i++) {
        if (data_arr[i]->type[0] == INSTRUCTION) {
            write_instruction_code(data_arr[i]->cmd[0], fd);
            if (data_arr[i] && data_arr[i]->bytcode[0] > 1) {
                param = calcul_param_description(data_arr[i]);
                write_param_description(param, fd);
                free(param);
            }
        }
        else if (data_arr[i]->type[0] == LABEL_INIT && data_arr[i]->cmd[1]) {
            write_instruction_code(data_arr[i]->cmd[1], fd);
            if (data_arr[i] && data_arr[i]->bytcode[1] > 1) {
                param = calcul_param_description(data_arr[i]);
                write_param_description(param, fd);
                free(param);
            }
        } write_param_value(data_arr, i, fd);
    }
}