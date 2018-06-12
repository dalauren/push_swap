/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:37:02 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/06 14:20:27 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				flag_mini_field_int(t_printf *ptf, t_flags *flag)
{
	if (flag->zero_present && flag->zero && ptf->value_arg != 0)
	{
		flag->zero = flag->numb;
		flag_zero(ptf, flag);
		flag->numb = 0;
	}
	ptf->len = ft_strlen(ptf->arg);
	if (flag->numb <= flag->period)
		return (0);
	if ((ptf->value_arg >= 0) && (flag->plus || flag->space))
		ptf->len++;
	ptf->pos_start = ptf->buff_s;
	while (flag->numb > ptf->len)
	{
		ptf->str[ptf->buff_s] = ' ';
		ptf->buff_s += 1;
		flag->numb--;
	}
	ptf->end_space = ptf->buff_s;
	return (1);
}

int				flag_minus(t_printf *ptf, t_flags *flag)
{
	char	*tmp;

	(void)flag;
	if (!(ptf->str2 = ft_strsub(ptf->str, ptf->pos_start, ptf->end_space)))
		return (-1);
	ptf->buff_s = ptf->pos_start;
	tmp = ptf->arg;
	if (!(ptf->arg = ft_strjoin(tmp, ptf->str2)))
		return (-1);
	free(ptf->str2);
	if (tmp)
		free(tmp);
	return (0);
}

intmax_t		cast_signed(t_printf *ptf, t_flags *flag)
{
	if (flag->cast_j)
		return (va_arg(ptf->ap, intmax_t));
	if (flag->cast_l == 1)
		return ((long)va_arg(ptf->ap, intmax_t));
	if (flag->cast_l == 2)
		return ((long long)va_arg(ptf->ap, intmax_t));
	if (flag->cast_h == 1)
		return ((short)va_arg(ptf->ap, int));
	if (flag->cast_h == 2)
		return ((char)va_arg(ptf->ap, int));
	if (flag->cast_z)
		return (va_arg(ptf->ap, uintmax_t));
	return ((int)va_arg(ptf->ap, int));
}

uintmax_t		cast_unsigned(t_printf *ptf, t_flags *flag)
{
	if (flag->cast_j)
		return (va_arg(ptf->ap, uintmax_t));
	if (flag->cast_l == 1)
		return ((unsigned long)va_arg(ptf->ap, unsigned long int));
	if (flag->cast_h == 1)
		return (unsigned short)va_arg(ptf->ap, unsigned int);
	if (flag->cast_h == 2)
		return ((unsigned char)va_arg(ptf->ap, unsigned int));
	if (flag->cast_l == 2)
		return ((unsigned long long)va_arg(ptf->ap, unsigned long long int));
	if (flag->cast_z)
		return (va_arg(ptf->ap, uintmax_t));
	return ((unsigned int)va_arg(ptf->ap, unsigned int));
}
