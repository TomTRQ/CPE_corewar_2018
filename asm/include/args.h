/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** args
*/

#ifndef ARGS_H_
#define ARGS_H_

#include <stdlib.h>
#include "op.h"
#include "error.h"

#define LIVE_ARGS (2)
#define LD_ARGS (3)
#define ST_ARGS (3)
#define ADD_ARGS (4)
#define SUB_ARGS (4)
#define AND_ARGS (4)
#define OR_ARGS (4)
#define XOR_ARGS (4)
#define ZJMP_ARGS (2)
#define LDI_ARGS (4)
#define STI_ARGS (4)
#define FORK_ARGS (2)
#define LLD_ARGS (3)
#define LLDI_ARGS (4)
#define LFORK_ARGS (2)
#define AFF_ARGS (2)

#define LIVE (op_tab[0].mnemonique)

typedef struct inst_list_s {
    char *name;
    int (*inst)(char **cmd, int *type, int idx);
} inst_list_t;

static const inst_list_t INST_LIST[] = {
        {"live", error_arg_live},
        {"ld", error_arg_ld},
        {"st", error_arg_st},
        {"add", error_arg_add},
        {"sub", error_arg_sub},
        {"and", error_arg_and},
        {"or", error_arg_or},
        {"xor", error_arg_or},
        {"zjmp", error_arg_zjmp},
        {"ldi", error_arg_ldi},
        {"sti", error_arg_sti},
        {"fork", error_arg_fork},
        {"lld", error_arg_lld},
        {"lldi", error_arg_lldi},
        {"lfork", error_arg_lfork},
        {"aff", error_arg_aff},
        {NULL, NULL}
};

#endif /* !ARGS_H_ */
