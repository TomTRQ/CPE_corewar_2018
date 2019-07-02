/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** error_unknow_command
*/

#include "op.h"
#include "data.h"
#include "mylib.h"

int error_unknow_command(data_t *data)
{
    int idx = 0;

    if (data->type[0] == LABEL_INIT)
        idx = 1;
    else
        idx = 0;
    if (!data->cmd[idx])
        return (0);
    if (data->type[idx] != INSTRUCTION && data->type[idx] != NAME_INIT &&
        data->type[idx] != COMMENT_INIT)
        return (84);
    return (0);
}