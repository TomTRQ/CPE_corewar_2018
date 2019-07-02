/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** test_lfork
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <string.h>
#include "mylib.h"
#include "error.h"

Test(error_arg_lfork, error_arg_lfork_valid)
{
    char *cmd[] = {"lfork", "%%1", NULL};
    int type[] = {INSTRUCTION, DIRECT};
    int got = 0;
    int expected = 0;

    got = error_arg_lfork(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_lfork, error_arg_lfork_valid_label)
{
    char *cmd[] = {"lfork", "1", NULL};
    int type[] = {INSTRUCTION, LABEL_CALL_D};
    int got = 0;
    int expected = 0;

    got = error_arg_lfork(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_lfork, error_arg_lfork_invalid_size)
{
    char *cmd[] = {"lfork", "%%1", "%%1", NULL};
    int type[] = {INSTRUCTION, DIRECT, DIRECT};
    int got = 0;
    int expected = 84;

    got = error_arg_lfork(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_lfork, error_arg_lfork_invalid_param1_ind)
{
    char *cmd[] = {"lfork", "1", NULL};
    int type[] = {INSTRUCTION, INDIRECT};
    int got = 0;
    int expected = 84;

    got = error_arg_lfork(cmd, type, 1);
    cr_assert_eq(got, expected);
}