/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** write_param_description
*/

#include <stdlib.h>
#include "data.h"
#include "mylib.h"

void write_param_description(char const *binary_param, int fd)
{
    int description = binary_to_decimal(binary_param);

    write(fd, &description, 1);
}