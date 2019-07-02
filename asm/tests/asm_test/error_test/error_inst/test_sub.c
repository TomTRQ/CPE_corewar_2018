/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** test_sub
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <string.h>
#include "mylib.h"
#include "error.h"

Test(error_arg_sub, test_sub_valid)
{
    char *cmd[] = {"sub", "r1", "r2", "r3", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_sub(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_sub, test_sub_invalid_param1)
{
    char *cmd[] = {"sub", "1", "r2", "r3", NULL};
    int type[] = {INSTRUCTION, INDIRECT, REGISTER, REGISTER};
    int got = 0;
    int expected = 84;

    got = error_arg_sub(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_sub, test_sub_invalid_param2)
{
    char *cmd[] = {"sub", "r1", "2", "r3", NULL};
    int type[] = {INSTRUCTION, REGISTER, INDIRECT, REGISTER};
    int got = 0;
    int expected = 84;

    got = error_arg_sub(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_sub, test_sub_invalid_param3)
{
    char *cmd[] = {"sub", "r1", "r2", "3", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER, INDIRECT};
    int got = 0;
    int expected = 84;

    got = error_arg_sub(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_sub, test_sub_invalid_size)
{
    char *cmd[] = {"sub", "r1", "r2", "r3", "1", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER, REGISTER, INDIRECT};
    int got = 0;
    int expected = 84;

    got = error_arg_sub(cmd, type, 1);
    cr_assert_eq(got, expected);
}