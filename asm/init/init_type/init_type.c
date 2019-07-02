/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** init_type
*/

#include <stdlib.h>
#include "op.h"
#include "data.h"
#include "mylib.h"

int *malloc_type(data_t *data)
{
    int k = 0;

    for (k = 0; data->cmd[k] != NULL; k++);
    data->type = malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++)
        data->type[i] = 0;
    return (data->type);
}

int condition_type2(char *cmd, int type)
{
    for (int j = 0; op_tab[j].mnemonique != NULL; j++)
        if (my_strcmp(cmd, op_tab[j].mnemonique) == 0)
        type = INSTRUCTION;
    if (my_strcmp(cmd, NAME_CMD_STRING) == 0)
        type = NAME_INIT;
    if (my_strcmp(cmd, COMMENT_CMD_STRING) == 0)
        type = COMMENT_INIT;
    return (type);
}

data_t *condition_type(data_t *data)
{
    data->type = malloc_type(data);
    for (int i = 0; data->cmd && data->cmd[i] != NULL; i++) {
        if (data->cmd[i][0] == 'r' && i != 0)
            data->type[i] = REGISTER;
        if (data->cmd[i][0] == DIRECT_CHAR)
            data->type[i] = DIRECT;
        if (data->cmd[i][0] == DIRECT_CHAR && data->cmd[i][1] == LABEL_CHAR)
            data->type[i] = LABEL_CALL_D;
        if (data->cmd[i][0] == LABEL_CHAR)
            data->type[i] = LABEL_CALL_I;
        if (data->cmd[i][0] >= '0' && data->cmd[i][0] <= '9')
            data->type[i] = INDIRECT;
        if (data->cmd[i][my_strlen(data->cmd[i]) - 1] == LABEL_CHAR)
            data->type[i] = LABEL_INIT;
        if (my_strcmp(data->cmd[0], NAME_CMD_STRING) == 0 && i != 0)
            data->type[i] = NAME_CONTENT;
        if (my_strcmp(data->cmd[0], COMMENT_CMD_STRING) == 0 && i != 0)
            data->type[i] = COMMENT_CONTENT;
        data->type[i] = condition_type2(data->cmd[i], data->type[i]);
    } return (data);
}

data_t **init_type(data_t **data_arr)
{
    for (int i = 0; data_arr[i]; i++)
        data_arr[i] = condition_type(data_arr[i]);
    return (data_arr);
}