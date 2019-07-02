/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** write_header
*/

#include "data.h"
#include "op.h"
#include "mylib.h"

char fill_header(int *index, char c)
{
    if (c != '"') {
        (*index)++;
        return (c);
    } else
        return (0);
}

struct header_s header_name(data_t **data_arr, struct header_s header)
{
    int i = 0;
    int idx = 0;

    for (; data_arr[i] && data_arr[i]->type &&
    data_arr[i]->type[0] != NAME_INIT; i++);
    if (data_arr[i] == NULL)
        return (header);
    for (int j = 1; data_arr[i]->cmd[j]; j++) {
        for (int k = 0; data_arr[i]->cmd[j][k] != '\0'; k++)
            header.prog_name[idx] = fill_header(&idx, data_arr[i]->cmd[j][k]);
        if (data_arr[i]->cmd[j + 1]) {
            header.prog_name[idx] = 32;
            idx++;
        }
    }
    return (header);
}

struct header_s header_comment(data_t **data_arr, struct header_s header)
{
    int i = 0;
    int idx = 0;

    for (; data_arr[i] && data_arr[i]->type &&
    data_arr[i]->type[0] != COMMENT_INIT; i++);
    if (data_arr[i] == NULL)
        return (header);
    for (int j = 1; data_arr[i]->cmd[j]; j++) {
        for (int k = 0; data_arr[i]->cmd[j][k] != '\0'; k++)
            header.comment[idx] = fill_header(&idx, data_arr[i]->cmd[j][k]);
        if (data_arr[i]->cmd[j + 1] != NULL) {
            header.comment[idx] = 32;
            idx++;
        }
    }
    return (header);
}

void write_header(data_t **data_arr, int fd)
{
    struct header_s header;

    for (int i = 0; i <= PROG_NAME_LENGTH + 1; i++)
        header.prog_name[i] = 0;
    for (int i = 0; i <= COMMENT_LENGTH + 1; i++)
        header.comment[i] = 0;
    header.magic = REVERSE_LONG(COREWAR_EXEC_MAGIC);
    header = header_name(data_arr, header);
    header = header_comment(data_arr, header);
    header.prog_size = calcul_header_size(data_arr);
    write(fd, &header, sizeof(header));
}