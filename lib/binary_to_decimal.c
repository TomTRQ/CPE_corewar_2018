/*
** EPITECH PROJECT, 2018
** binary_to_decimal.c
** File description:
** No description
*/

int binary_to_decimal(char const *tab)
{
    int result = 0;
    int power = 1;

    if (!tab)
        return (0);
    for (int i = 7; i >= 0; i--) {
        if (tab[i] == '1')
            result += power;
        power *= 2;
    }
    return (result);
}