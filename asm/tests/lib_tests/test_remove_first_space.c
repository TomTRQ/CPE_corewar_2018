/*
** EPITECH PROJECT, 2018
** test_remove_first_space.c
** File description:
** No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test (remove_first_space, test_remove_first_space_null)
{
    char *str = NULL;
    char *str2 = remove_first_space(str);

    cr_assert_null(str2);
}

Test (remove_first_space, test_remove_first_space_true)
{
    char *str = "            salut";
    char *str2 = remove_first_space(str);

    cr_assert_str_eq(str2, "salut");
}

Test (remove_first_space, test_remove_first_space_without_sapce)
{
    char *str = "salut";
    char *str2 = remove_first_space(str);

    cr_assert_str_eq(str2, "salut");
}