/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_C.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:04:52 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/14 14:11:38 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			apply_flag_unicode_wc(t_printf *ptf, t_flags *flag)
{
	(flag->numb) ? flag_mini_field_char(ptf, flag) : 0;
	(flag->minus) ? flag_minus(ptf, flag) : 0;
}

static void		fill_str(t_printf *ptf, int zero)
{
	if (ptf->arg[0] != '\0')
	{
		ptf->len = ft_strlen(ptf->arg);
		if (zero == 1)
			ptf->len += 1;
	}
	ft_strncpy(&ptf->str[ptf->buff_s], ptf->arg, ptf->len);
	ptf->buff_s += ptf->len;
	free(ptf->arg);
}

int				spe_wc(t_printf *ptf, t_flags *flag)
{
	int i;
	int zero;

	zero = 0;
	if (((i = 0) == 0) && flag->space)
		flag->space = 0;
	ptf->warg = va_arg(ptf->ap, wint_t);
	if (ptf->warg < 0)
		return (-1);
	if (!(ptf->arg = ft_strnew(4)))
		return (-1);
	fill_char(ptf->warg, ptf->arg, &i, flag);
	if (flag->high_surro == 1)
		return (-1);
	if (ptf->arg[0] == '\0')
	{
		zero = 1;
		ptf->len = 1;
	}
	apply_flag_unicode_wc(ptf, flag);
	check_buff_size(ptf);
	fill_str(ptf, zero);
	return (ptf->buff_s);
}
