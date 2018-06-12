/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_d2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:46:18 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/14 11:54:26 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				spe_u(t_printf *ptf, t_flags *flag)
{
	if (ptf->maj)
		flag->cast_l = 1;
	ptf->uarg_int = cast_unsigned(ptf, flag);
	if (ptf->uarg_int == 0 && flag->period == 0 && flag->period_present)
		return (0);
	if (flag->space || flag->plus)
	{
		flag->space = 0;
		flag->plus = 0;
	}
	if (!(ptf->arg = ft_uintmaxtoa(ptf->uarg_int)))
		return (-1);
	ptf->value_arg = ft_atoi(ptf->arg);
	apply_flags(flag, ptf);
	check_buff_size(ptf);
	if (!(flag->minus))
		ptf->buff_s = ft_strlen(ptf->str);
	ft_strncpy(&ptf->str[ptf->buff_s], ptf->arg, ft_strlen(ptf->arg));
	ptf->buff_s += ft_strlen(ptf->arg);
	free(ptf->arg);
	return (ft_strlen(ptf->str));
}

static int		spe_o_end(t_printf *ptf, t_flags *flag)
{
	check_buff_size(ptf);
	if (!(flag->minus))
		ptf->buff_s = ft_strlen(ptf->str);
	ft_strncpy(&ptf->str[ptf->buff_s], ptf->arg, ft_strlen(ptf->arg));
	ptf->buff_s += ft_strlen(ptf->arg);
	free(ptf->arg);
	return (1);
}

static void		spe_o_start(t_printf *ptf, t_flags *flag)
{
	if (ptf->maj)
		flag->cast_l = 1;
	if (flag->space || flag->plus)
	{
		flag->space = 0;
		flag->plus = 0;
	}
	ptf->base = 8;
}

int				spe_o(t_printf *ptf, t_flags *flag)
{
	spe_o_start(ptf, flag);
	ptf->uarg_int = cast_unsigned(ptf, flag);
	if (ptf->uarg_int != 0 || (ptf->uarg_int == 0 && flag->period == 0 &&
				flag->numb == 0 && flag->hashtag == 0 &&
				flag->period_present == 0))
	{
		if (!(ptf->arg = ft_uitoabase(ptf->uarg_int, 8, ptf)))
			return (-1);
	}
	else if (ptf->arg_int == 0 && flag->zero == 0 && flag->period_present == 0
			&& flag->numb_present)
	{
		if (!(ptf->arg = ft_intmaxtoa(ptf->arg_int)))
			return (-1);
	}
	else
	{
		if (!(ptf->arg = ft_strdup("\0")))
			return (-1);
	}
	apply_flags(flag, ptf);
	if (spe_o_end(ptf, flag) != 1)
		return (-1);
	return (ft_strlen(ptf->str));
}
