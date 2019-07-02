/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include <stdio.h>
#include "get_file.h"
#include "mylib.h"
#include "data.h"
#include "op.h"
#include "error.h"

int main(int ac, char **av)
{
    char **file = NULL;
    data_t **data_arr = NULL;
    int fd = 0;

    if (ac != 2)
        return (84);
    file = load_file(av[1]);
    if (!file)
        return (84);
    data_arr = init_data(file);
    if (error_handling(data_arr) == 84) {
        free_data_arr(data_arr);
        return (84);
    }
    fd = create_file(av[1]);
    write_file(data_arr, fd);
    free_data_arr(data_arr);
    return (0);
}