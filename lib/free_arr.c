/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** free_arr
*/

#include <stdlib.h>

void free_arr(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}