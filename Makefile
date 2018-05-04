# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalauren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/04 14:21:48 by dalauren          #+#    #+#              #
#    Updated: 2018/05/04 17:27:25 by dalauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc -Wall -Wextra -Werror

LIBFT = ./libft/

INC_DIR = includes/

SRC_DIR = src/

SRC = push_swap.c \
	  move.c \
	  move2.c \
	  move3.c \
	  element.c \

DONE = [\033[0;32mDONE\033[0m]

OBJ = $(SRC:.c=.o)

RM = rm -f

SRC_F = $(addprefix $(SRC_DIR), $(SRC))

all : $(NAME)

$(NAME): $(SRC_F)
		make -C $(LIBFT)
		$(CC) -c $(SRC_F) -I $(INC_DIR)
		$(CC) -o $(NAME) $(OBJ) -I $(INC_DIR) libft/libft.a
		@echo "push_swap = $(DONE)"
clean:
		$(RM) $(OBJ)
		make clean -C $(LIBFT)

fclean:	clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
