# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalauren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 08:03:44 by dalauren          #+#    #+#              #
#    Updated: 2018/06/03 17:51:45 by dalauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PRINTF = ./ft_printf/

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC_PTF = check_buff.c\
		  flags.c\
		  flags_2.c\
		  flags_3.c\
		  flags_4.c\
		  ft_printf.c\
		  ft_utoa_base.c\
		  padding.c\
		  spe_char.c\
		  spe_d.c\
		  spe_d2.c\
		  spe_p.c\
		  spe_wc.c\
		  spe_ws.c\
		  spe_x.c\
		  unicode.c\

INC_P = ./ft_printf/ft_printf.h

SRC_LIB = ft_atoi.c\
		  ft_bzero.c\
		  ft_swap.c\
		  ft_isalnum.c\
		  ft_isalpha.c\
		  ft_isascii.c\
		  ft_isdigit.c\
		  ft_isprint.c\
		  ft_isspace.c\
		  ft_itoa.c\
		  ft_lstadd.c\
		  ft_lstdel.c\
		  ft_lstdelone.c\
		  ft_lstiter.c\
		  ft_lstmap.c\
		  ft_lstnew.c\
		  ft_memalloc.c\
		  ft_memccpy.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_memcpy.c\
		  ft_memdel.c\
		  ft_memmove.c\
		  ft_memset.c\
		  ft_printlst.c\
		  ft_putchar.c\
		  ft_putchar_fd.c\
		  ft_putendl.c\
		  ft_putendl_fd.c\
		  ft_putnbr.c\
		  ft_putnbr_fd.c\
		  ft_putstr.c\
		  ft_putstr_fd.c\
		  ft_strcat.c\
		  ft_strchr.c\
		  ft_strclr.c\
		  ft_strcmp.c\
		  ft_strcpy.c\
		  ft_strdel.c\
		  ft_strdup.c\
		  ft_strequ.c\
		  ft_striter.c\
		  ft_striteri.c\
		  ft_strjoin.c\
		  ft_strlcat.c\
		  ft_strlen.c\
		  ft_strmap.c\
		  ft_strmapi.c\
		  ft_strncat.c\
		  ft_strncmp.c\
		  ft_strnequ.c\
		  ft_strnew.c\
		  ft_strnstr.c\
		  ft_strrchr.c\
		  ft_strrev.c\
		  ft_strstr.c\
		  ft_strsub.c\
		  ft_strtrim.c\
		  ft_tolower.c\
		  ft_toupper.c\
		  ft_strncpy.c\
		  ft_strsplit.c\
		  ft_lstsize.c\
		  ft_lst_last.c\
		  ft_lst_push_front.c\
		  ft_lst_push_back.c\
		  ft_create_elem.c\
		  ft_skip.c\
		  ft_intmaxtoa.c\
		  ft_putnstr.c\
		  ft_strncpy2.c\
		  ft_strwlen.c\
		  ft_strjoinfree.c\
		  ft_uintmaxtoa.c\
		  get_next_line.c\
		  get_next_line_utilities.c\
		  ft_atol.c\
		  ft_deltab.c\

OBJ = $(SRC_LIB:.c=.o)
OBJ_P = $(SRC_PTF:.c=.o)

SRC_P_F = $(addprefix $(PRINTF), $(SRC_PTF))

all: $(NAME)

$(NAME):
	@$(CC) -c $(FLAGS) $(SRC_LIB) $(SRC_P_F) -I$(INC_P)
	@ar rcs $(NAME) $(OBJ) $(LIBFT_P) $(OBJ_P)

clean:
	@rm -f $(OBJ_P)
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
