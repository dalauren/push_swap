/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:01:37 by dalauren          #+#    #+#             */
/*   Updated: 2018/05/02 20:08:51 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack *stack;
	/*t_pile *a;*/
	/*t_pile *tmp;*/
	/*t_pile *b;*/
	int i;
	/*int j = 5;*/

	ft_bzero(&stack, sizeof(t_stack));
	i = 1;
	if (argc < 2)
	{
		ft_putstr("wrong number of arguments\n");
		return (0);
	}
	while (i < argc)
	{
		
	}
	/*lst = NULL;*/
	/*lst2 = NULL;*/
	/*while (i != 5)*/
	/*{*/
		/*lst_push_back(&lst, i);*/
		/*i++;*/
	/*}*/
	/*while (j != 0)*/
	/*{*/
		/*lst_push_back(&lst2, j);*/
		/*j--;*/
	/*}*/
	/*[>push_to_a(&lst, &lst2);<]*/
	/*//push_to_b(&lst2, &lst);*/
	/*reverse_rotate_both(&lst, &lst2);*/
	/*//lst_push_front(&lst, 8);*/
	/*tmp = lst;*/
	/*while (tmp)*/
	/*{*/
		/*printf("data2 = %d\n", tmp->data);*/
		/*tmp = tmp->next;*/
	/*}*/
	/*tmp = lst2;*/
	/*while (tmp)*/
	/*{*/
		/*printf("lst 2 = %d\n", tmp->data);*/
		/*tmp = tmp->next;*/
	/*}*/
	return (0);
}
