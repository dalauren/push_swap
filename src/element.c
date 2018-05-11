/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:22:21 by dalauren          #+#    #+#             */
/*   Updated: 2018/05/11 16:24:25 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile		*create_elem(int data, int nb)
{
	t_pile *new_elem;

	if (!(new_elem = (t_pile *)malloc(sizeof(t_list))))
		return (NULL);
	new_elem->data = data;
	new_elem->nb = nb;
	new_elem->next = NULL;
	return (new_elem);
}

void		lst_push_back(t_pile **begin_list, int data, int nb)
{
	t_pile *lst;

	lst = *begin_list;
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = create_elem(data, nb);
	}
	else
		*begin_list = create_elem(data, nb);
}

void		lst_push_front(t_pile **begin_list, int data, int nb)
{
	t_pile *lst;

	lst = *begin_list;
	if (*begin_list)
	{
		lst = create_elem(data, nb);
		lst->next = *begin_list;
		*begin_list = lst;
	}
	else
		*begin_list = create_elem(data, nb);
}

int			find_mediane_lst(t_pile *a)
{
	t_mediane med;

	ft_bzero(&med, sizeof(t_mediane));
	med.tmp = a;
	while (med.tmp)
	{
		med.mediane = med.tmp->data;
		med.tmp2 = a;
		while (med.tmp2)
		{
			if (med.tmp2->data > med.mediane)
				med.nb_up++;
			else if (med.tmp2->data < med.mediane)
				med.nb_down++;
			med.tmp2 = med.tmp2->next;
		}
		if ((ABS(med.nb_up - med.nb_down)) >= 0 &&
				(ABS(med.nb_up - med.nb_down)) <= 1)
			return (med.mediane);
		else
			med.tmp = med.tmp->next;
		med.nb_up = 0;
		med.nb_down = 0;
	}
	return (med.mediane);
}

int		lst_size(t_pile *begin_list)
{
	int		i;
	t_pile	*tmp;

	i = 0;
	tmp = begin_list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
