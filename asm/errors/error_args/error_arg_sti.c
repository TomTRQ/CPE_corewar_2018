/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** error_arg_sti
*/

#include "data.h"
#include "args.h"

int error_arg_sti(char **cmd, int *type, int idx)
{
    if (error_invalid_occur_parameter(cmd, type, STI_ARGS) == 84)
        return (84);
    if (type[idx] != REGISTER)
        return (84);
    idx += 2;
    if (type[idx] != REGISTER &&
    type[idx] != LABEL_CALL_D && type[idx] != DIRECT)
        return (84);
    return (0);
}