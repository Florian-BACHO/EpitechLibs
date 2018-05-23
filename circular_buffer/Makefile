##
## EPITECH PROJECT, 2018
## irc
## File description:
## makefile
##

SRC		=	src/cbuffer_create.c \
			src/cbuffer_destroy.c \
			src/cbuffer_is_empty_full.c \
			src/cbuffer_reset.c \
			src/cbuffer_read_write.c \
			src/cbuffer_count_elements.c \
			src/pcb_get_next_idx.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra

CPPFLAGS	+=	-I ./include

NAME		=	libcircular_buffer.a

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
