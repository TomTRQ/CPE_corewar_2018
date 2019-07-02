/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** test_ld
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <string.h>
#include "mylib.h"
#include "error.h"

Test(error_arg_ld, test_ld_valid1)
{
    char *cmd[] = {"ld", "1", "r2", NULL};
    int type[] = {INSTRUCTION, LABEL_CALL_D, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_ld(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_ld, test_ld_valid2)
{
    char *cmd[] = {"ld", "1", "r2", NULL};
    int type[] = {INSTRUCTION, LABEL_CALL_I, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_ld(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_ld, test_ld_valid4)
{
    char *cmd[] = {"ld", "%%1", "r2", NULL};
    int type[] = {INSTRUCTION, INDIRECT, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_ld(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_ld, test_ld_invalid_size)
{
    char *cmd[] = {"ld", "1", "r2", "r3", NULL};
    int type[] = {INSTRUCTION, INDIRECT, REGISTER, REGISTER};
    int got = 0;
    int expected = 84;

    got = error_arg_ld(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_ld, test_ld_invalid_param1)
{
    char *cmd[] = {"ld", "r1", "r2", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER};
    int got = 0;
    int expected = 84;

    got = error_arg_ld(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_ld, test_ld_invalid_param3)
{
    char *cmd[] = {"ld", "%%1", "1", NULL};
    int type[] = {INSTRUCTION, DIRECT, INDIRECT};
    int got = 0;
    int expected = 84;

    got = error_arg_ld(cmd, type, 1);
    cr_assert_eq(got, expected);
}