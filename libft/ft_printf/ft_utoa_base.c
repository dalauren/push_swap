/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:52:13 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/04 14:27:52 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		size_number(uintmax_t nb, int base)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char	*ft_uitoabase(uintmax_t nb, int base, t_printf *ptf)
{
	int		i;
	int		numb;
	char	*str;

	if (base < 2 || base > 16)
		return (NULL);
	i = size_number(nb, base);
	if (!(str = ft_strnew(i)))
		return (NULL);
	i--;
	while (i >= 0)
	{
		numb = nb % base;
		if (numb <= 9)
			str[i] = numb + '0';
		else
			str[i] = (ptf->maj) ? (numb - 10 + 'A') : (numb - 10 + 'a');
		nb /= base;
		i--;
	}
	return (str);
}
