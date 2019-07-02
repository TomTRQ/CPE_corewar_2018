/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** error_arg_xor
*/

#include "data.h"
#include "args.h"

int error_arg_xor(char **cmd, int *type, int idx)
{
    if (error_invalid_occur_parameter(cmd, type, XOR_ARGS) == 84)
        return (84);
    idx += 2;
    if (type[idx] != REGISTER)
        return (84);
    return (0);
}