/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** error_handling
*/

#include "data.h"
#include "error.h"
#include "mylib.h"
#include "args.h"

int check_valid_inst(data_t *data, int j, int nb)
{
    if (my_strcmp(data->cmd[nb - 1], INST_LIST[j].name) == 0)
        if (INST_LIST[j].inst(data->cmd, data->type, nb) == 84)
            return (84);
    return (0);
}

int check_label_init(data_t *data, int j)
{
    if (data->type[0] == LABEL_INIT) {
        if (check_valid_inst(data, j, 2) == 84)
            return (84);
    }
    return (0);
}

int check_inst_init(data_t *data, int j)
{
    if (data->type[0] == INSTRUCTION)
        if (check_valid_inst(data, j, 1) == 84)
            return (84);
    return (0);
}

int parse_instructions(data_t *data)
{
    for (int j = 0; INST_LIST[j].name != NULL; j++)
        if (check_label_init(data, j) == 84)
            return (84);
        else if (check_inst_init(data, j) == 84)
            return (84);
    return (0);
}

int error_handling(data_t **data_arr)
{
    if (error_header(data_arr) == 84)
        return (84);
    if (error_label(data_arr) == 84)
        return (84);
    if (error_direct_value(data_arr) == 84)
        return (84);
    for (int i = 0; data_arr[i]; i++) {
        if (error_unknow_command(data_arr[i]) == 84)
            return (84);
        if (parse_instructions(data_arr[i]) == 84)
            return (84);
    }
    return (0);
}