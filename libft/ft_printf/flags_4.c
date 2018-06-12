/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:08:16 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/13 18:43:34 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		flag_period_end(t_printf *ptf, int len_preci)
{
	if (ptf->j < 0)
	{
		ptf->str2[0] = '-';
		ft_memset(&ptf->str2[1], '0', len_preci);
		if (!(ptf->arg = ft_strjoin(ptf->str2, &ptf->tmp[1])))
			return (-1);
	}
	else
	{
		if (!(ptf->arg = ft_strjoin(ptf->str2, ptf->tmp)))
			return (-1);
		else if (ptf->spe_p && ptf->value_arg == 0)
		{
			if (!(ptf->arg = ft_strjoin(ptf->tmp, ptf->str2)))
				return (-1);
		}
	}
	return (1);
}

int				flag_period_int(t_printf *ptf, t_flags *flag)
{
	int len_preci;
	int len_arg;

	len_arg = ft_strlen(ptf->arg);
	if ((ptf->j = ft_atoi(ptf->arg)) < 0)
		len_arg -= 1;
	len_preci = flag->period - len_arg;
	(flag->hashtag) ? (len_preci -= 1) : len_preci;
	if (len_preci <= 0)
		return (0);
	if (ptf->spe_p == 1)
		len_preci = flag->period - 1;
	if (!(ptf->str2 = ft_strnew(len_preci)))
		return (-1);
	ft_memset(ptf->str2, '0', len_preci);
	ptf->tmp = ptf->arg;
	if (flag_period_end(ptf, len_preci) != 1)
		return (-1);
	free(ptf->str2);
	free(ptf->tmp);
	return (1);
}
