/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** test_sti
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <string.h>
#include "mylib.h"
#include "error.h"

Test(error_arg_sti, error_arg_sti_valid_param3_register)
{
    char *cmd[] = {"sti", "r1", "r2", "r3", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER, REGISTER};
    int got = 0;
    int expected = 0;

    got = error_arg_sti(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_sti, error_arg_sti_invalid_size)
{
    char *cmd[] = {"sti", "r1", "r2", "r3", "r3", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER, REGISTER, REGISTER};
    int got = 0;
    int expected = 84;

    got = error_arg_sti(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_sti, error_arg_param1_invalid)
{
    char *cmd[] = {"sti", "1", "r2", "r3", NULL};
    int type[] = {INSTRUCTION, INDIRECT, REGISTER, REGISTER};
    int got = 0;
    int expected = 84;

    got = error_arg_sti(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_sti, error_arg_param3_valid_label_call_d)
{
    char *cmd[] = {"sti", "r1", "r2", "%%:1", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER, LABEL_CALL_D};
    int got = 0;
    int expected = 0;

    got = error_arg_sti(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_sti, error_arg_param3_valid_direct)
{
    char *cmd[] = {"sti", "r1", "r2", "%%3", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER, DIRECT};
    int got = 0;
    int expected = 0;

    got = error_arg_sti(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_sti, error_arg_param3_invvalid_inddirect)
{
    char *cmd[] = {"sti", "r1", "r2", "3", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER, INDIRECT};
    int got = 0;
    int expected = 84;

    got = error_arg_sti(cmd, type, 1);
    cr_assert_eq(got, expected);
}