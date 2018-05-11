/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:01:37 by dalauren          #+#    #+#             */
/*   Updated: 2018/05/11 17:28:17 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			separate_mediane(t_stack *s)
{
	int		nb;

	nb = 0;
	while (nb != s->s_len)
	{
		if (s->a->data < s->mediane)
		{
			/*ft_putstr("pa\n");*/
			push_to_b(&s->b, &s->a);
			nb++;
		}
		else
		{
			/*ft_putstr("ra\n");*/
			rotate_a(&s->a);
			nb++;
		}
	}
}

int				main(int argc, char **argv)
{
	t_stack	s;
	t_stack	tmp;
	int		i;

	i = 1;
	ft_bzero(&s, sizeof(t_stack));
	if (argc < 2)
	{
		ft_putstr_fd("wrong number of arguments\n", 2);
		return (-1);
	}
	while (i < argc)
	{
		if (push_on_list(&s, argv[i]) == -1)
		{
			ft_putstr_fd("error\n", 2);
			return (-1);
		}
		i++;
	}
	// une fonciton
	while (lst_size(s.a) > 3)
	{
		s.mediane = find_mediane_lst(s.a);
		separate_mediane(&s);
	}
	// jusqu'a la
	tmp = s;
	while (tmp.a || tmp.b)
	{
		while (tmp.a)
		{
			printf("a = | %d |\n", tmp.a->data);
			tmp.a = tmp.a->next;
		}
	 while (tmp.b)
		{
			printf("b = %d |\n", tmp.b->data);
			tmp.b = tmp.b->next;
		}
	}
	return (0);
}
