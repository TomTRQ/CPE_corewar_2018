/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** test_add
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <string.h>
#include "mylib.h"
#include "error.h"

Test(error_arg_add, error_arg_add_valid)
{
    char *cmd[] = {"add", "r1", "r2", "r3", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_add(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_add, error_arg_add_invalid_size)
{
    char *cmd[] = {"add", "r1", "r2", "r3", "r3", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER, REGISTER, REGISTER};
    int got = 0;
    int expected = 84;

    got = error_arg_add(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_add, error_arg_param1_invalid)
{
    char *cmd[] = {"add", "1", "r2", "r3", NULL};
    int type[] = {INSTRUCTION, INDIRECT, REGISTER, REGISTER};
    int got = 0;
    int expected = 84;

    got = error_arg_add(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_add, error_arg_param2_invalid)
{
    char *cmd[] = {"add", "r1", "2", "r3", NULL};
    int type[] = {INSTRUCTION, REGISTER, INDIRECT, REGISTER};
    int got = 0;
    int expected = 84;

    got = error_arg_add(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_add, error_arg_param3_invalid)
{
    char *cmd[] = {"add", "r1", "r2", "3", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER, INDIRECT};
    int got = 0;
    int expected = 84;

    got = error_arg_add(cmd, type, 1);
    cr_assert_eq(got, expected);
}