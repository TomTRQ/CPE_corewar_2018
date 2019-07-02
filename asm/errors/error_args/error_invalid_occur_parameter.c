/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** error_invalid_occur_parameter
*/

#include "data.h"
#include "mylib.h"

int error_invalid_occur_parameter(char **cmd, int *type, int arg_size)
{
    int len = arrlen(cmd);

    if (type[0] == LABEL_INIT) {
        if (len != arg_size + 1)
            return (84);
    }
    else {
        if (len != arg_size)
            return (84);
    }
    return (0);
}