##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for CPE_corewar_2018
##

NAME			=		asm

CC				=		gcc

RM				=		rm -f

SRCMAIN			=		main.c

SRC             =		op.c 															\
						check_special_cmd.c												\
						loaders/load_file.c												\
						init/init_data_struct.c											\
						init/init_instruction/init_data_instruction_bytcode.c			\
						init/init_instruction/init_instructions.c						\
						init/init_parameters/init_parameters_bytcode.c					\
						init/init_size/init_size.c										\
						init/init_type/init_type.c										\
						init/init_label.c												\
						creators/create_data.c											\
						creators/count_size.c											\
						creators/create_file.c											\
						calculators/calcul_description.c								\
						calculators/calcul_header_size.c								\
						calculators/calcul_label_range.c								\
						calculators/calcul_len.c										\
						calculators/calcul_label_nb.c									\
						writers/write_file.c											\
						writers/write_command.c											\
						writers/write_instruction.c										\
						writers/write_header.c											\
						writers/write_param_description.c								\
						writers/write_param_value.c										\
						errors/error_header/error_header.c								\
						errors/error_header/error_null_header.c							\
						errors/error_header/error_invalid_char_header.c					\
						errors/error_handling.c											\
						errors/error_label/error_label.c								\
						errors/error_label/error_undeclared_label.c						\
						errors/error_label/error_multiple_def_label.c					\
						errors/error_missing_value.c									\
						errors/error_unknow_command.c									\
						errors/error_args/error_arg_add.c								\
						errors/error_args/error_arg_aff.c								\
						errors/error_args/error_arg_and.c								\
						errors/error_args/error_arg_fork.c								\
						errors/error_args/error_arg_ld.c								\
						errors/error_args/error_arg_ldi.c								\
						errors/error_args/error_arg_lfork.c								\
						errors/error_args/error_arg_live.c								\
						errors/error_args/error_arg_lld.c								\
						errors/error_args/error_arg_lldi.c								\
						errors/error_args/error_arg_or.c								\
						errors/error_args/error_arg_st.c								\
						errors/error_args/error_arg_sti.c								\
						errors/error_args/error_arg_sub.c								\
						errors/error_args/error_arg_xor.c								\
						errors/error_args/error_arg_zjmp.c								\
						errors/error_args/error_invalid_occur_parameter.c				\
						cleaner/free_data_arr.c											\

LIBSRC			=		../lib/my_putstr.c                  	\
						../lib/my_putchar.c						\
						../lib/my_printf/my_printf.c			\
						../lib/my_printf/my_printf2.c			\
						../lib/my_put_nbr_base.c				\
						../lib/my_put_nbr.c						\
						../lib/my_strlen.c						\
						../lib/my_ischar.c						\
						../lib/my_isspace.c						\
						../lib/binary_to_decimal.c				\
						../lib/my_atoi.c						\
						../lib/my_strdup.c						\
						../lib/my_strcmp.c						\
						../lib/my_strncmp.c						\
						../lib/my_revstr.c						\
						../lib/my_strcat.c						\
						../lib/count_occur.c					\
						../lib/cut_str.c 						\
						../lib/cut_start_string.c				\
						../lib/free_arr.c						\
						../lib/parse_getline.c					\
						../lib/space_cmp.c						\
						../lib/arrlen.c							\
						../lib/char_to_str.c					\
						../lib/cut_end_string.c					\

TEST 			=		tests/lib_tests/my_printf/test_my_printf_0_plus.c						\
						tests/lib_tests/my_printf/test_my_printf_b_percent_c.c					\
						tests/lib_tests/my_printf/test_my_printf_oux_xup_p.c					\
						tests/lib_tests/my_printf/test_my_printf_base.c							\
						tests/lib_tests/my_printf/test_my_printf_h_plus.c 						\
						tests/lib_tests/my_printf/test_my_printf_sup.c 							\
						tests/lib_tests/my_printf/test_my_putstr.c								\
						tests/lib_tests/test_my_strcat.c										\
						tests/lib_tests/test_my_strcmp.c										\
						tests/lib_tests/test_my_strncmp.c										\
						tests/lib_tests/test_my_strdup.c										\
						tests/lib_tests/test_space_cmp.c										\
						tests/lib_tests/test_my_atoi.c											\
						tests/lib_tests/test_my_isspace.c										\
						tests/lib_tests/test_arrlen.c											\
						tests/lib_tests/test_binary_to_decimal.c								\
						tests/lib_tests/test_char_to_str.c										\
						tests/lib_tests/test_count_occur.c										\
						tests/lib_tests/test_cut_start_string.c									\
						tests/lib_tests/test_my_revstr.c										\
						tests/lib_tests/test_cut_end_string.c									\
						tests/lib_tests/test_my_ischar.c										\
						tests/asm_test/error_test/error_inst/test_add.c							\
						tests/asm_test/error_test/error_inst/test_live.c						\
						tests/asm_test/error_test/error_inst/test_and.c							\
						tests/asm_test/error_test/error_inst/test_aff.c							\
						tests/asm_test/error_test/error_inst/test_fork.c						\
						tests/asm_test/error_test/error_inst/test_ld.c							\
						tests/asm_test/error_test/error_inst/test_ldi.c							\
						tests/asm_test/error_test/error_inst/test_lfork.c						\
						tests/asm_test/error_test/error_inst/test_lld.c							\
						tests/asm_test/error_test/error_inst/test_lldi.c						\
						tests/asm_test/error_test/error_inst/test_or.c							\
						tests/asm_test/error_test/error_inst/test_st.c							\
						tests/asm_test/error_test/error_inst/test_sti.c							\
						tests/asm_test/error_test/error_inst/test_sub.c							\
						tests/asm_test/error_test/error_inst/test_xor.c							\
						tests/asm_test/error_test/error_inst/test_zjmp.c						\

OBJ             =		$(SRC:.c=.o)

OBJMAIN			=		$(SRCMAIN:.c=.o)

CFLAGS          +=		-I "./include/"
CFLAGS			+=		-I "../lib/include/"
CFLAGS			+=		-W -Wall -Wextra

all:			$(NAME)

$(NAME):		$(OBJ) $(OBJMAIN)
				$(CC) $(OBJMAIN) $(OBJ) -o $(NAME) -L ../lib -lmy
clean:
				$(RM) $(OBJ) $(OBJMAIN)

fclean:			clean
				$(RM) $(NAME)
				$(RM) *.gc*
				$(RM) unit_tests
				$(RM) *.o

tests_run:
				$(CC) --coverage $(CFLAGS) $(SRC) $(LIBSRC) -c
				$(CC) $(CFLAGS) $(TEST) -c
				gcc -o unit_tests *.o -lcriterion -lgcov
				./unit_tests
				gcovr
				gcovr -b

re:				fclean all

sweet:			all clean