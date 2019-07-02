/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** calcul_name_len
*/

#include <stdlib.h>
#include "data.h"
#include "mylib.h"

int calcul_len(char **cmd)
{
    int len = 0;

    for (int i = 1; cmd[i] != NULL; cmd++)
        len += my_strlen(cmd[i]);
    return (len);
}