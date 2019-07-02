/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** write_instructions
*/

#include <stdlib.h>
#include "data.h"

void write_file(data_t **data_arr, int fd)
{
    write_header(data_arr, fd);
    write_command(data_arr, fd);
}