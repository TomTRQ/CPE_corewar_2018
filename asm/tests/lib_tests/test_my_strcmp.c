/*
** EPITECH PROJECT, 2018
** test_my_strcmp.c
** File description:
** No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test (my_strcmp, test_strcmp_true)
{
    int i = my_strcmp("foo", "foo");

    cr_assert_eq(0, i);
}

Test (my_strcmp, test_strcmp_false)
{
    int i = my_strcmp("foo", "bar");

    cr_assert_eq(1, i);
}

Test (my_strcmp, test_strcmp_len1_diff)
{
    int i = my_strcmp("foo", "ba");

    cr_assert_eq(1, i);
}

Test (my_strcmp, test_strcmp_len2_diff)
{
    int i = my_strcmp("fo", "bar");

    cr_assert_eq(1, i);
}