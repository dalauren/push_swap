/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:45:10 by dalauren          #+#    #+#             */
/*   Updated: 2018/05/02 18:38:47 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_pile **a)
{
	t_pile *tmp;
	t_pile *tmp2;

	tmp = *a;
	tmp2 = (*a)->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *a;
	(*a)->next = NULL;
	*a = tmp2;
}

void	rotate_b(t_pile **b)
{
	t_pile *tmp;
	t_pile *tmp2;

	tmp = *b;
	tmp2 = (*b)->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *b;
	(*b)->next = NULL;
	*b = tmp2;
}

void	reverse_rotate_a(t_pile **a)
{
	t_pile *tmp;
	t_pile *tmp2;

	tmp = *a;
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
}

void	reverse_rotate_b(t_pile **b)
{
	t_pile *tmp;
	t_pile *tmp2;

	tmp = *b;
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
}

void	reverse_rotate_both(t_pile **a, t_pile **b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
}
