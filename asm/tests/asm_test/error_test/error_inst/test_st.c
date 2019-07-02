/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** test_st
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <string.h>
#include "mylib.h"
#include "error.h"

Test(error_arg_st, test_st_valid_reg)
{
    char *cmd[] = {"st", "r1", "r1", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER};
    int got = 0;

    got = error_arg_st(cmd, type, 1);
    cr_assert_eq(got, 0);
}

Test(error_arg_st, test_st_valid_ind)
{
    char *cmd[] = {"st", "r1", "1", NULL};
    int type[] = {INSTRUCTION, REGISTER, INDIRECT};
    int got = 0;

    got = error_arg_st(cmd, type, 1);
    cr_assert_eq(got, 0);
}

Test(error_arg_st, test_st_valid_label_ind)
{
    char *cmd[] = {"st", "r1", ":live", NULL};
    int type[] = {INSTRUCTION, REGISTER, LABEL_CALL_I};
    int got = 0;

    got = error_arg_st(cmd, type, 1);
    cr_assert_eq(got, 0);
}

Test(error_arg_st, test_st_invalid_param1)
{
    char *cmd[] = {"st", "1", "1", NULL};
    int type[] = {INSTRUCTION, INDIRECT, INDIRECT};
    int got = 0;

    got = error_arg_st(cmd, type, 1);
    cr_assert_eq(got, 84);
}

Test(error_arg_st, test_st_invalid_param2)
{
    char *cmd[] = {"st", "r1", "%%1", NULL};
    int type[] = {INSTRUCTION, REGISTER, DIRECT};
    int got = 0;

    got = error_arg_st(cmd, type, 1);
    cr_assert_eq(got, 84);
}

Test(error_arg_st, test_st_invalid_size)
{
    char *cmd[] = {"st", "r1", "r2", "r2", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER, REGISTER};
    int got = 0;

    got = error_arg_st(cmd, type, 1);
    cr_assert_eq(got, 84);
}