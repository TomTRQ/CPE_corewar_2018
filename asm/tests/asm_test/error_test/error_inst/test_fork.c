/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** test_fork
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <string.h>
#include "mylib.h"
#include "error.h"

Test(error_arg_fork, error_arg_fork_valid)
{
    char *cmd[] = {"fork", "%%1", NULL};
    int type[] = {INSTRUCTION, DIRECT};
    int got = 0;
    int expected = 0;

    got = error_arg_fork(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_fork, error_arg_fork_valid_label)
{
    char *cmd[] = {"fork", "1", NULL};
    int type[] = {INSTRUCTION, LABEL_CALL_D};
    int got = 0;
    int expected = 0;

    got = error_arg_fork(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_fork, error_arg_fork_invalid_size)
{
    char *cmd[] = {"fork", "%%1", "%%1", NULL};
    int type[] = {INSTRUCTION, DIRECT, DIRECT};
    int got = 0;
    int expected = 84;

    got = error_arg_fork(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_fork, error_arg_fork_invalid_param1_ind)
{
    char *cmd[] = {"fork", "1", NULL};
    int type[] = {INSTRUCTION, INDIRECT};
    int got = 0;
    int expected = 84;

    got = error_arg_fork(cmd, type, 1);
    cr_assert_eq(got, expected);
}