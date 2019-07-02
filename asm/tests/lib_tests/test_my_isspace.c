/*
** EPITECH PROJECT, 2018
** test_my_isspace.c
** File description:
** No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test (my_isspace, test_my_isspace_true)
{
    char c = ' ';
    int i = 0;

    i = my_isspace(c);

    cr_assert_eq(i, 1);
}

Test (my_isspace, test_my_isspace_false)
{
    char c = 'a';
    int expected = 0;
    int got = 0;

    got = my_isspace(c);
    cr_assert_eq(got, expected);
}