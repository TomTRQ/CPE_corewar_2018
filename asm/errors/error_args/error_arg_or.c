/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** error_arg_or
*/

#include "data.h"
#include "args.h"

int error_arg_or(char **cmd, int *type, int idx)
{
    if (error_invalid_occur_parameter(cmd, type, OR_ARGS) == 84)
        return (84);
    if (type[idx + 2] != REGISTER)
        return (84);
    return (0);
}