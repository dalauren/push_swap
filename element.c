/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:22:21 by dalauren          #+#    #+#             */
/*   Updated: 2018/05/02 13:09:34 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile		*create_elem(int data)
{
	t_pile *new_elem;

	if (!(new_elem = (t_pile *)malloc(sizeof(t_list))))
		return (NULL);
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}

void		lst_push_back(t_pile **begin_list, int data)
{
	t_pile *lst;

	lst = *begin_list;
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = create_elem(data);
	}
	else
		*begin_list = create_elem(data);
}

void		lst_push_front(t_pile **begin_list, int data)
{
	t_pile *lst;

	lst = *begin_list;
	if (*begin_list)
	{
		lst = create_elem(data);
		lst->next = *begin_list;
		*begin_list = lst;
	}
	else
		*begin_list = create_elem(data);
}
