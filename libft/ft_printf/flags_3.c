/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:36:11 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/06 14:12:32 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_mini_field_char(t_printf *ptf, t_flags *flag)
{
	int		space;
	char	*tmp;

	space = flag->numb - ft_strlen(ptf->arg);
	if (space <= 0)
		return (0);
	else
	{
		if (!(ptf->str3 = ft_strnew(space)))
			return (-1);
	}
	ft_memset(ptf->str3, ' ', space);
	tmp = NULL;
	tmp = ptf->arg;
	ptf->arg = (flag->minus) ? ft_strjoin(tmp, ptf->str3) :
		ft_strjoin(ptf->str3, tmp);
	if (ptf->arg == NULL)
		return (-1);
	free(ptf->str3);
	return (1);
}

int		flag_preci_char(t_printf *ptf, t_flags *flag)
{
	if (ptf->arg[0] == '\0')
	{
		flag->period = 0;
		return (0);
	}
	if (flag->period_present && flag->string == 1 && flag->period == 0)
		ptf->len = 0;
	else
		ptf->len = flag->period - ft_strlen(ptf->arg);
	if (!(ptf->str2 = ft_strnew(flag->period + ft_strlen(ptf->arg))))
		return (-1);
	ft_strncpy(ptf->str2, ptf->arg, flag->period);
	ptf->arg = ptf->str2;
	return (1);
}
