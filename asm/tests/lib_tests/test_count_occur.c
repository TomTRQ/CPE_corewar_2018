/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** test_count_occur
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test(count_occur, test_null)
{
    char *str = NULL;
    int got = 0;
    int expected = 0;

    got = count_occur(str, 'c');
    cr_assert_eq(expected, got);
}

Test(count_occur, classic_test_true)
{
    char *str = "Toto";
    int got = 0;
    int expected = 2;

    got = count_occur(str, 'o');
    cr_assert_eq(expected, got);
}

Test(count_occur, classic_test_false)
{
    char *str = "Toto";
    int got = 0;
    int expected = 0;

    got = count_occur(str, 'a');
    cr_assert_eq(expected, got);
}