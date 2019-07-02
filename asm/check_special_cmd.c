/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** check_special_cmd
*/

#include "mylib.h"
#include "data.h"
#include "op.h"

int check_special_cmd(char *cmd)
{
    if (my_strcmp(cmd, STI) == FALSE && my_strcmp(cmd, ZJMP) == FALSE &&
        my_strcmp(cmd, FORK) == FALSE)
        return (FALSE);
    return (TRUE);
}

