##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for makefile
##

NAME			=		libmy.a

CC				=		gcc

ARC				= 		ar rc

RM				=		rm -f

SRC             =		my_putstr.c                 	\
						my_putchar.c					\
						my_printf/my_printf.c			\
						my_printf/my_printf2.c			\
						my_put_nbr_base.c				\
						my_put_nbr.c					\
						my_strlen.c						\
						my_ischar.c						\
						my_isspace.c					\
						my_atoi.c						\
						binary_to_decimal.c				\
						my_strdup.c						\
						my_strcmp.c						\
						my_strncmp.c					\
						my_revstr.c						\
						my_strcat.c						\
						count_occur.c					\
						cut_str.c 						\
						cut_start_string.c				\
						free_arr.c						\
						parse_getline.c					\
						space_cmp.c						\
						arrlen.c						\
						char_to_str.c					\
						cut_end_string.c				\

OBJ             =		$(SRC:.c=.o)

CFLAGS          +=		-I "./include/"
CFLAGS			+=		-W -Wall -Wextra

all:			$(NAME)

$(NAME):		$(OBJ)
				$(ARC) $(NAME) $(OBJ)
clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)
				$(RM) *.gc*
				$(RM) unit_tests
				$(RM) *.o

re:				fclean all

sweet:			all clean