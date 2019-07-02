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

Test (my_put_nbr_base, test_my_put_nbr_base_HEXA, .init = cr_redirect_stdout)
{
    my_put_nbr_base(10, "0123456789ABCDEF");
    cr_assert_stdout_eq_str("A");
}

Test (my_put_nbr_base, test_my_put_nbr_base_deci, .init = cr_redirect_stdout)
{
    my_put_nbr_base(8, "0123456789");
    cr_assert_stdout_eq_str("8");
}

Test (my_put_nbr_base, test_my_put_nbr_base_octal, .init = cr_redirect_stdout)
{
    my_put_nbr_base(53, "01234567");
    cr_assert_stdout_eq_str("65");
}

Test (my_put_nbr_base, test_my_put_nbr_base_bi, .init = cr_redirect_stdout)
{
    my_put_nbr_base(2, "01");
    cr_assert_stdout_eq_str("10");
}

Test (my_put_nbr, test_my_put_nbr_pos, .init = cr_redirect_stdout)
{
    my_put_nbr(23562);
    cr_assert_stdout_eq_str("23562");
}