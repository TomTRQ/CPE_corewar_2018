/*
** EPITECH PROJECT, 2018
** test_space_cmp.c
** File description:
** No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test (space_cmp, test_space_cmp_true)
{
    char *str = "salut ";
    char *str2 = "saluter";
    int i = space_cmp(str, str2);

    cr_assert_eq(0, i);
}

Test (space_cmp, test_space_cmp_true2)
{
    char *str = "saluter";
    char *str2 = "salu ";
    int i = space_cmp(str, str2);

    cr_assert_eq(0, i);
}

Test (space_cmp, test_space_cmp_true3)
{
    char *str = "saluter";
    char *str2 = "salut";
    int i = space_cmp(str, str2);

    cr_assert_eq(0, i);
}

Test (space_cmp, test_space_cmp_true4)
{
    char *str = "salut";
    char *str2 = "saluter";
    int i = space_cmp(str, str2);

    cr_assert_eq(0, i);
}

Test (space_cmp, test_space_cmp_false)
{
    char *str = "salut";
    char *str2 = "salur";
    int i = space_cmp(str, str2);

    cr_assert_eq(1, i);
}