/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** test_my_revstr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test(my_revstr, test_my_revstr_null)
{
    char *str = my_revstr(NULL);

    cr_assert_null(str);
}

Test(my_revstr, test_my_revstr_ok)
{
    char *str = my_revstr("salut");

    cr_assert_str_eq(str, "tulas");
    free(str);
}