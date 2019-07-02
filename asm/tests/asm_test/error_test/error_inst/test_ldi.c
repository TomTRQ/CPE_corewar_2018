/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** test_ldi
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <string.h>
#include "mylib.h"
#include "error.h"

Test(error_arg_ldi, error_arg_ldi_valid)
{
    char *cmd[] = {"ldi", "%%1", "%%1", "r1", NULL};
    int type[] = {INSTRUCTION, DIRECT, DIRECT, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_ldi(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_ldi, error_arg_ldi_valid_param2_label_d)
{
    char *cmd[] = {"ldi", "%%1", "%%:live", "r1", NULL};
    int type[] = {INSTRUCTION, DIRECT, LABEL_CALL_D, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_ldi(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_ldi, error_arg_ldi_valid_param2_reg)
{
    char *cmd[] = {"ldi", "%%1", "r1", "r1", NULL};
    int type[] = {INSTRUCTION, DIRECT, REGISTER, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_ldi(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_ldi, error_arg_ldi_invalid_size)
{
    char *cmd[] = {"ldi", "%%1", "r1", "r1", "r1", NULL};
    int type[] = {INSTRUCTION, DIRECT, REGISTER, REGISTER, REGISTER};
    int got = 0;
    int expected = 84;

    got = error_arg_ldi(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_ldi, error_arg_ldi_invalid_param2)
{
    char *cmd[] = {"ldi", "%%1", "1", "%%1", NULL};
    int type[] = {INSTRUCTION, DIRECT, INDIRECT, DIRECT};
    int got = 0;
    int expected = 84;

    got = error_arg_ldi(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_ldi, error_arg_ldi_invalid_param3)
{
    char *cmd[] = {"ldi", "%%1", "r1", "%%1", NULL};
    int type[] = {INSTRUCTION, DIRECT, REGISTER, DIRECT};
    int got = 0;
    int expected = 84;

    got = error_arg_ldi(cmd, type, 1);
    cr_assert_eq(got, expected);
}