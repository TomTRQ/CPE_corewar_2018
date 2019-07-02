/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** calcul_label_nb
*/

#include "data.h"

int calcul_label_nb(data_t **data_arr)
{
    int nb_label = 0;

    for (int i = 0; data_arr[i]; i++)
        if (data_arr[i]->type[0] == LABEL_INIT)
            nb_label++;
    return (nb_label);
}