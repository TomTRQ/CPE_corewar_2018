/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** error
*/

#ifndef ERROR_H_
#define ERROR_H_

#include "data.h"

int error_header(data_t **data_arr);
int error_handling(data_t **data_arr);
int error_null_header(data_t **data_arr, int type);
int error_invalid_char_header(data_t **data_arr, int type);
int error_label(data_t **data_arr);
int error_undeclared_label(data_t **data_arr, char **label);
int error_direct_value(data_t **data_arr);
int error_missing_value(data_t **data_arr, int type);
int error_multiple_def_label(char **label);
int error_unknow_command(data_t *data);
int error_invalid_occur_parameter(char **cmd, int *type, int arg_size);

int error_arg_live(char **cmd, int *type, int idx);
int error_arg_ld(char **cmd, int *type, int idx);
int error_arg_st(char **cmd, int *type, int idx);
int error_arg_add(char **cmd, int *type, int idx);
int error_arg_sub(char **cmd, int *type, int idx);
int error_arg_and(char **cmd, int *type, int idx);
int error_arg_or(char **cmd, int *type, int idx);
int error_arg_xor(char **cmd, int *type, int idx);
int error_arg_zjmp(char **cmd, int *type, int idx);
int error_arg_ldi(char **cmd, int *type, int idx);
int error_arg_sti(char **cmd, int *type, int idx);
int error_arg_fork(char **cmd, int *type, int idx);
int error_arg_lld(char **cmd, int *type, int idx);
int error_arg_lldi(char **cmd, int *type, int idx);
int error_arg_lfork(char **cmd, int *type, int idx);
int error_arg_aff(char **cmd, int *type, int idx);

#endif /* !ERROR_H_ */

