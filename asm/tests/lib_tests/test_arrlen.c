/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** test_arrlen
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test(arrlen, null_arr)
{
    char **arr = NULL;

    cr_assert_eq(arrlen(arr), 0);
}

Test(arrlen, arr)
{
    char *arr[] = {
        "bonjour",
        "toto",
        NULL
    };

    cr_assert_eq(arrlen(arr), 2);
}