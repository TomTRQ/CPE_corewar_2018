/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** calcul_header_size
*/

#include <stdlib.h>
#include "data.h"
#include "mylib.h"

int calcul_header_size(data_t **data_arr)
{
    int arr_len = 0;
    int header_size = 0;

    for (int i = 0; data_arr[i]; i++) {
        arr_len = arrlen(data_arr[i]->cmd);
        for (int j = 0; j < arr_len; j++) {
            header_size += data_arr[i]->bytcode[j];
        }
    }
    header_size = REVERSE_LONG(header_size);
    return (header_size);
}