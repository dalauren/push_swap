/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:32:53 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/07 11:41:17 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				sort_tab(int *tab, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void			sort_int_tab(int *tab, unsigned int size, t_stack *s)
{
	unsigned int	i;
	int				swap;

	swap = 0;
	while (sort_tab(tab, size))
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				swap = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swap;
			}
			i++;
		}
	}
	s->up = 2;
	s->percent = tab[(size * 10) / 100 + s->up];
}

void			attribute_value(t_stack *s, int *tab)
{
	t_pile	*tmp;
	int		i;

	tmp = s->a;
	i = 0;
	while (tmp)
	{
		i = 0;
		while (i < s->size_list)
		{
			if (tab[i] == tmp->data)
			{
				tmp->base_nb = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void			create_tab(t_stack *s)
{
	int		i;
	int		*tab;
	t_pile	*tmp;

	i = 0;
	tmp = s->a;
	s->start_size = lst_size(s->a);
	s->size_list = lst_size(s->a);
	if (!(tab = (int *)malloc(sizeof(int) * s->size_list)))
		return ;
	while (tmp)
	{
		tab[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	sort_int_tab(tab, (unsigned int)s->size_list, s);
	attribute_value(s, tab);
	free(tab);
}

int				separate_by_mediane(t_stack *s, t_move_list *move_list)
{
	if (!(s->mediane = find_mediane_lst(s->a)))
		return (-1);
	s->min = find_min_list(s);
	s->nb_node_to_move = nb_under_mediane(s, s->a);
	push_first_value(s, move_list);
	while (s->nb_node_to_move > 0)
	{
		if (lst_size(s->a) <= 3)
			break ;
		push_under_mediane(s, move_list);
	}
	if (lst_size(s->a) == 3)
		class_last(s, move_list);
	return (0);
}
