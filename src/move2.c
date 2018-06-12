/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:45:10 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/06 11:10:47 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_pile **a, t_pile **b)
{
	t_pile *tmp;
	t_pile *tmp2;

	(void)b;
	tmp = *a;
	tmp2 = (*a)->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *a;
	(*a)->next = NULL;
	*a = tmp2;
	set_nb(a);
}

void	rotate_b(t_pile **a, t_pile **b)
{
	t_pile *tmp;
	t_pile *tmp2;

	(void)a;
	tmp = *b;
	if (tmp)
	{
		tmp2 = (*b)->next;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = *b;
		(*b)->next = NULL;
		*b = tmp2;
		set_nb(b);
	}
}

void	reverse_rotate_a(t_pile **a, t_pile **b)
{
	t_pile *tmp;
	t_pile *tmp2;

	(void)b;
	tmp = *a;
	if (tmp)
	{
		tmp2 = *a;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			if (tmp->next != NULL)
				tmp2 = tmp2->next;
		}
		tmp->next = *a;
		tmp2->next = NULL;
		*a = tmp;
		set_nb(a);
	}
}

void	reverse_rotate_b(t_pile **a, t_pile **b)
{
	t_pile *tmp;
	t_pile *tmp2;

	(void)a;
	tmp = *b;
	if (tmp)
	{
		tmp2 = *b;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			if (tmp->next != NULL)
				tmp2 = tmp2->next;
		}
		tmp->next = *b;
		tmp2->next = NULL;
		*b = tmp;
		set_nb(b);
	}
}

void	reverse_rotate_both(t_pile **a, t_pile **b)
{
	if (*a && (*a)->next && *b && (*b)->next)
	{
		reverse_rotate_a(a, b);
		reverse_rotate_b(a, b);
	}
}
