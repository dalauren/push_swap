/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:33:06 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/07 14:42:31 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			nb_under_percent(t_stack *s, t_pile *a)
{
	t_pile	*tmp;
	int		i;

	i = 0;
	tmp = a;
	if (tmp->next)
	{
		while (tmp)
		{
			if (tmp->data < s->percent)
				i++;
			tmp = tmp->next;
		}
		return (i);
	}
	return (-1);
}

static int			*tab_create(t_stack *s)
{
	int		*tab;
	int		i;
	t_pile	*tmp;

	tmp = s->a;
	i = 0;
	if (!(tab = (int*)malloc(sizeof(int) * s->size_list)))
		return (NULL);
	while (tmp)
	{
		tab[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

void				separate_percent(t_stack *s, t_move_list *move_list)
{
	while (s->nb_node_to_move > 0)
	{
		while (s->a->data < s->percent && lst_size(s->a) > 3)
		{
			chosen_one("pb", move_list, s);
			s->nb_node_to_move--;
		}
		if (lst_size(s->a) > 3)
			chosen_one("ra", move_list, s);
		else
			return ;
	}
}

static void			free_tab(t_stack *s, int *tab)
{
	if (s->free == 1)
	{
		free(tab);
		s->free = 0;
	}
}

void				sort_by_percent(t_stack *s, t_move_list *move_list)
{
	int *tab;

	s->size_list = lst_size(s->a);
	if (s->size_list > 3)
	{
		if (!(tab = tab_create(s)))
			return ;
		s->free = 1;
	}
	if (s->size_list > 3)
		sort_int_tab(tab, (unsigned)s->size_list, s);
	while (s->size_list > 3)
	{
		if ((s->nb_node_to_move = nb_under_percent(s, s->a)) == -1)
			break ;
		separate_percent(s, move_list);
		free_tab(s, tab);
		if (lst_size(s->a) > 3)
			sort_by_percent(s, move_list);
		else
			break ;
	}
	free_tab(s, tab);
}
