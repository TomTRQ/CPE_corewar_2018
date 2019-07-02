/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** calcul_description
*/

#include <stdlib.h>
#include "data.h"

char *fill_conditions_param_description(char *param_size, int type,
int count_type)
{
    if (type == REGISTER) {
        param_size[count_type] = '0';
        param_size[count_type + 1] = '1';
    } else if (type == DIRECT || type == LABEL_CALL_D) {
        param_size[count_type] = '1';
        param_size[count_type + 1] = '0';
    } else {
        param_size[count_type] = '1';
        param_size[count_type + 1] = '1';
    }
    return (param_size);
}

char *calcul_param_description(data_t *data)
{
    char *param_size  = NULL;
    int count_type = 0;

    param_size = malloc(sizeof(char) * (BINARY_LENGTH + 1));
    if (!param_size)
        return (NULL);
    for (int i = 0; i < BINARY_LENGTH; i++)
        param_size[i] = '0';
    param_size[BINARY_LENGTH] = '\0';
    for (int i = 1; i < data->size; i++, count_type += 2) {
        param_size = fill_conditions_param_description(param_size,
            data->type[i], count_type);
        param_size[8] = '\0';
    }
    return (param_size);
}