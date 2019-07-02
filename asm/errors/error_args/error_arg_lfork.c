/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** error_arg_lfork
*/

#include "data.h"
#include "args.h"

int error_arg_lfork(char **cmd, int *type, int idx)
{
    if (error_invalid_occur_parameter(cmd, type, LFORK_ARGS) == 84)
        return (84);
    if (type[idx] != DIRECT && type[idx] != LABEL_CALL_D)
        return (84);
    return (0);
}