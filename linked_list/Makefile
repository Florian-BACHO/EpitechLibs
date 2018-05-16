##
## EPITECH PROJECT, 2018
## irc
## File description:
## makefile
##

SRC		=	$(shell find src -type f -name "*.c")

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra

CPPFLAGS	+=	-I ./include

NAME		=	liblinked_list.a

all: $(NAME)

debug: CFLAGS += -g3

debug: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
