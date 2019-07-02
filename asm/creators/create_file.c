/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** create_file
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mylib.h"

char *remove_type_file(char *name)
{
    char *clean_name = NULL;
    char *cor_name = NULL;
    int i = my_strlen(name) - 1;
    int j = 0;

    if (!name)
        return (NULL);
    for (; name[i] != '.' && i > 0; i--);
    if (i == 0)
        i = my_strlen(name);
    clean_name = malloc(sizeof(char) * (i + 1));
    for (; j < i; j++)
        clean_name[j] = name[j];
    clean_name[j] = '\0';
    cor_name = my_strcat(clean_name, ".cor");
    free(clean_name);
    return (cor_name);
}

int create_file(char *name)
{
    char *new_name = NULL;
    int fd = 0;

    new_name = remove_type_file(name);
    fd = open(new_name, O_CREAT | O_WRONLY | O_TRUNC, 0755);
    free(new_name);
    return (fd);
}