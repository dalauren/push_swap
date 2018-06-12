/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:53:03 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/06 14:18:36 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				spe_s(t_printf *ptf, t_flags *flag)
{
	flag->string = 1;
	flag->flag_null = 0;
	if (flag->cast_l == 1)
		return (spe_ws(ptf, flag));
	if (!(ptf->arg = va_arg(ptf->ap, char *)))
	{
		flag->flag_null = 1;
		if (!(ptf->arg = ft_strdup("(null)")))
			return (-1);
	}
	apply_flags_char(ptf, flag);
	ptf->buff_s = ft_strlen(ptf->str);
	check_buff_size(ptf);
	ft_strncpy(&ptf->str[ptf->buff_s], ptf->arg, ft_strlen(ptf->arg));
	ptf->buff_s += ft_strlen(ptf->arg);
	free(ptf->arg);
	return (ft_strlen(ptf->str));
}

static int		end_spe_c(t_printf *ptf, t_flags *flag, int zero, char *str)
{
	ptf->arg = str;
	apply_flags_char(ptf, flag);
	check_buff_size(ptf);
	ptf->buff_s = ft_strlen(ptf->str);
	if (ptf->arg[0] != '\0')
	{
		ptf->len = ft_strlen(ptf->arg);
		if (zero == 1)
			ptf->len += 1;
	}
	ft_strncpy(&ptf->str[ptf->buff_s], ptf->arg, ptf->len);
	ptf->buff_s += ptf->len;
	return (1);
}

int				spe_c(t_printf *ptf, t_flags *flag)
{
	char	*str;
	int		zero;

	zero = 0;
	ptf->spe_c = 1;
	if (flag->cast_l == 1)
		return (spe_wc(ptf, flag));
	if (!(str = ft_strnew(1)))
		return (-1);
	str[0] = va_arg(ptf->ap, int);
	if (str[0] == '\0')
	{
		ptf->flag = 1;
		flag->numb--;
		zero = 1;
		ptf->len = 1;
	}
	if (end_spe_c(ptf, flag, zero, str) != 1)
		return (-1);
	return (ptf->buff_s);
}

int				padding_zero_pc(t_flags *flag, t_printf *ptf)
{
	char *str;
	char *tmp;

	if (flag->minus)
	{
		flag->numb = flag->zero;
		flag->zero = 0;
		return (1);
	}
	if (!(str = ft_strnew(flag->zero - ft_strlen(ptf->arg))))
		return (-1);
	ft_memset(str, '0', flag->zero - ft_strlen(ptf->arg));
	tmp = ptf->arg;
	if (!(ptf->arg = ft_strjoin(str, tmp)))
		return (-1);
	free(str);
	return (1);
}

int				spe_pc(t_printf *ptf, t_flags *flag)
{
	char *str;

	flag->pc = 1;
	if (!(str = ft_strdup("%")))
		return (-1);
	ptf->arg = str;
	apply_flags_char(ptf, flag);
	ptf->buff_s = ft_strlen(ptf->str);
	check_buff_size(ptf);
	ft_strncpy(&ptf->str[ptf->buff_s], ptf->arg, ft_strlen(ptf->arg));
	ptf->buff_s = ft_strlen(ptf->str);
	free(str);
	return (ptf->buff_s);
}
