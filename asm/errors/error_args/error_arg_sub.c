/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** error_arg_sub
*/

#include "data.h"
#include "args.h"

int error_arg_sub(char **cmd, int *type, int idx)
{
    if (error_invalid_occur_parameter(cmd, type, SUB_ARGS) == 84)
        return (84);
    for (; cmd[idx]; idx++) {
        if (type[idx] != REGISTER)
            return (84);
    }
    return (0);
}