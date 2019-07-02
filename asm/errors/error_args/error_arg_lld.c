/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** error_arg_lld
*/

#include "data.h"
#include "args.h"

int error_arg_lld(char **cmd, int *type, int idx)
{
    if (error_invalid_occur_parameter(cmd, type, LLD_ARGS) == 84)
        return (84);
    if (type[idx] != DIRECT && type[idx] != LABEL_CALL_D &&
    type[idx] != INDIRECT && type[idx] != LABEL_CALL_I)
        return (84);
    idx++;
    if (type[idx] != REGISTER)
        return (84);
    return (0);
}