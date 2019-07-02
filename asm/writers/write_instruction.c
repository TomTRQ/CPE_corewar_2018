/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** write_instructions
*/

#include <stdlib.h>
#include <unistd.h>
#include "mylib.h"
#include "data.h"
#include "op.h"

int find_command_array(char *cmd)
{
    for (int i = 0; op_tab[i].mnemonique; i++)
        if (my_strcmp(cmd, op_tab[i].mnemonique) == 0)
            return (i + 1);
    return (0);
}

int write_instruction_code(char *cmd, int fd)
{
    int inst = 0;

    inst = find_command_array(cmd);
    write(fd, &inst, 1);
    return (0);
}