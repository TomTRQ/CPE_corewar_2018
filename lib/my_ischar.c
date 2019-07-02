/*
** EPITECH PROJECT, 2019
** my_ischar
** File description:
** my_ischar
*/

int my_ischar(char str)
{
    if (str != ' ' && str != '\t' && str != '\0' && str != '\n')
        return (1);
    return (0);
}