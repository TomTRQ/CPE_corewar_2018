/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** error_invalid_char_header
*/

#include <stdlib.h>
#include "data.h"
#include "mylib.h"

char *array_to_str(char **arr)
{
    int len = calcul_len(arr);
    char *str = NULL;
    int idx = 0;

    str = malloc(sizeof(char) * (len + 1));
    for (int i = 1; arr[i]; i++) {
        for (int j = 0; arr[i][j] != '\0'; j++, idx++)
            str[idx] = arr[i][j];
    }
    str[idx] = '\0';
    return (str);
}

int error_invalid_char_header(data_t **data_arr, int type)
{
    char *str = NULL;
    int i = 0;
    int j = 0;
    int occur = 0;

    for (; data_arr[i] && data_arr[i]->type[0] != type; i++);
    if (!data_arr[i])
        return (0);
    str = array_to_str(data_arr[i]->cmd);
    for (; str[j] != '\0' && occur < 2; j++)
        if (str[j] == '"')
            occur++;
    for (; str[j] != '\0'; j++) {
        free(str);
        return (84);
    }
    free(str);
    return (0);
}