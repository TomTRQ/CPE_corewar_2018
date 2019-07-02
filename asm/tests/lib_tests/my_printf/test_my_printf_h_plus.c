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

Test (my_printf, test_space_no_diff, .init = cr_redirect_stdout)
{
    my_printf("% d %       s", 1000, "merci");
    cr_assert_stdout_eq_str("1000 merci");
}

Test (my_printf, test_plus_is_functionnal, .init = cr_redirect_stdout)
{
    my_printf("%+d", 1000);
    cr_assert_stdout_eq_str("+1000");
}

Test (my_printf, test_o_is_functionnal, .init = cr_redirect_stdout)
{
    my_printf("%#o", 7);
    cr_assert_stdout_eq_str("07");
}

Test (my_printf, test_x_is_functionnal, .init = cr_redirect_stdout)
{
    my_printf("%#x", 6);
    cr_assert_stdout_eq_str("0x6");
}

Test (my_printf, test_X_is_functionnal, .init = cr_redirect_stdout)
{
    my_printf("%#X", 6);
    cr_assert_stdout_eq_str("0X6");
}
