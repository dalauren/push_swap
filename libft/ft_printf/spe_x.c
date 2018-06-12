/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:50:58 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/12 14:21:16 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		spe_x_end(t_printf *ptf, t_flags *flag)
{
	if (!(flag->minus))
		ptf->buff_s = ft_strlen(ptf->str);
	ft_strncpy(&ptf->str[ptf->buff_s], ptf->arg, ft_strlen(ptf->arg));
	ptf->buff_s += ft_strlen(ptf->arg);
	free(ptf->arg);
}

static void		spe_x_start(t_printf *ptf, t_flags *flag)
{
	flag->spe_x = 1;
	ptf->base = 16;
	ptf->uarg_int = cast_unsigned(ptf, flag);
	if (flag->plus || flag->space)
	{
		flag->plus = 0;
		flag->space = 0;
	}
}

int				spe_x(t_printf *ptf, t_flags *flag)
{
	spe_x_start(ptf, flag);
	if (ptf->uarg_int == 0 && flag->period_present == 0)
	{
		flag->hashtag = 0;
		if (!(ptf->arg = ft_strdup("0")))
			return (-1);
		apply_flags(flag, ptf);
	}
	else
	{
		if (ptf->uarg_int != 0 || (ptf->uarg_int == 0 && flag->period == 0 &&
				flag->numb == 0 && flag->hashtag == 0 &&
				flag->period_present == 0))
			ptf->arg = ft_uitoabase(ptf->uarg_int, 16, ptf);
		else
		{
			flag->hashtag = 0;
			if (!(ptf->arg = ft_strdup("\0")))
				return (-1);
		}
		apply_flags(flag, ptf);
		check_buff_size(ptf);
	}
	spe_x_end(ptf, flag);
	return (ft_strlen(ptf->str));
}

int				handle_hash_and_preci_for_x(t_printf *ptf, t_flags *flag)
{
	int		preci;
	char	*tmp;

	preci = flag->period - ft_strlen(ptf->arg);
	if (preci > 0)
	{
		if (!(ptf->str2 = ft_strnew(preci)))
			return (-1);
		ft_memset(ptf->str2, '0', preci);
		tmp = ptf->arg;
		if (!(ptf->arg = ft_strjoinfree(ptf->str2, tmp)))
			return (-1);
	}
	if (flag->hashtag)
		return (flag_hash(ptf));
	return (1);
}
