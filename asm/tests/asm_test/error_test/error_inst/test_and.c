/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** test_and
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <string.h>
#include "mylib.h"
#include "error.h"

Test(error_arg_and, error_arg_and_valid)
{
    char *cmd[] = {"and", "r1", "r2", "r3", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_and(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_and, error_arg_and_invalid_size)
{
    char *cmd[] = {"and", "r1", "r2", "r3", "r4", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER, REGISTER, REGISTER};
    int got = 0;
    int expected = 84;

    got = error_arg_and(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_and, error_arg_and_invalid_param3)
{
    char *cmd[] = {"and", "r1", "r2", "3", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER, INDIRECT, REGISTER};
    int got = 0;
    int expected = 84;

    got = error_arg_and(cmd, type, 1);
    cr_assert_eq(got, expected);
}