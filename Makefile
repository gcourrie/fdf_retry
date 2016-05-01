##
## Makefile for wolf3d in /home/courri_g/rendu/CPE_2014_bsq
## 
## Made by gaspard courrier
## Login   <courri_g@epitech.net>
## 
## Started on  Thu Dec 18 18:00:29 2014 gaspard courrier
## Last update Sun Jan  4 20:45:08 2015 gaspard courrier
##

SRC	=	sources/main.c \
		sources/fdf.c \
		sources/key.c \
		sources/draw_fdf.c \
		sources/draw_line.c \
		sources/matrice.c


OBJ	=	$(SRC:.c=.o)

NAME	=	fdf

WARN	=	-W -Wextra -Wall -pedantic

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(WARN) -o $(NAME) $(OBJ) -L./minilibx/ -lmlx -L/usr/lib64/X11 -lXext -lX11 -L./libft -lft -lm

clean:
		rm $(OBJ)

fclean:		clean
		rm $(NAME)

re:		fclean all
