/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** test_aff
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <string.h>
#include "mylib.h"
#include "error.h"

Test(error_arg_aff, test_aff_valid)
{
    char *cmd[] = {"aff", "r1", NULL};
    int type[] = {INSTRUCTION, REGISTER};
    int got = 0;

    got = error_arg_aff(cmd, type, 1);
    cr_assert_eq(got, 0);
}

Test(error_arg_aff, test_aff_indirect)
{
    char *cmd[] = {"aff", "1", NULL};
    int type[] = {INSTRUCTION, INDIRECT};
    int got = 0;

    got = error_arg_aff(cmd, type, 1);
    cr_assert_eq(got, 84);
}

Test(error_arg_aff, test_aff_invalid_size)
{
    char *cmd[] = {"aff", "r1", "r2", NULL};
    int type[] = {INSTRUCTION, REGISTER, REGISTER};
    int got = 0;

    got = error_arg_aff(cmd, type, 1);
    cr_assert_eq(got, 84);
}