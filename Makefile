##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for CPE_corewar_2018
##

ASM				=		asm

COR				=		corewar

CC				=		gcc

RM				=		rm -f

LIBDIR			=		lib

all:
				cd $(LIBDIR) && $(MAKE) sweet
				cd $(ASM) && $(MAKE) sweet
				#cd $(COR) && $(MAKE) sweet
clean:
				cd $(LIBDIR) && $(MAKE) clean

fclean:			clean
				cd $(ASM) && $(MAKE) fclean

tests_run:
				cd $(ASM) && $(MAKE) tests_run

re:				fclean all

sweet:			all clean