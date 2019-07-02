/*
** EPITECH PROJECT, 2018
** test_my_strncmp.c
** File description:
** No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test (my_strncmp, test_strncmp_true_n)
{
    int i = my_strncmp("foo", "foo", 2);

    cr_assert_eq(0, i);
}

Test (my_strcmp, test_strncmp_false)
{
    int i = my_strncmp("foo", "bar", 3);

    cr_assert_eq(1, i);
}

Test (my_strcmp, test_strncmp_len1_diff)
{
    int i = my_strncmp("foo", "ba", 2);

    cr_assert_eq(1, i);
}

Test (my_strcmp, test_strncmp_null)
{
    int i = my_strncmp(NULL, "ba", 2);

    cr_assert_eq(1, i);
}