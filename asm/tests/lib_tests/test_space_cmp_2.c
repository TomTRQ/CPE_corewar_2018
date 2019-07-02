/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** test_space_cmp_2
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test (space_cmp, test_space_cmp_null)
{
    char *str = NULL;
    char *str2 = "salur";
    int i = space_cmp(str, str2);

    cr_assert_eq(1, i);
}

Test (space_cmp, test_space_cmp_null2)
{
    char *str = "salut";
    char *str2 = NULL;
    int i = space_cmp(str, str2);

    cr_assert_eq(1, i);
}