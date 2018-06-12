/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:22:21 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/07 15:13:52 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		do_ope(char *line, t_stack *s)
{
	if (ft_strcmp(line, "sa") == 0)
		swap_a(&s->a, &s->b);
	else if (ft_strcmp(line, "sb") == 0)
		swap_b(&s->a, &s->b);
	else if (ft_strcmp(line, "ss") == 0)
		swap_both(&s->a, &s->b);
	else if (ft_strcmp(line, "pa") == 0)
		push_to_a(&s->a, &s->b);
	else if (ft_strcmp(line, "pb") == 0)
		push_to_b(&s->a, &s->b);
	else if (ft_strcmp(line, "ra") == 0)
		rotate_a(&s->a, &s->b);
	else if (ft_strcmp(line, "rb") == 0)
		rotate_b(&s->a, &s->b);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_both(&s->a, &s->b);
	else if (ft_strcmp(line, "rra") == 0)
		reverse_rotate_a(&s->a, &s->b);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_rotate_b(&s->a, &s->b);
	else if (ft_strcmp(line, "rrr") == 0)
		reverse_rotate_both(&s->a, &s->b);
	else
		return (-1);
	return (0);
}

int				check_pile(t_pile *a)
{
	t_pile *tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		else
			tmp = tmp->next;
	}
	return (0);
}

int				checker(t_stack *s)
{
	char *line;

	s->start_size = lst_size(s->a);
	while ((get_next_line(0, &line)) > 0)
	{
		if (do_ope(line, s) == -1)
		{
			free(line);
			ft_putendl_fd("Error", 2);
			free_stack(s);
			return (-1);
		}
		free(line);
	}
	if (check_pile(s->a) == 1 || s->start_size != lst_size(s->a))
		ft_putendl("KO");
	else
		ft_putendl("OK");
	free_stack(s);
	return (0);
}

int				main(int argc, char **argv)
{
	t_stack		s;
	int			i;

	i = 1;
	ft_bzero(&s, sizeof(t_stack));
	if (argc < 2)
		return (-1);
	while (i < argc)
	{
		if (push_on_list(&s, argv[i]) == -1)
		{
			free_stack(&s);
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		i++;
	}
	if (check_pile(s.a) == 0)
	{
		free_stack(&s);
		ft_putendl("OK");
		return (0);
	}
	checker(&s);
	return (0);
}
