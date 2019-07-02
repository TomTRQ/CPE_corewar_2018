/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** free_data_arr
*/

#include <stdlib.h>
#include "data.h"
#include "mylib.h"

void free_data_arr(data_t **data_arr)
{
    for (int i = 0; data_arr[i]; i++) {
        free_arr(data_arr[i]->cmd);
        free(data_arr[i]->bytcode);
        free(data_arr[i]->type);
        free(data_arr[i]);
    }
    free(data_arr);
}