/*
** EPITECH PROJECT, 2018
** test_my_printf.c
** File description:
** test my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test (my_printf, test_0_is_functionnal, .init = cr_redirect_stdout)
{
    my_printf("%0     s", "salut");
    cr_assert_stdout_eq_str("salut");
}

Test (my_printf, test_plus_is_functionnal_i, .init = cr_redirect_stdout)
{
    my_printf("%+i", 1000);
    cr_assert_stdout_eq_str("+1000");
}

Test (my_printf, test_plus_is_functionnal_i_d, .init = cr_redirect_stdout)
{
    my_printf("%+s", "salut");
    cr_assert_stdout_eq_str("salut");
}