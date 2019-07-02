/*
** EPITECH PROJECT, 2018
** test_my_strdup.c
** File description:
** No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test (my_strdup, test_my_strdup_ok)
{
    char *str = "salut";
    char *dup = my_strdup(str);

    cr_assert_str_eq(str, dup);
    free(dup);
}

Test (my_strdup, test_my_strdup_fail)
{
    char *str = NULL;
    char *dup = my_strdup(str);

    cr_assert_null(dup);
    free(dup);
}

Test (my_strdup, test_my_strdup_backslash_n)
{
    char *str = "salut\n";
    char *dup = my_strdup(str);

    cr_assert_str_eq("salut", dup);
    free(dup);
}