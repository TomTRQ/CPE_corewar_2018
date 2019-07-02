/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** All .h functions
*/

#ifndef _MY_H_
#define _MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int handle_cond(char *format, int *i, va_list ap);
int handle_flags_base_for_s_up(char *format, int *i, va_list ap);
int handle_zero(char *format, int *i);
int convert_endian(int nb);
int handle_space(char *format, int *i);
int my_isspace(char str);
char *my_revstr(char *str);
int my_strcmp(char *s1, char *s2);
int my_ischar(char str);
int my_printf(char *format, ...);
void my_putchar(char c);
int cond_for_s_up(char *str, int const *j);
int my_atoi(char const *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
int binary_to_decimal(char const *tab);
int my_put_nbr(int nb);
char *my_strdup(char *str);
int my_strncmp(char *s1, char *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *s1, char *s2);
char *my_strrevcat(char *dest, char *src, char *right, int a);
char *my_strcpy(char *dest, char const *src);
void handle_flags(char *format, int *i, va_list ap);
int handle_flags_base(char *format, int *i, va_list ap);
int my_put_nbr_base(int nb, char *base);
int count_occur(char *str, char c);
char *cut_str(char *str);
void free_arr(char **arr);
char *parse_getline(char *buff);
int space_cmp(char *s1, char *s2);
int dec_to_hex(int nb, char *base);
int binary_to_decimal(char const *tab);
int arrlen(char **arr);
char *cut_start_string(char *str, int i);
char *char_to_str(char c);
char *cut_end_string(char *str, int idx);
#endif
