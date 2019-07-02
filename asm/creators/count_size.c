/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** coun_size
*/

#include "op.h"

int count_size_file(char **data)
{
    int size = 0;

    for (int i = 0; data && data[i]; i++)
        if (data[i][0] != '\n' && data[i][0] != COMMENT_CHAR)
            size++;
    return (size);
}

int count_size_line(char *str)
{
    static int i = 0;
    int size = 0;

    for (; str[i] != ' ' && str[i] != SEPARATOR_CHAR; i++, size++)
        if (str[i] == '\0') {
            i = -1;
            break;
        }
    i++;
    return (size);
}
