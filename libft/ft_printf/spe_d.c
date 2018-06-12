/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:57:46 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/14 14:47:45 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		spe_d_end(t_printf *ptf, t_flags *flag)
{
	if (flag->space && flag->zero)
		flag->zero--;
	ptf->value_arg = ft_atoi(ptf->arg);
	apply_flags(flag, ptf);
	if (!(flag->minus))
		ptf->buff_s = ft_strlen(ptf->str);
	check_buff_size(ptf);
	ft_strcpy(&ptf->str[ptf->buff_s], ptf->arg);
	ptf->buff_s += ft_strlen(ptf->arg);
	if (flag->minus)
		free(ptf->tmp);
	free(ptf->arg);
	ptf->arg = NULL;
}

static int		spe_d_start(t_printf *ptf, t_flags *flag)
{
	return ((ptf->arg_int != 0) || (ptf->uarg_int == 0 && flag->period == 0 &&
				flag->numb == 0 && flag->hashtag == 0 &&
				flag->period_present == 0 && flag->zero_present == 0));
}

int				spe_d(t_printf *ptf, t_flags *flag)
{
	flag->cast_l = (ptf->maj) ? 1 : flag->cast_l;
	ptf->arg_int = cast_signed(ptf, flag);
	if (spe_d_start(ptf, flag))
	{
		if (!(ptf->arg = ft_intmaxtoa(ptf->arg_int)))
			return (-1);
	}
	else if (ptf->arg_int == 0 && flag->zero == 0 && flag->period_present == 0
			&& flag->numb_present)
	{
		if (!(ptf->arg = ft_intmaxtoa(ptf->arg_int)))
			return (-1);
	}
	else if (ptf->arg_int == 0 && flag->numb_present && flag->zero_present)
	{
		if (!(ptf->arg = ft_intmaxtoa(ptf->arg_int)))
			return (-1);
	}
	else
	{
		if (!(ptf->arg = ft_strdup("\0")))
			return (-1);
	}
	spe_d_end(ptf, flag);
	return (ft_strlen(ptf->str));
}
