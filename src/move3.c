/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:40:02 by dalauren          #+#    #+#             */
/*   Updated: 2018/05/11 15:58:01 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_pile **a, t_pile **b)
{
	rotate_a(a);
	rotate_b(b);
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
	int value;

	value = ft_atoi(str);
	if (check_arg(str) == -1)
		return (-1);
	if (check_list(&s->a, value) != -1)
	{
		lst_push_back(&s->a, value, s->nb);
		s->nb++;
		s->s_len++;
		return (0);
	}
	else
		return (-1);
	return (0);
}
