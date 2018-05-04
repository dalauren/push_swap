# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalauren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 17:32:37 by dalauren          #+#    #+#              #
#    Updated: 2018/05/02 18:40:37 by dalauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc -Wall -Werror -Wextra

LIBFT = ./libft/

SRC = main.c \
	  move.c \
	  move2.c \
	  move3.c \
	  element.c \

OBJ = $(SRC:.c=.o)

RM = rm -f

all :		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBFT)
			$(CC) -o $(NAME) $(OBJ) ./libft/libft.a

clean:
			$(RM) $(OBJ)
			make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME)
			make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclen re
