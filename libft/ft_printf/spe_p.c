/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:14:55 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/04 14:38:06 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		end_spe_p(t_printf *ptf, t_flags *flag)
{
	apply_flags_char(ptf, flag);
	ptf->buff_s = ft_strlen(ptf->str);
	ft_strncpy(&ptf->str[ptf->buff_s], ptf->arg, ft_strlen(ptf->arg));
	ptf->buff_s += ft_strlen(ptf->arg);
	free(ptf->arg);
	return (1);
}

int				spe_p(t_printf *ptf, t_flags *flag)
{
	char	*tmp;

	ptf->spe_p = 1;
	ptf->arg_p = va_arg(ptf->ap, uintmax_t);
	if (ptf->arg_p == 0 && flag->period_present)
	{
		ptf->value_arg = 0;
		if (!(ptf->arg = ft_strdup("0x")))
			return (-1);
		apply_flags_char(ptf, flag);
		ft_strncpy(&ptf->str[ptf->buff_s], ptf->arg, ft_strlen(ptf->arg));
		ptf->buff_s += ft_strlen(ptf->arg);
		free(ptf->arg);
		return (ptf->buff_s);
	}
	if (!(tmp = ft_uitoabase((uintmax_t)ptf->arg_p, 16, ptf)))
		return (-1);
	if (!(ptf->str2 = ft_strdup("0x")))
		return (-1);
	if (!(ptf->arg = ft_strjoinfree(ptf->str2, tmp)))
		return (-1);
	if (end_spe_p(ptf, flag) != 1)
		return (-1);
	return (ptf->buff_s);
}

static int		end_preci_p(t_printf *ptf, char *tmp, char *str)
{
	if (ptf->value_arg == 0)
	{
		if (!(ptf->arg = ft_strjoin(ptf->arg, str)))
			return (-1);
		return (1);
	}
	tmp = ptf->arg;
	if (!(ptf->arg = ft_strjoin(ptf->str2, ptf->arg)))
		return (-1);
	return (1);
}

int				handle_preci_for_p(t_printf *ptf, t_flags *flag)
{
	int		preci;
	char	*str;
	char	*tmp;

	tmp = NULL;
	ptf->len = ft_strlen(ptf->arg);
	preci = flag->period - ptf->len;
	if (!(str = ft_strnew(preci)))
		return (-1);
	if (ptf->value_arg == 0)
		preci = flag->period;
	ft_memset(str, '0', preci);
	if (ptf->value_arg != 0)
	{
		if (!(ptf->str2 = ft_strjoin(ptf->str2, str)))
			return (-1);
	}
	if (end_preci_p(ptf, tmp, str) != 1)
		return (-1);
	free(tmp);
	free(str);
	return (1);
}
