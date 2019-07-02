/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** arr_len
*/

#include <stdlib.h>

int arrlen(char **arr)
{
    int size = 0;

    for (; arr && arr[size] != NULL; size++);
    return (size);
}