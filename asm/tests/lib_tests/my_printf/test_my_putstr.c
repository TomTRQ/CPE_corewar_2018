/*
** EPITECH PROJECT, 2018
** test_my_putstr
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test (my_putstr, test_my_putstr, .init = cr_redirect_stdout)
{
    my_putstr("-23562");
    cr_assert_stdout_eq_str("-23562");
}

Test (my_putstr, test_my_putstr_char, .init = cr_redirect_stdout)
{
    my_putstr("2");
    cr_assert_stdout_eq_str("2");
}