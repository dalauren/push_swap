/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:22:21 by dalauren          #+#    #+#             */
/*   Updated: 2018/05/02 13:09:34 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		do_ope(char *line, t_pile *a, t_pile *b)
{
	if (ft_strcmp(line, "sa") == 0)
		swap_a(&a);
	else if (ft_strcmp(line, "sb") == 0)
		swap_b(&b);
	else if (ft_strcmp(line, "ss") == 0)
		swap_both(&a, &b);
	else if (ft_strcmp(line, "pa") == 0)
		push_to_a(&a, &b);
	else if (ft_strcmp(line, "pb") == 0)
		push_to_b(&b, &a);
	else if (ft_strcmp(line, "ra") == 0)
		rotate_a(&a);
	else if (ft_strcmp(line, "rb") == 0)
		rotate_b(&b);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_both(&a, &b);
	else if (ft_strcmp(line, "rra") == 0)
		reverse_rotate_a(&a);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_rotate_b(&b);
	else if (ft_strcmp(line, "rrr") == 0)
		reverse_rotate_both(&a, &b);
	else
		return (-1);
	return (0);
}

int				check_list_end(t_pile *a)
{
	t_pile *tmp;
	int		nb;

	tmp = a;
	nb = tmp->data;
	while (tmp)
	{
		if (nb < tmp->data)
			return (-1);
		nb = tmp->data;
		tmp = tmp->next;
	}
	return (0);
}

int				checker(t_pile *a, t_pile *b)
{
	char *line;

	while ((get_next_line(0, &line)) > 0)
	{
		if (do_ope(line, a, b) == -1)
		{
			free(line);
			ft_putendl_fd("Error", 2);
			return (-1);
		}
		free(line);
	}
	if (check_list_end(a) == -1)
		ft_putendl("KO");
	else
		ft_putendl("OK");
	free(a);
	free(b);
	return (0);
}

int				main(int argc, char **argv)
{
	t_stack s;
	int i;

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
	checker(s.a, s.b);
	return (0);
}
