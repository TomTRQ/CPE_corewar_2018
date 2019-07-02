/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** init_instructions
*/

#include <stdlib.h>
#include "mylib.h"
#include "op.h"
#include "data.h"

int get_opt_tab_size(void)
{
    int size = 0;

    for (; op_tab[size].mnemonique != NULL; size++);
    return (size);
}

char **init_instruction_name(void)
{
    char **instructions = NULL;
    int size = get_opt_tab_size();
    int i = 0;

    instructions = malloc(sizeof(char *) * (size + 3));
    for (; i < size; i++)
        instructions[i] = op_tab[i].mnemonique;
    instructions[i] = NAME_CMD_STRING;
    i++;
    instructions[i] = COMMENT_CMD_STRING;
    i++;
    instructions[i] = NULL;
    return (instructions);
}

int *init_instruction_bytcode(void)
{
    int i = get_opt_tab_size();
    int *bytcode = 0;

    bytcode = malloc(sizeof(int) * (i + 2));
    for (int k = 0; k < i + 2; k++)
        bytcode[k] = 0;
    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (my_strcmp(op_tab[i].mnemonique, LIVE) == 0 ||
            my_strcmp(op_tab[i].mnemonique, ZJMP) == 0 ||
            my_strcmp(op_tab[i].mnemonique, FORK) == 0 ||
            my_strcmp(op_tab[i].mnemonique, LFORK) == 0)
            bytcode[i] = 1;
        else if (my_strcmp(op_tab[i].mnemonique, NAME_CMD_STRING) == 0 ||
                my_strcmp(op_tab[i].mnemonique, COMMENT_CMD_STRING) == 0)
            bytcode[i] = 0;
        else
            bytcode[i] = 2;
    }
    return (bytcode);
}