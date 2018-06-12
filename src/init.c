/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:19:32 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/04 16:03:34 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				tab_start_init(t_move_list *move_list)
{
	move_list[0].str = ft_strdup("sb");
	move_list[1].str = ft_strdup("sa");
	move_list[2].str = ft_strdup("ss");
	move_list[3].str = ft_strdup("pa");
	move_list[4].str = ft_strdup("pb");
	move_list[5].str = ft_strdup("ra");
	move_list[6].str = ft_strdup("rb");
	move_list[7].str = ft_strdup("rr");
	move_list[8].str = ft_strdup("rra");
	move_list[9].str = ft_strdup("rrb");
	move_list[10].str = ft_strdup("rrr");
	move_list[11].str = NULL;
	move_list[0].move = &swap_b;
	move_list[1].move = &swap_a;
	move_list[2].move = &swap_both;
	move_list[3].move = &push_to_a;
	move_list[4].move = &push_to_b;
	move_list[5].move = &rotate_a;
	move_list[6].move = &rotate_b;
	move_list[7].move = &rotate_both;
	move_list[8].move = &reverse_rotate_a;
	move_list[9].move = &reverse_rotate_b;
	move_list[10].move = &reverse_rotate_both;
	move_list[11].move = NULL;
}

int						quickest_way_move(t_stack *s, int value)
{
	int		i;
	t_pile	*tmp;

	i = 0;
	tmp = s->a;
	while (tmp && tmp->base_nb != value)
	{
		i++;
		tmp = tmp->next;
	}
	if (i > (lst_size(s->a) / 2))
		return (1);
	else
		return (0);
}

void					chosen_one(char *str, t_move_list *move_list,
		t_stack *s)
{
	int i;

	i = 0;
	while (move_list[i].str)
	{
		if (ft_strcmp(str, move_list[i].str) == 0)
		{
			if (s->visu == 1)
				visu_push(s);
			move_list[i].move(&s->a, &s->b);
			ft_putendl(str);
			s->total_actions++;
			return ;
		}
		i++;
	}
}

t_move_list				*start_init(void)
{
	t_move_list *move_list;

	if (!(move_list = (t_move_list*)malloc(sizeof(t_move_list) * 12)))
		return (NULL);
	tab_start_init(move_list);
	return (move_list);
}
