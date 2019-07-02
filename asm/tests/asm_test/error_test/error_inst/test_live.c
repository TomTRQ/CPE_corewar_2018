/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** test_live
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include <stddef.h>
#include "error.h"

Test(error_arg_live, test_live_valid)
{
    char *cmd[] = {"live", "%%1", NULL};
    int type[] = {INSTRUCTION, DIRECT};
    int got = 0;

    got = error_arg_live(cmd, type, 1);
    cr_assert_eq(got, 0);
}

Test(error_arg_live, test_live_indirect)
{
    char *cmd[] = {"live", "1", NULL};
    int type[] = {INSTRUCTION, INDIRECT};
    int got = 0;

    got = error_arg_live(cmd, type, 1);
    cr_assert_eq(got, 84);
}

Test(error_arg_live, test_live_with_label)
{
    char *cmd[] = {"live:", "live", "%%1", NULL};
    int type[] = {LABEL_INIT, INSTRUCTION, LABEL_CALL_D};
    int got = 0;

    got = error_arg_live(cmd, type, 2);
    cr_assert_eq(got, 0);
}

Test(error_arg_live, test_live_invalid_size)
{
    char *cmd[] = {"live", "%%1", "r2", NULL};
    int type[] = {INSTRUCTION};
    int got = 0;

    got = error_arg_live(cmd, type, 1);
    cr_assert_eq(got, 84);
}