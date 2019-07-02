/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** test_lldi
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <string.h>
#include "mylib.h"
#include "error.h"

Test(error_arg_lldi, error_arg_lldi_valid_reg)
{
    char *cmd[] = {"lldi", "r1", "r2", "r2", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_lldi(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_lldi, error_arg_lldi_valid_label_call_d)
{
    char *cmd[] = {"lldi", "r1", "%%:label", "r2", NULL};
    int type[] = {INSTRUCTION, REGISTER, LABEL_CALL_D, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_lldi(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_lldi, error_arg_lldi_valid_dir)
{
    char *cmd[] = {"lldi", "r1", "%%1", "r2", NULL};
    int type[] = {INSTRUCTION, REGISTER, DIRECT, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_lldi(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_lldi, error_arg_lldi_invalid_size)
{
    char *cmd[] = {"lldi", "%%1", "r1", "%%1", "r2", NULL};
    int type[] = {INSTRUCTION, DIRECT, REGISTER, DIRECT, REGISTER};
    int got = 0;
    int expected = 84;

    got = error_arg_lldi(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_lldi, error_arg_lldi_invalid_param2_reg)
{
    char *cmd[] = {"lldi", "%%1", "1", "r2", NULL};
    int type[] = {INSTRUCTION, DIRECT, INDIRECT, REGISTER};
    int got = 0;
    int expected = 84;

    got = error_arg_lldi(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_lldi, error_arg_lldi_invalid_param3_reg)
{
    char *cmd[] = {"lldi", "%%1", "r1", "3", NULL};
    int type[] = {INSTRUCTION, DIRECT, REGISTER, INDIRECT};
    int got = 0;
    int expected = 84;

    got = error_arg_lldi(cmd, type, 1);
    cr_assert_eq(got, expected);
}