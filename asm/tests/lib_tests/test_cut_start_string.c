/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** test_cut_start_string
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test(cut_start_string, null_tab)
{
    char *tab = NULL;
    char *got = NULL;

    got = cut_start_string(tab, 1);
    cr_assert_null(got);
}

Test(cut_start_string, index_bigger_len)
{
    char *str = "Salut";
    char *got = NULL;

    got = cut_start_string(str, 12);
    cr_assert_null(got);
}

Test(cut_start_string, classic_test)
{
    char *str = "Salut";
    char *got = NULL;
    char *expected = "lut";

    got = cut_start_string(str, 2);
    cr_assert_str_eq(got, expected);
}