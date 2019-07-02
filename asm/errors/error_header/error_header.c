/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** error_header
*/

#include "data.h"
#include "op.h"
#include "error.h"

int error_header_occur(data_t **data_arr, int type)
{
    int count = 0;

    for (int i = 0; data_arr[i]; i++)
        if (data_arr[i]->type[0] == type)
            count++;
    if (count != 1)
        return (84);
    return (0);
}

int error_header_len(data_t **data_arr, int type, int max_length)
{
    int len = 0;

    for (int i = 0; data_arr[i]; i++) {
        if (data_arr[i]->type[0] == type) {
            len = calcul_len(data_arr[i]->cmd);
            break;
        }
    }
    if (len == 0 || len > max_length)
        return (84);
    return (0);
}

int error_pos_header(data_t **data_arr)
{
    int i = 0;
    int comment = FALSE;

    if (data_arr[0]->type[0] != NAME_INIT)
        return (84);
    for (; data_arr[i]; i++) {
        if (data_arr[i]->type[0] == COMMENT_INIT) {
            comment = TRUE;
            break;
        }
    }
    if (comment == TRUE) {
        if (data_arr[i - 1] && data_arr[i - 1]->type[0] == NAME_INIT)
            return (0);
        else
            return (84);
    }
    return (0);
}

int error_header_sentences_occur(data_t **data_arr, int type)
{
    int occur = 0;
    int i = 0;

    for (; data_arr[i] && data_arr[i]->type[0] != type; i++);
    if (!data_arr[i])
        return (0);
    for (int j = 0; data_arr[i]->cmd[j]; j++) {
        for (int k = 0; data_arr[i]->cmd[j][k] != '\0'; k++) {
            if (data_arr[i] && data_arr[i]->cmd[j][k] == '"')
                occur++;
        }
    }
    if (occur != 2)
        return (84);
    return (0);
}

int error_header(data_t **data_arr)
{
    if (error_header_len(data_arr, NAME_INIT, PROG_NAME_LENGTH) == 84 ||
        error_header_occur(data_arr, NAME_INIT) == 84)
        return (84);
    if (error_pos_header(data_arr) == 84)
        return (84);
    if (error_header_sentences_occur(data_arr, NAME_INIT) == 84 ||
        error_header_sentences_occur(data_arr, COMMENT_INIT) == 84)
        return (84);
    if (error_null_header(data_arr, NAME_INIT) == 84 ||
        error_null_header(data_arr, COMMENT_INIT) == 84)
            return (84);
    if (error_invalid_char_header(data_arr, NAME_INIT) == 84 ||
        error_invalid_char_header(data_arr, COMMENT_INIT) == 84)
            return (84);
    return (0);
}