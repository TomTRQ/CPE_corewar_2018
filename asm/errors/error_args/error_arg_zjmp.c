/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** error_arg_zjmp
*/

#include "data.h"
#include "args.h"

int error_arg_zjmp(char **cmd, int *type, int idx)
{
    if (error_invalid_occur_parameter(cmd, type, ZJMP_ARGS) == 84)
        return (84);
    if (type[idx] != DIRECT && type[idx] != LABEL_CALL_D)
        return (84);
    return (0);
}