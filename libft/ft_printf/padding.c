/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:33:40 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/14 14:47:43 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				skip_to_sp(int c)
{
	return ((c != 'd') && (c != '%') && (c != 'i') && (c != 'o') && (c != 'u')
			&& (c != 'x')
			&& (c != 'X') && (c != 'D') && (c != 'O') && (c != 'U')
			&& (c != 'c') &&
			(c != 'C') && (c != 's') && (c != 'S') && (c != 'p'));
}

static void		check_flags_3(char *format, t_printf *ptf, t_flags *flag)
{
	if (format[ptf->i] == '.')
	{
		if (flag->period_present)
			return ;
		flag->period_present = 1;
		ptf->i++;
		flag->period = ft_atoi(&format[ptf->i]);
		while (ft_isdigit(format[ptf->i]))
			ptf->i++;
		ptf->i--;
	}
	if (format[ptf->i] == 'h')
	{
		flag->cast_h = (format[ptf->i + 1] == 'h') ? 2 : 1;
		while (format[ptf->i] == 'h')
			ptf->i++;
		ptf->i--;
	}
	if (format[ptf->i] == 'l')
	{
		flag->cast_l = (format[ptf->i + 1] == 'l') ? 2 : 1;
		while (format[ptf->i] == 'l')
			ptf->i++;
		ptf->i--;
	}
}

static void		check_flags_2(char *format, t_printf *ptf, t_flags *flag)
{
	flag->hashtag = (format[ptf->i] == '#') ? 1 : flag->hashtag;
	flag->plus = (format[ptf->i] == '+') ? 1 : flag->plus;
	flag->space = (format[ptf->i] == ' ') ? 1 : flag->space;
	flag->minus = (format[ptf->i] == '-') ? 1 : flag->minus;
	flag->cast_z = (format[ptf->i] == 'z') ? 1 : flag->cast_z;
	flag->cast_j = (format[ptf->i] == 'j') ? 1 : flag->cast_j;
	if (format[ptf->i] == '0')
	{
		flag->zero_present = 1;
		flag->zero = ft_atoi(&format[ptf->i]);
		if (format[ptf->i + 1] == '0')
		{
			flag->numb = flag->zero;
			flag->zero_present = 0;
			flag->numb_present = 1;
		}
		while (ft_isdigit(format[ptf->i]))
			ptf->i++;
		if (flag->numb_present == 0)
			ptf->i--;
	}
}

void			check_flags(char *format, t_printf *ptf, t_flags *flag)
{
	ptf->i++;
	while (skip_to_sp(format[ptf->i]) && format[ptf->i])
	{
		if (format[ptf->i] == '*')
			return ;
		check_flags_2(format, ptf, flag);
		if (ft_isdigit(format[ptf->i]))
		{
			flag->numb_present = 1;
			if (ft_isdigit(format[ptf->i - 1]))
				ptf->i++;
			flag->numb = ft_atoi(&format[ptf->i]);
			while (ft_isdigit(format[ptf->i]))
				ptf->i++;
			ptf->i--;
		}
		check_flags_3(format, ptf, flag);
		ptf->i++;
	}
}

void			apply_flags(t_flags *flag, t_printf *ptf)
{
	if (flag->space && flag->plus != 1)
		flag_space(ptf, flag);
	if ((flag->period && flag->zero) || (flag->minus && flag->zero))
	{
		flag->numb = flag->zero;
		flag->zero_present = 0;
		flag->zero = 0;
	}
	if (flag->zero_present)
		flag_zero(ptf, flag);
	if (flag->spe_x && flag->hashtag && flag->period && flag->period_present)
		handle_hash_and_preci_for_x(ptf, flag);
	else
	{
		(flag->period) ? flag_period_int(ptf, flag) : 0;
		(flag->hashtag) ? flag_hash(ptf) : 0;
	}
	(flag->numb) ? flag_mini_field_int(ptf, flag) : 0;
	(flag->plus) ? flag_plus(ptf, flag) : 0;
	(flag->minus) ? flag_minus(ptf, flag) : 0;
}
