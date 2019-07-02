/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** test_zjmp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <string.h>
#include "mylib.h"
#include "error.h"

Test(error_arg_zjmp, error_arg_zjmp_valid)
{
    char *cmd[] = {"zjmp", "%%1", NULL};
    int type[] = {INSTRUCTION, DIRECT};
    int got = 0;
    int expected = 0;

    got = error_arg_zjmp(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_zjmp, error_arg_zjmp_valid_label)
{
    char *cmd[] = {"zjmp", "1", NULL};
    int type[] = {INSTRUCTION, LABEL_CALL_D};
    int got = 0;
    int expected = 0;

    got = error_arg_zjmp(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_zjmp, error_arg_zjmp_invalid_size)
{
    char *cmd[] = {"zjmp", "%%1", "%%1", NULL};
    int type[] = {INSTRUCTION, DIRECT, DIRECT};
    int got = 0;
    int expected = 84;

    got = error_arg_zjmp(cmd, type, 1);
    cr_assert_eq(got, expected);
}

Test(error_arg_zjmp, error_arg_zjmp_invalid_param1_ind)
{
    char *cmd[] = {"zjmp", "1", NULL};
    int type[] = {INSTRUCTION, INDIRECT};
    int got = 0;
    int expected = 84;

    got = error_arg_zjmp(cmd, type, 1);
    cr_assert_eq(got, expected);
}