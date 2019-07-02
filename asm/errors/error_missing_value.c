/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** error_missing_value
*/

#include "data.h"
#include "op.h"
#include "mylib.h"

int check_value(char *cmd)
{
    for (int i = 1; cmd && cmd[i] != '\0'; i++)
        if (cmd[i] < '0' || cmd[i] > '9')
            return (84);
    return (0);
}

int check_missing_value(char *cmd, int type, int type_asked)
{
    if (my_strlen(cmd) == 1 && type != INDIRECT  && type != COMMENT_CONTENT &&
        type != COMMENT_INIT && type != NAME_CONTENT && type != NAME_INIT) {
        return (84);
    }
    if (type == type_asked)
        if (check_value(cmd) == 84)
            return (84);
    return (0);
}

int error_missing_value(data_t *data, int type)
{
    for (int j = 0; data->cmd[j]; j++) {
        if (check_missing_value(data->cmd[j],
            data->type[j], type) == 84)
        return (84);
    }
    return (0);
}

int error_direct_value(data_t **data_arr)
{
    for (int i = 0; data_arr[i]; i++)
        if (error_missing_value(data_arr[i], DIRECT) == 84)
            return (84);
    return (0);
}