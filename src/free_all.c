/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:02:12 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/06 09:41:58 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			free_move_list(t_move_list *move_list)
{
	int i;

	i = 0;
	while (i < 11)
	{
		free(move_list[i].str);
		i++;
	}
	free(move_list);
}

void			free_list(t_pile *a)
{
	t_pile *robin;
	t_pile *batman;

	batman = a;
	while (batman)
	{
		robin = batman->next;
		free(batman);
		batman = robin;
	}
	a = NULL;
}

void			free_stack(t_stack *s)
{
	free_list(s->a);
	free_list(s->b);
}
