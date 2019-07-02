/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** init_data_bytcode
*/

#include <stdlib.h>
#include "mylib.h"
#include "op.h"
#include "data.h"

int *init_data_bytcode(data_t *data)
{
    int k = 0;

    for (k = 0; data->cmd[k] != NULL; k++);
    data->bytcode = malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++)
        data->bytcode[i] = 0;
    return (data->bytcode);
}

data_t *fill_instructions_bytcode(char **instructions,
    int *bytcode, data_t *data_arr)
{
    int var = 0;

    if (data_arr->type[0] == LABEL_INIT)
        var = 1;
    else
        var = 0;
    for (int j = 0; instructions[j] != NULL; j++) {
        if (my_strcmp(data_arr->cmd[var], instructions[j]) == 0) {
            data_arr->bytcode[var] = bytcode[j];
            break;
        }
    }
    return (data_arr);
}

data_t **init_data_instruction_bytcode(data_t **data_arr)
{
    char **instructions = init_instruction_name();
    int *bytcode = init_instruction_bytcode();

    for (int i = 0; data_arr[i] != NULL; i++) {
        data_arr[i] = fill_instructions_bytcode(
        instructions, bytcode, data_arr[i]);
    }
    free(instructions);
    free(bytcode);
    return (data_arr);
}