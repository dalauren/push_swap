/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:03:46 by dalauren          #+#    #+#             */
/*   Updated: 2018/05/04 14:31:24 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include "./libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

# define ABS(x) (x < 0) ? -x : x

typedef struct		s_pile
{
	int				data;
	struct s_pile	*next;
}					t_pile;

//typedef struct		s_stack
//{
	//t_pile			*a;
	//t_pile			*b;
//}					t_stack;

typedef struct			s_mediane
{
	int					mediane;
	int					nb_up;
	int					nb_down;
	t_pile				*tmp;
	t_pile				*tmp2;
}						t_mediane;

void			swap_a(t_pile **begin_list);
void			swap_b(t_pile **begin_list);
void			swap_both(t_pile **begin_list1, t_pile **begin_list2);
void			push_to_a(t_pile **a, t_pile **b);
void			push_to_b(t_pile **b, t_pile **a);
void			rotate_a(t_pile **a);
void			rotate_b(t_pile **b);
void			rotate_both(t_pile **a, t_pile **b);
void			reverse_rotate_a(t_pile **a);
void			reverse_rotate_b(t_pile **b);
void			reverse_rotate_both(t_pile **a, t_pile **b);
void			lst_push_back(t_pile **begin_list, int data);
void			lst_push_front(t_pile **begin_list, int data);
int				check_list(t_pile **a, int data);
int				check_list_end(t_pile *a);
int				check_arg(char *str);
int				push_on_list(t_pile **a, char *str);
int				checker(t_pile *a, t_pile *b);
int				find_mediane_lst(t_pile *a);
t_pile			*create_elem(int data);

#endif
