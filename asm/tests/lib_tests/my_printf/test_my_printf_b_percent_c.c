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

Test (my_printf, test_if_b_is_operational, .init = cr_redirect_stdout)
{
    my_printf("salut %s le monde, on est %b", "tout", 2);
    cr_assert_stdout_eq_str("salut tout le monde, on est 10");
}

Test (my_printf, test_if_percent_is_operational, .init = cr_redirect_stdout)
{
    my_printf("salut %s le monde, on est %%", "tout");
    cr_assert_stdout_eq_str("salut tout le monde, on est %");
}

Test (my_printf, test_without_percent, .init = cr_redirect_stdout)
{
    my_printf("salut tout le monde");
    cr_assert_stdout_eq_str("salut tout le monde");
}

Test (my_printf, test_if_char_is_operational, .init = cr_redirect_stdout)
{
    my_printf("salut tout le %c", 'X');
    cr_assert_stdout_eq_str("salut tout le X");
}

Test (my_put_nbr_base, test_my_put_nbr_base_hexa, .init = cr_redirect_stdout)
{
    my_put_nbr_base(13, "0123456789abcdef");
    cr_assert_stdout_eq_str("d");
}