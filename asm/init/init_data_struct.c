/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** init_data_struct
*/

#include <stdlib.h>
#include "mylib.h"
#include "data.h"
#include "op.h"

data_t **init_data(char **file)
{
    data_t **data_arr = NULL;

    data_arr = create_data(file);
    if (!data_arr)
        return (NULL);
    data_arr = init_type(data_arr);
    data_arr = init_parameters_bytcode(data_arr);
    data_arr = init_data_instruction_bytcode(data_arr);
    data_arr = init_size(data_arr);
    return (data_arr);
}