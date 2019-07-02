/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** error_arg_ldi
*/

#include "data.h"
#include "args.h"

int error_arg_ldi(char **cmd, int *type, int idx)
{
    if (error_invalid_occur_parameter(cmd, type, LDI_ARGS) == 84)
        return (84);
    idx++;
    if (type[idx] != DIRECT && type[idx] != LABEL_CALL_D &&
        type[idx] != REGISTER)
        return (84);
    idx++;
    if (type[idx] != REGISTER)
        return (84);
    return (0);
}