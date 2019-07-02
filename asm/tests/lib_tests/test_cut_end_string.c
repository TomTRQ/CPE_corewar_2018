/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** test_cut_end_string
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test(cut_end_string, test_null)
{
    char *str = NULL;
    char *got = NULL;

    got = cut_end_string(str, 12);
    cr_assert_null(got);
}

Test(cut_end_string, too_big_idx)
{
    char *str = "Salut";
    char *got = NULL;

    got = cut_end_string(str, 24);
    cr_assert_null(got);
}

Test(cut_end_string, good_test)
{
    char *str = "Salut";
    char *got = NULL;
    char *expected = "Sal";

    got = cut_end_string(str, 2);
    cr_assert_str_eq(got, expected);
}