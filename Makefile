##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## .
##

SRCS	=	src/main.c		\
		src/help_check.c	\
		src/player1.c		\
		src/player2.c		\
		src/create_map.c	\
		src/fill_map.c		\
		src/print.c		\
		src/game_player1.c	\
		src/game_player2.c	\
		src/attack.c		\
		src/defend.c		\
		src/success.c		\
		src/convert_bin_ascii.c \
		src/hit.c		\
		src/convert.c

TOOLS	=	tools/my_putstr.c	\
		tools/my_strcmp.c	\
		tools/my_put_nbr.c	\
		tools/my_getnbr.c	\
		tools/get_next_line.c	\
		tools/clean_str.c

OBJ	=	$(SRCS:.c=.o) $(TOOLS:.c=.o)

NAME	=	navy

CC	=	gcc -g3

RM	=	rm -f

CFLAGS += -Wall -Wextra

CPPFLAGS  += -I./include/

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
