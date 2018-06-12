/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:03:27 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/06 16:56:13 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				push_first_value(t_stack *s, t_move_list *move_list)
{
	if (quickest_way_move(s, s->min) == 1)
	{
		while (SAB != s->min)
			chosen_one("rra", move_list, s);
		if (SAB == s->min)
			chosen_one("pb", move_list, s);
	}
	else
	{
		while (SAB != s->min)
			chosen_one("ra", move_list, s);
		if (SAB == s->min)
			chosen_one("pb", move_list, s);
	}
}

int					last_sort(t_stack *s, t_move_list *move_list)
{
	while (s->b && s->b->next &&
			s->b->base_nb > s->b->next->base_nb)
	{
		if (check_pile(s->a) == 1)
			chosen_one("sa", move_list, s);
		chosen_one("pa", move_list, s);
	}
	if (s->b && s->b->next && s->b->base_nb < s->b->next->base_nb)
		chosen_one("sb", move_list, s);
	return (0);
}

void				check_position(t_stack *s, t_move_list *move_list)
{
	if (s->a && s->a->next && SAB > SANB && (s->b && s->b->next &&
				s->b->base_nb < s->b->next->base_nb))
		chosen_one("ss", move_list, s);
	else if (s->b && s->b->next && s->b->base_nb < s->b->next->base_nb)
		chosen_one("sb", move_list, s);
}

static void			part_two(t_stack *s, t_move_list *move_list)
{
	while (SAB != s->min)
	{
		if (SAB < s->min + 2 && SAB < s->mediane)
		{
			if (SAB > s->min + 2)
				chosen_one("pb", move_list, s);
			check_position(s, move_list);
		}
		chosen_one("ra", move_list, s);
	}
	if (SAB == s->min)
	{
		chosen_one("pb", move_list, s);
		check_position(s, move_list);
	}
}

void				push_under_mediane(t_stack *s, t_move_list *move_list)
{
	if ((s->min = find_min_list(s)) == -1)
		return ;
	s->nb_node_to_move = (lst_size(s->a) <= 3) ? 0 : s->nb_node_to_move;
	if (lst_size(s->a) <= 3)
		return ;
	if (quickest_way_move(s, s->min) == 1)
	{
		while (SAB != s->min)
		{
			if (SAB < s->min + 2 && SAB < s->mediane)
			{
				if (SAB > s->min + 2)
					chosen_one("pb", move_list, s);
				check_position(s, move_list);
			}
			chosen_one("rra", move_list, s);
		}
		if (SAB == s->min)
		{
			chosen_one("pb", move_list, s);
			check_position(s, move_list);
		}
	}
	else if (quickest_way_move(s, s->min) == 0)
		part_two(s, move_list);
}
