/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** init_size
*/

#include <stdlib.h>
#include "data.h"
#include "mylib.h"

data_t **init_size(data_t **data_arr)
{
    for (int i = 0; data_arr[i]; i++)
        data_arr[i]->size = arrlen(data_arr[i]->cmd);
    return (data_arr);
}