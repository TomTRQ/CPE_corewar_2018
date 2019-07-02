/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** test_lld
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <string.h>
#include "mylib.h"
#include "error.h"

Test(error_arg_lld, error_arg_lld_valid)
{
    char *cmd[] = {"lld", "%%1", "r2", NULL};
    int type[] = {INSTRUCTION, DIRECT, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_lld(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_lld, error_arg_lld_invalid_size)
{
    char *cmd[] = {"lld", "%%1", "r1", "%%1", NULL};
    int type[] = {INSTRUCTION, DIRECT, REGISTER, DIRECT};
    int got = 0;
    int expected = 84;

    got = error_arg_lld(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_lld, error_arg_lld_invalid_param2)
{
    char *cmd[] = {"lld", "%%1", "1", NULL};
    int type[] = {INSTRUCTION, DIRECT, INDIRECT};
    int got = 0;
    int expected = 84;

    got = error_arg_lld(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_lld, error_arg_lld_valid_param1_indirect)
{
    char *cmd[] = {"lld", "1", "r1", NULL};
    int type[] = {INSTRUCTION, INDIRECT, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_lld(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_lld, error_arg_lld_valid_param1_label_call_indirect)
{
    char *cmd[] = {"lld", ":1", "r1", NULL};
    int type[] = {INSTRUCTION, LABEL_CALL_I, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_lld(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_lld, error_arg_lld_valid_param1_label_call_direct)
{
    char *cmd[] = {"lld", "%%:1", "r1", NULL};
    int type[] = {INSTRUCTION, LABEL_CALL_D, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_lld(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_lld, error_arg_lld_invalid_param1)
{
    char *cmd[] = {"lld", "r1", "r1", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER};
    int got = 0;
    int expected = 84;

    got = error_arg_lld(cmd, type, 1);
    cr_assert_eq(got, expected);
}