/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** init_label
*/

#include <stdlib.h>
#include "data.h"
#include "mylib.h"

char **init_label_array(data_t **data_arr)
{
    int nb_label = calcul_label_nb(data_arr);
    char **label = NULL;
    int idx = 0;

    label = malloc(sizeof(char *) * (nb_label + 1));
    if (!label)
        return (NULL);
    for (int i = 0; data_arr[i]; i++) {
        if (data_arr[i]->type[0] == LABEL_INIT) {
            label[idx] = my_strdup(data_arr[i]->cmd[0]);
            idx++;
        }
    }
    label[idx] = NULL;
    return (label);
}