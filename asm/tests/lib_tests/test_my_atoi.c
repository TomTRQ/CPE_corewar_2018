/*
** EPITECH PROJECT, 2018
** test_my_atoi.c
** File description:
** No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test (my_atoi, test_my_atoi_bad_input)
{
    char *a = "abc";
    int i = my_atoi(a);

    cr_assert_eq(-1, i);
}

Test (my_atoi, test_my_atoi_null)
{
    char *str = NULL;
    int i = my_atoi(str);

    cr_assert_eq(-1, i);
}

Test (my_atoi, test_my_atoi_true)
{
    char *str = "462";
    int i = my_atoi(str);

    cr_assert_eq(462, i);
}