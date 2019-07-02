/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** test_my_isschar
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test(my_ischar, test_my_isschar_space)
{
    int i = my_ischar(' ');

    cr_assert_eq(0, i);
}

Test(my_ischar, test_my_isschar_tab)
{
    int i = my_ischar('\t');

    cr_assert_eq(0, i);
}

Test(my_ischar, test_my_isschar_end)
{
    int i = my_ischar('\0');

    cr_assert_eq(0, i);
}

Test(my_ischar, test_my_isschar_enter)
{
    int i = my_ischar('\n');

    cr_assert_eq(0, i);
}

Test(my_ischar, test_my_isschar_good)
{
    int i = my_ischar('a');

    cr_assert_eq(1, i);
}