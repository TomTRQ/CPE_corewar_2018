/*
** EPITECH PROJECT, 2018
** test_my_strcat.c
** File description:
** No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test (my_strcat, test_my_strcat)
{
    char *str = "sa";
    char *str2 = "lut";
    char *cat = my_strcat(str, str2);

    cr_assert_str_eq(cat, "salut");
}

Test (my_strcat, test_my_strcat_null)
{
    char *str = NULL;
    char *str2 = "test";
    char *cat = my_strcat(str, str2);

    cr_assert_null(cat);
}

Test (my_strcat, test_my_strcat_null2)
{
    char *str = "test";
    char *str2 = NULL;
    char *cat = my_strcat(str, str2);

    cr_assert_null(cat);
}

Test (my_strcat, test_my_strcat_backslash_n)
{
    char *str = "sa";
    char *str2 = "lut\n";
    char *cat = my_strcat(str, str2);

    cr_assert_str_eq(cat, "salut");
}