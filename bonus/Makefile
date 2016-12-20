##
## Makefile for  in /home/januar_m/delivery/PSU/bootstrap/boostrap_2016_sokoban
## 
## Made by Martin Januario
## Login   <martin.januario@epitech.eu>
## 
## Started on  Sun Dec 11 19:28:08 2016 
## Last update Tue Dec 20 10:00:51 2016 
##

SRC	=	SRC/main.c		\
		SRC/free_tab.c		\
		SRC/check_map.c		\
		SRC/ini_struct.c	\
		SRC/my_strdup.c		\
		SRC/my_strcpy.c		\
		SRC/my_strcmp.c		\
		SRC/souris.c		\
		SRC/loading.c		\
		SRC/int_to_str.c	\
		SRC/display_map.c	\
		SRC/my_put_nbr.c	\
		SRC/music.c		\
		SRC/disp_help.c		\
		SRC/my_puterror.c	\
		SRC/ini_map.c		\
		SRC/p_up.c		\
		SRC/recup_map.c		\
		SRC/check_finish.c	\
		SRC/p_down.c		\
		SRC/p_left.c		\
		SRC/p_right.c		\
		SRC/start_the_game.c	\
		SRC/my_strlen.c		\
		SRC/my_putstr.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I include/

NAME	=	my_sokoban

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lncurses -lc_graph_prog

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
