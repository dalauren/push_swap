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
	t_pile *a;
	t_pile *b;
	int mediane;
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
	mediane = find_mediane_lst(a);
	printf("mediane = %d\n", mediane);
	return (0);
}
