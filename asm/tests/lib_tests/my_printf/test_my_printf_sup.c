/*
** EPITECH PROJECT, 2018
** test_my_printf2
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylib.h"
#include <string.h>
#include <stddef.h>

Test (my_printf, test_if_S_is_operational, .init = cr_redirect_stdout)
{
    char str[] = "toto";
    str[1] = 11;
    my_printf("salut %s le monde, on est %S", "tout", str);
    cr_assert_stdout_eq_str("salut tout le monde, on est t\\013to");
}

Test (my_printf, test_if_S2_is_operational, .init = cr_redirect_stdout)
{
    char str[] = "toto";
    str[1] = 7;
    my_printf("salut %s le monde, on est %S", "tout", str);
    cr_assert_stdout_eq_str("salut tout le monde, on est t\\007to");
}

Test (my_printf, test_if_S3_is_operational, .init = cr_redirect_stdout)
{
    char str[] = "toto";
    str[1] = 127;
    my_printf("salut %s le monde, on est %S", "tout", str);
    cr_assert_stdout_eq_str("salut tout le monde, on est t\\177to");
}

Test (my_printf, test_if_neg_is_operational, .init = cr_redirect_stdout)
{
    my_printf("salut %s le monde, on est %d", "tout", -53);
    cr_assert_stdout_eq_str("salut tout le monde, on est -53");
}

Test (my_printf, test_if_i_is_operational, .init = cr_redirect_stdout)
{
    my_printf("salut %s le monde, on est %i", "tout", -53);
    cr_assert_stdout_eq_str("salut tout le monde, on est -53");
}