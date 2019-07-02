/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** test_or
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <string.h>
#include "mylib.h"
#include "error.h"

Test(error_arg_or, error_arg_or_valid)
{
    char *cmd[] = {"or", "%%1", "r2", "r1", NULL};
    int type[] = {INSTRUCTION, DIRECT, REGISTER, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_or(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_or, error_arg_or_invalid_size)
{
    char *cmd[] = {"or", "%%1", "r1", "r1", "r1", NULL};
    int type[] = {INSTRUCTION, DIRECT, REGISTER, REGISTER, REGISTER};
    int got = 0;
    int expected = 84;

    got = error_arg_or(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_or, error_arg_or_invalid_param3)
{
    char *cmd[] = {"or", "%%1", "r1", "%%1", NULL};
    int type[] = {INSTRUCTION, DIRECT, REGISTER, DIRECT};
    int got = 0;
    int expected = 84;

    got = error_arg_or(cmd, type, 1);
    cr_assert_eq(got, expected);
}