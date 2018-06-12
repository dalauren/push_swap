/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:40:02 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/06 11:11:11 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			set_nb(t_pile **a)
{
	int		i;
	t_pile	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->nb = i;
		tmp = tmp->next;
		i++;
	}
}

void			rotate_both(t_pile **a, t_pile **b)
{
	if (*a && (*a)->next && *b && (*b)->next)
	{
		rotate_a(a, b);
		rotate_b(b, a);
	}
}

int				check_arg(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (0);
}

int				check_list(t_pile **a, int data)
{
	t_pile *tmp;

	tmp = *a;
	while (tmp)
	{
		if (data == tmp->data)
			return (-1);
		else
			tmp = tmp->next;
	}
	return (0);
}

int				push_on_list(t_stack *s, char *str)
{
	long int value;

	value = ft_atol(str);
	if (value > INT_MAX || value < INT_MIN)
		return (-1);
	if (check_arg(str) == -1)
		return (-1);
	if (check_list(&s->a, value) != -1)
	{
		lst_push_back(&s->a, value, s->nb, s->base_nb);
		s->nb++;
		s->size_list++;
		return (0);
	}
	else
		return (-1);
	return (0);
}
