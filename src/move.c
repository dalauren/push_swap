/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:27:26 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/06 17:22:16 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_pile **a, t_pile **b)
{
	t_pile	*tmp;
	int		tmp_data;
	int		i;

	(void)b;
	tmp_data = 0;
	i = 0;
	tmp = *a;
	if (tmp && tmp->next)
	{
		i = tmp->base_nb;
		tmp->base_nb = tmp->next->base_nb;
		tmp->next->base_nb = i;
		tmp_data = tmp->data;
		tmp->data = tmp->next->data;
		tmp->next->data = tmp_data;
	}
	set_nb(a);
}

void	swap_b(t_pile **a, t_pile **b)
{
	t_pile	*tmp;
	int		i;
	int		tmp_data;

	(void)a;
	tmp_data = 0;
	i = 0;
	tmp = *b;
	if (tmp && tmp->next)
	{
		i = tmp->base_nb;
		tmp_data = tmp->data;
		tmp->base_nb = tmp->next->base_nb;
		tmp->next->base_nb = i;
		tmp->data = tmp->next->data;
		tmp->next->data = tmp_data;
	}
	set_nb(b);
}

void	swap_both(t_pile **a, t_pile **b)
{
	if (*a && (*a)->next && *b && (*b)->next)
	{
		swap_a(a, b);
		swap_b(a, b);
	}
}

void	push_to_a(t_pile **a, t_pile **b)
{
	t_pile *tmp;

	tmp = NULL;
	if (*b)
	{
		tmp = *b;
		lst_push_front(a, tmp->data, tmp->nb, tmp->base_nb);
		(*b) = (*b)->next;
		free(tmp);
	}
}

void	push_to_b(t_pile **a, t_pile **b)
{
	t_pile *tmp;

	tmp = NULL;
	if (*a)
	{
		tmp = *a;
		lst_push_front(b, tmp->data, tmp->nb, tmp->base_nb);
		(*a) = (*a)->next;
		free(tmp);
	}
}
