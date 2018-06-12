/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:04:13 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/07 14:56:56 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				check_pile_b(t_pile *a)
{
	t_pile *tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->base_nb < tmp->next->base_nb)
			return (1);
		else
			tmp = tmp->next;
	}
	return (0);
}

int				check_pile(t_pile *a)
{
	t_pile *tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->base_nb > tmp->next->base_nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int				nb_under_mediane(t_stack *s, t_pile *a)
{
	t_pile	*tmp;
	int		i;

	i = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->base_nb < s->mediane)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int				find_min_list(t_stack *s)
{
	t_pile	*tmp;
	int		min;

	tmp = s->a;
	min = tmp->base_nb;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->base_nb < min)
			{
				min = tmp->base_nb;
				s->nb_node_to_move = tmp->base_nb;
			}
			tmp = tmp->next;
		}
		return (min);
	}
	return (-1);
}

void			class_last(t_stack *s, t_move_list *move_list)
{
	if (lst_size(s->a) == 2 && check_pile(s->a) != 0)
	{
		chosen_one("sa", move_list, s);
		return ;
	}
	if (SAB > SANB && SAB > SANNB && SANB < SANNB)
		chosen_one("ra", move_list, s);
	else if (SAB < SANB && SANB > SANNB && SANNB > SAB)
	{
		chosen_one("rra", move_list, s);
		chosen_one("sa", move_list, s);
	}
	else if (SAB > SANB && SANB < SANNB)
		chosen_one("sa", move_list, s);
	else if (SAB > SANB && SAB > SANNB && SANB > SANNB)
	{
		chosen_one("ra", move_list, s);
		chosen_one("sa", move_list, s);
	}
	else if (SAB < SANB && SANB > SANNB && SAB > SANNB)
		chosen_one("rra", move_list, s);
}
