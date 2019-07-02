/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** write_param_value
*/

#include <stdlib.h>
#include "op.h"
#include "data.h"
#include "mylib.h"

void write_parameter(char *param, int fd, int size, int cut_index)
{
    char *value = NULL;
    int param_size = 0;

    value = cut_start_string(param, cut_index);
    if (!value)
        return;
    param_size = my_atoi(value);
    if (size == IND_SIZE)
        param_size = REVERSE_SHORT(param_size);
    else if (size == DIR_SIZE)
        param_size = REVERSE_LONG(param_size);
    write(fd, &param_size, size);
    free(value);
}

void write_range_before(data_t **data_arr, int idx, char *label, int fd)
{
    int range = check_label_before(data_arr, idx, label);
    int neg = 255;

    for (int i = 0; i < IND_SIZE - 1; i++)
        write(fd, &neg, 1);
    write(fd, &range, 1);
    free(label);
}

void write_label(data_t **data_arr, int idx, char *name, int fd)
{
    int range = 0;
    int zero = 0;
    char *label_char = NULL;
    char *cut_name = NULL;
    char *label = NULL;

    (name[0] == DIRECT_CHAR) ? (cut_name = cut_start_string(name, 2)) :
    (cut_name = cut_start_string(name, 1));
    label_char = char_to_str(LABEL_CHAR);
    label = my_strcat(cut_name, label_char);
    free(label_char);
    free(cut_name);
    range = check_label_after(data_arr, idx, label);
    if (range == 0) {
        write_range_before(data_arr, idx, label, fd);
        return;
    } for (int i = 0; i < IND_SIZE - 1; i++)
        write(fd, &zero, 1);
    write(fd, &range, 1);
    free(label);
}

void write_param_value(data_t **data_arr, int idx, int fd)
{
    for (int i = 1; data_arr[idx]->cmd[i]; i++) {
        if (data_arr[idx]->type[i] == REGISTER)
            write_parameter(data_arr[idx]->cmd[i], fd, 1,
            CUT_REG_DIR_SIZE);
        else if (data_arr[idx]->type[i] == INDIRECT)
            write_parameter(data_arr[idx]->cmd[i], fd, IND_SIZE, 0);
        if (data_arr[idx]->type[i] == DIRECT &&
            check_special_cmd(data_arr[idx]->cmd[0]) == FALSE)
            write_parameter(data_arr[idx]->cmd[i], fd,
            DIR_SIZE, CUT_REG_DIR_SIZE);
        else if (data_arr[idx]->type[i] == DIRECT &&
            check_special_cmd(data_arr[idx]->cmd[0]) == TRUE)
            write_parameter(data_arr[idx]->cmd[i], fd,
            IND_SIZE, CUT_REG_DIR_SIZE);
        if (data_arr[idx]->type[i] == LABEL_CALL_D ||
            data_arr[idx]->type[i] == LABEL_CALL_I) {
            write_label(data_arr, idx, data_arr[idx]->cmd[i], fd);
            }
    }
}