/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:17:12 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/11 13:04:26 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		put_color(t_stack *s, t_pile *tmp_a)
{
	if (s->start_size <= 30)
	{
		if (tmp_a->base_nb == s->mediane)
			ft_printf("| \033[0;33m%10d\033[0m| ", tmp_a->data);
		else if (tmp_a->base_nb < s->mediane)
			ft_printf("| \033[0;32m%10d\033[0m| ", tmp_a->data);
		else if (tmp_a->base_nb > s->mediane)
			ft_printf("| \033[0;31m%10d\033[0m| ", tmp_a->data);
	}
	else
	{
		if (tmp_a->base_nb == s->percent)
			ft_printf("| \033[0;33m%10d\033[0m |", tmp_a->data);
		else if (tmp_a->base_nb < s->percent)
			ft_printf("| \033[0;32m%10d\033[0m |", tmp_a->data);
		else if (tmp_a->base_nb > s->percent)
			ft_printf("| \033[0;31m%10d\033[0m |", tmp_a->data);
	}
}

static void		print_stack(t_stack *s)
{
	int		i;
	t_pile	*tmp_a;
	t_pile	*tmp_b;

	i = 0;
	tmp_a = s->a;
	tmp_b = s->b;
	while (i < s->start_size)
	{
		if (tmp_a)
			put_color(s, tmp_a);
		else
			ft_printf("| %10s |", "_");
		if (tmp_b)
			ft_printf(" %-10d |\n", tmp_b->data);
		else
			ft_printf(" %-10s |\n", "_");
		if (tmp_a)
			tmp_a = tmp_a->next;
		if (tmp_b)
			tmp_b = tmp_b->next;
		i++;
	}
}

void			visu_push(t_stack *s)
{
	char str[2];

	ft_printf("+-------------------------+\n");
	ft_printf("|                         |\n");
	print_stack(s);
	ft_printf("|                         |\n");
	ft_printf("+-------------------------+\n");
	read(0, str, 1);
}
