/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** error_arg_st
*/

#include "data.h"
#include "args.h"

int error_arg_st(char **cmd, int *type, int idx)
{
    if (error_invalid_occur_parameter(cmd, type, ST_ARGS) == 84)
        return (84);
    if (type[idx] != REGISTER)
        return (84);
    idx++;
    if (type[idx] != INDIRECT &&
    type[idx] != LABEL_CALL_I && type[idx] != REGISTER)
        return (84);
    return (0);
}