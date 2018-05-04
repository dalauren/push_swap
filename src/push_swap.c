/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:01:37 by dalauren          #+#    #+#             */
/*   Updated: 2018/05/04 17:26:00 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_arg(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-')
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

static int		check_list(t_pile **a, int data)
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

static int		push_on_list(t_pile **a, char *str)
{
	int value;

	value = ft_atoi(str);
	if (check_arg(str) == -1)
		return (-1);
	if (check_list(a, value) != -1)
	{
		lst_push_back(a, value);
		return (0);
	}
	else
		return (-1);
	return (0);
}

int				main(int argc, char **argv)
{
	t_pile *a;
	t_pile *b;
	int i;

	i = 1;
	a = NULL;
	b = NULL;
	if (argc < 2)
	{
		ft_putstr_fd("wrong number of arguments\n", 2);
		return (-1);
	}
	while (i < argc)
	{
		if (push_on_list(&a, argv[i]) == -1)
		{
			ft_putstr_fd("error\n", 2);
			return (-1);
		}
		i++;
	}
	return (0);
}
