/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:03:46 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/07 15:09:02 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define SAB s->a->base_nb
# define SANB s->a->next->base_nb
# define SANNB s->a->next->next->base_nb
# define SBB s->b->base_nb
# define SBNB s->b->next->base_nb
# define SBNNB s->b->next->next->base_nb
# define ABS(x) (x < 0) ? -x : x

typedef struct			s_pile
{
	int					data;
	int					base_nb;
	int					nb;
	struct s_pile		*next;
}						t_pile;

typedef struct			s_stack
{
	t_pile				*a;
	t_pile				*b;
	int					visu;
	int					free;
	int					nb_nod_push;
	int					base_nb;
	int					quickest_way;
	int					nb_node_to_move;
	int					min;
	int					percent;
	int					up;
	int					total_actions;
	int					size_list;
	int					start_size;
	int					nb;
	int					mediane;
}						t_stack;

typedef struct			s_move_list
{
	char				*str;
	void				(*move)(t_pile **a, t_pile **b);
}						t_move_list;

typedef struct			s_mediane
{
	int					mediane;
	int					nb_up;
	int					nb_down;
	t_pile				*tmp;
	t_pile				*tmp2;
}						t_mediane;

void					swap_a(t_pile **a, t_pile **b);
void					swap_b(t_pile **a, t_pile **b);
void					swap_both(t_pile **a, t_pile **b);
void					push_to_a(t_pile **a, t_pile **b);
void					push_to_b(t_pile **a, t_pile **b);
void					rotate_a(t_pile **a, t_pile **b);
void					rotate_b(t_pile **a, t_pile **b);
void					rotate_both(t_pile **a, t_pile **b);
void					reverse_rotate_a(t_pile **a, t_pile **b);
void					reverse_rotate_b(t_pile **a, t_pile **b);
void					reverse_rotate_both(t_pile **a, t_pile **b);
void					lst_push_back(t_pile **begin_list, int data, int nb,
						int base_nb);
void					lst_push_front(t_pile **begin_list, int data, int nb,
						int base_nb);
void					free_move_lsit(t_move_list *move_list);
void					chosen_one(char *str, t_move_list *move_list, t_stack
						*s);
void					visu_push(t_stack *s);
void					set_nb(t_pile **a);
void					class_last(t_stack *s, t_move_list *move_list);
void					sort_int_tab(int *tab, unsigned int size, t_stack *s);
void					create_tab(t_stack *s);
void					push_first_value(t_stack *s, t_move_list *move_list);
void					push_under_mediane(t_stack *s, t_move_list *move_list);
void					selec_value(t_stack *s, t_move_list *move_list,
						int value);
void					sort_by_percent(t_stack *s, t_move_list *move_list);
void					free_move_list(t_move_list *move_list);
void					free_list(t_pile *a);
void					free_stack(t_stack *s);
void					put_order(t_stack *s, t_move_list *move_list,
						int value);
int						check_pile_b(t_pile *a);
int						find_right_one(t_stack *s);
int						last_sort(t_stack *s, t_move_list *move_list);
int						sort_tab(int *tab, unsigned int size);
int						nb_under_mediane(t_stack *s, t_pile *a);
int						find_min_list(t_stack *s);
int						quickest_way_move(t_stack *s, int value);
int						separate_by_mediane(t_stack *s, t_move_list *move_list);
int						lst_size(t_pile *begin_list);
int						check_list(t_pile **a, int data);
int						check_pile(t_pile *a);
int						check_arg(char *str);
int						push_on_list(t_stack *s, char *str);
int						checker(t_stack *s);
int						find_mediane_lst(t_pile *a);
t_pile					*create_elem(int data, int nb, int base_nb);
t_move_list				*start_init(void);

#endif
