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

NAME2 = checker

CC = gcc -Wall -Wextra -Werror

LIBFT = ./libft/

INC_DIR = includes/

SRC_DIR = src/

SRC = push_swap.c \
	  move.c \
	  move2.c \
	  move3.c \
	  element.c \

SRC2 = checker.c \
	  move.c \
	  move2.c \
	  move3.c \
	  element.c \

DONE = [\033[0;32mDONE\033[0m]

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

RM = rm -f

SRC_F = $(addprefix $(SRC_DIR), $(SRC))
SRC2_F = $(addprefix $(SRC_DIR), $(SRC2))

all : $(NAME) $(NAME2)

$(NAME): $(SRC_F)
		make -C $(LIBFT)
		$(CC) -c $(SRC_F) -I $(INC_DIR)
		$(CC) -o $(NAME) $(OBJ) -I $(INC_DIR) libft/libft.a
		@echo "push_swap = $(DONE)"

$(NAME2): $(SRC2_F)
		make -C $(LIBFT)
		$(CC) -c $(SRC2_F) -I $(INC_DIR)
		$(CC) -o $(NAME2) $(OBJ2) -I $(INC_DIR) libft/libft.a
		@echo "checker = $(DONE)"

clean:
		$(RM) $(OBJ)
		$(RM) $(OBJ2)
		make clean -C $(LIBFT)

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(NAME2)
		make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
