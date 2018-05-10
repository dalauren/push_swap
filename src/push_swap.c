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
	s.mediane = find_mediane_lst(s.a);
	return (0);
}
