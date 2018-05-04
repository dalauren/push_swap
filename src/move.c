/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:27:26 by dalauren          #+#    #+#             */
/*   Updated: 2018/05/02 18:39:51 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_pile **begin_list)
{
	t_pile	*tmp;
	int		i;

	i = 0;
	tmp = *begin_list;
	if (tmp && tmp->next)
	{
		i = tmp->data;
		tmp->data = tmp->next->data;
		tmp->next->data = i;
	}
}

void	swap_b(t_pile **begin_list)
{
	t_pile *tmp;
	int i;

	i = 0;
	tmp = *begin_list;
	if (tmp && tmp->next)
	{
		i = tmp->data;
		tmp->data = tmp->next->data;
		tmp->next->data = i;
	}
}

void	swap_both(t_pile **begin_list1, t_pile **begin_list2)
{
	swap_a(begin_list1);
	swap_b(begin_list2);
}

void	push_to_a(t_pile **a, t_pile **b)
{
	t_pile *tmp;

	tmp = *b;
	if (*a && *b)
	{
		lst_push_front(a, tmp->data);
		(*b) = (*b)->next;
	}
	free(tmp);
}

void	push_to_b(t_pile **b, t_pile **a)
{
	t_pile *tmp;

	tmp = *a;
	if (*a && *b)
	{
		lst_push_front(b, tmp->data);
		(*a) = (*a)->next;
	}
	free(tmp);
}
