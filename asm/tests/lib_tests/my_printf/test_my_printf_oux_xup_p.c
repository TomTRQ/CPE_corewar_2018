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

Test (my_printf, test_if_o_is_operational, .init = cr_redirect_stdout)
{
    my_printf("salut %s le monde, on est %o", "tout", 11);
    cr_assert_stdout_eq_str("salut tout le monde, on est 13");
}

Test (my_printf, test_if_u_is_operational, .init = cr_redirect_stdout)
{
    my_printf("salut %s le monde, on est %u", "tout", 11);
    cr_assert_stdout_eq_str("salut tout le monde, on est 11");
}

Test (my_printf, test_if_x_is_operational, .init = cr_redirect_stdout)
{
    my_printf("salut %s le monde, on est %x", "tout", 11);
    cr_assert_stdout_eq_str("salut tout le monde, on est b");
}

Test (my_printf, test_if_X_is_operational, .init = cr_redirect_stdout)
{
    my_printf("salut %s le monde, on est %X", "tout", 11);
    cr_assert_stdout_eq_str("salut tout le monde, on est B");
}

Test (my_printf, test_if_p_is_operational, .init = cr_redirect_stdout)
{
    my_printf("salut %s le monde, on est %p", "tout", 11);
    cr_assert_stdout_eq_str("salut tout le monde, on est 0xb");
}