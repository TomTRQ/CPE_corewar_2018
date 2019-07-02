/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** test_char_to_str
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test(char_to_str, test_char_to_str_ok)
{
    char *str = char_to_str('a');

    cr_assert_str_eq(str, "a");
    free(str);
}