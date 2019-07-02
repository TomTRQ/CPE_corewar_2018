/*
** EPITECH PROJECT, 2018
** load_file.c
** File description:
** No description
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mylib.h"
#include "op.h"

char *fill_line(char *str, char *tmp, int i, int j)
{
    if (str[j] == '\0') {
        tmp[i] = '\0';
        return (tmp);
    }
    tmp[i] = ' ';
    i++;
    j++;
    for (; str[j] != '\0'; j++) {
        if (str[j] != ' ' || (str[j - 1] != SEPARATOR_CHAR &&
        str[j] == ' ')) {
            tmp[i] = str[j];
            i++;
        }
    }
    tmp[i] = '\0';
    return (tmp);
}

char *clean(char *str)
{
    char *tmp = NULL;
    int size = 0;
    int i = 0;
    int j = 0;

    if (!str) return (NULL);
    if (space_cmp(str, NAME_CMD_STRING) == 0 ||
    (space_cmp(str, COMMENT_CMD_STRING) == 0))
        return (str);
    str = parse_getline(str);
    size = my_strlen(str);
    tmp = malloc(sizeof(char) * (size + 2));
    if (!tmp) return (NULL);
    for (; str[j] != '\0' && str[j] != ' '; j++, i++)
        tmp[i] = str[j];
    tmp = fill_line(str, tmp, i, j);
    free(str);
    return (tmp);
}

char **fill_array_file(FILE *ptr)
{
    size_t size = 0;
    char **file = NULL;
    char *line = NULL;
    int i = 0;

    for (; getline(&line, &size, ptr) != -1; i++) {
        file = realloc(file, (sizeof(char *) * (i + 1)));
        if (!file)
            return (NULL);
        file[i] = my_strdup(line);
        file[i] = clean(file[i]);
        if (!file[i])
            return (NULL);
    }
    file = realloc(file, (sizeof(char *) * (i + 1)));
    file[i] = NULL;
    free(line);
    return (file);
}

char **load_file(char *file_name)
{
    FILE *ptr = NULL;
    char **file = NULL;

    ptr = fopen(file_name, "r");
    if (!ptr)
        return (NULL);
    file = fill_array_file(ptr);
    if (!file)
        return (NULL);
    fclose(ptr);
    return (file);
}