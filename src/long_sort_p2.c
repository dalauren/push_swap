/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort_p2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 17:46:36 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/07 14:43:46 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				find_right_one(t_stack *s)
{
	int		i;
	int		place;
	t_pile	*tmp;

	i = 0;
	place = 0;
	tmp = s->b;
	while (tmp)
	{
		if (tmp->base_nb == SAB - 1)
		{
			if (place > (lst_size(tmp) / 2))
				s->quickest_way = 1;
			else
				s->quickest_way = 0;
			i = tmp->base_nb;
			return (i);
		}
		place++;
		tmp = tmp->next;
	}
	return (-1);
}

void			put_order(t_stack *s, t_move_list *move_list, int value)
{
	int i;

	i = 0;
	while (SAB != value - 1)
	{
		chosen_one("ra", move_list, s);
		i++;
	}
}

void			good_place(t_stack *s, t_move_list *move_list)
{
	int i;

	i = 0;
	while (SAB + 1 != SBB)
	{
		chosen_one("ra", move_list, s);
		i++;
	}
	chosen_one("pa", move_list, s);
	while (i > 0)
	{
		chosen_one("rra", move_list, s);
		i--;
	}
	if (SAB > SANB)
		chosen_one("sa", move_list, s);
}

void			selec_value(t_stack *s, t_move_list *move_list, int value)
{
	if (SBB && SBB > value)
		good_place(s, move_list);
	if (s->quickest_way == 0)
	{
		while (s->b && SBB != value)
			chosen_one("rb", move_list, s);
		if (s->b && SBB == value)
			chosen_one("pa", move_list, s);
	}
	else
	{
		while (s->b && SBB != value)
		{
			chosen_one("rrb", move_list, s);
		}
		if (s->b && SBB == value)
			chosen_one("pa", move_list, s);
	}
}
