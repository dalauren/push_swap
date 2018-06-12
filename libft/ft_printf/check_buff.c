/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:45:11 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/13 18:45:52 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			apply_flags_char(t_printf *ptf, t_flags *flag)
{
	if (ptf->spe_c && flag->zero_present && flag->zero)
	{
		flag->zero--;
		flag_zero(ptf, flag);
	}
	if (flag->period && flag->period_present && ptf->spe_p)
		handle_preci_for_p(ptf, flag);
	else if ((flag->period || flag->period_present) && flag->string)
		flag_preci_char(ptf, flag);
	else
		(flag->period) ? flag_preci_char(ptf, flag) : flag->period;
	if (flag->pc && flag->zero)
		padding_zero_pc(flag, ptf);
	(flag->numb) ? flag_mini_field_char(ptf, flag) : 0;
	(flag->minus) ? flag_minus(ptf, flag) : 0;
}

void			check_buff_size(t_printf *ptf)
{
	if ((ptf->buff_s + ft_strlen(ptf->arg)) > BUFF_SIZE)
	{
		write(1, ptf->str, ptf->buff_s);
		ft_memset(ptf->str, 0, BUFF_SIZE);
		ptf->ret += ptf->buff_s;
		ptf->buff_s = 0;
	}
}
