/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** create_data
*/

#include <stdlib.h>
#include "data.h"
#include "op.h"
#include "mylib.h"

char **fill_cmd(char *string, char **cmd)
{
    int j = 0;
    int k = 0;

    for (int i = 0; string[i] != '\0'; i++, k++) {
        if (string[i] == SEPARATOR_CHAR || string[i] == ' ') {
            cmd[j][k] = '\0';
            j++;
            k = -1;
            cmd[j] = malloc(sizeof(char) * (count_size_line(string) + 1));
        }
        else
            cmd[j][k] = string[i];
    }
    cmd[j][k] = '\0';
    cmd[j + 1] = NULL;
    return (cmd);
}

char **init_cmd(char *string)
{
    char **cmd = NULL;
    int size = count_occur(string, SEPARATOR_CHAR) + count_occur(string, ' ');

    cmd = malloc(sizeof(char *) * (size + 2));
    if (!cmd)
        return (NULL);
    cmd[0] = malloc(sizeof(char) * (count_size_line(string) + 1));
    cmd = fill_cmd(string, cmd);
    return (cmd);
}

data_t **fill_data(char **file, data_t **data_arr)
{
    int ind_arr = 0;
    int i = 0;

    for (; file && file[i]; i++) {
        if (file[i][0] != COMMENT_CHAR && file[i][0] != '\0') {
            data_arr[ind_arr] = malloc(sizeof(data_t));
            if (!data_arr[ind_arr])
                return (NULL);
            data_arr[ind_arr]->cmd = init_cmd(file[i]);
            data_arr[ind_arr]->bytcode = init_data_bytcode(data_arr[ind_arr]);
            ind_arr++;
        }
    }
    data_arr[ind_arr] = NULL;
    return (data_arr);
}

data_t **create_data(char **file)
{
    data_t **data_arr = NULL;
    int size_arr = count_size_file(file);

    data_arr = malloc(sizeof(data_t) * (size_arr + 1));
    if (!data_arr)
        return (NULL);
    data_arr = fill_data(file, data_arr);
    free_arr(file);
    return (data_arr);
}