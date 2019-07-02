/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** test_binary_to_decimal
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test(binary_to_decimal, null_tab)
{
    char *tab = NULL;
    int expected = 0;
    int got = binary_to_decimal(tab);

    cr_assert_eq(got, expected);
}

Test(binary_to_decimal, arr)
{
    char *tab = "10101000";
    int expected = 168;
    int got = binary_to_decimal(tab);

    cr_assert_eq(got, expected);
}