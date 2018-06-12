/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:01:37 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/11 13:27:24 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			start_short(t_stack *s)
{
	t_move_list	*move_list;

	move_list = start_init();
	create_tab(s);
	((lst_size(s->a) == 2) && check_pile(s->a) == 1) ? class_last(s, move_list)
		: check_pile(s->a);
	if (check_pile(s->a) == 0)
	{
		free_move_list(move_list);
		return (0);
	}
	if (s->start_size == 3)
	{
		class_last(s, move_list);
		free_move_list(move_list);
		return (0);
	}
	separate_by_mediane(s, move_list);
	while (s->b->next)
		last_sort(s, move_list);
	while (s->b)
		chosen_one("pa", move_list, s);
	(s->visu == 1) ? visu_push(s) : s->visu;
	free_move_list(move_list);
	return (0);
}

static void			end_sort(t_stack *s, t_move_list *move_list)
{
	int value;

	if (lst_size(s->a) == 3)
		class_last(s, move_list);
	while (s->b)
	{
		if (lst_size(s->a) < s->start_size)
		{
			if (!(value = find_right_one(s)))
				break ;
		}
		if (s->b && SAB < value)
		{
			put_order(s, move_list, value);
			visu_push(s);
			exit(0);
		}
		selec_value(s, move_list, value);
	}
	if (s->b && SBB == SAB - 1)
		chosen_one("pa", move_list, s);
}

static int			start_long(t_stack *s)
{
	t_move_list	*move_list;

	move_list = start_init();
	create_tab(s);
	if (check_pile(s->a) == 0)
	{
		free_move_list(move_list);
		return (0);
	}
	s->start_size = lst_size(s->a);
	sort_by_percent(s, move_list);
	end_sort(s, move_list);
	if (s->visu == 1)
		visu_push(s);
	free_move_list(move_list);
	return (0);
}

int					main(int argc, char **argv)
{
	t_stack		s;
	int			i;

	i = 0;
	ft_bzero(&s, sizeof(t_stack));
	if (argc < 2)
		return (-1);
	if ((ft_strcmp(argv[1], "-v") == 0) && argc > 2)
	{
		s.visu = 1;
		i++;
	}
	while (++i < argc)
	{
		if (push_on_list(&s, argv[i]) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(&s);
			return (-1);
		}
	}
	s.size_list = lst_size(s.a);
	(s.size_list <= 30) ? start_short(&s) : start_long(&s);
	free_stack(&s);
	return (0);
}
