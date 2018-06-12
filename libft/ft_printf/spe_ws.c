/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_ws.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:33:28 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/14 13:38:23 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		spe_ws_start(t_printf *ptf, t_flags *flag)
{
	ptf->swarg = va_arg(ptf->ap, wchar_t*);
	if (ptf->swarg == NULL || ptf->swarg == '\0')
	{
		if (!(ptf->arg = ft_strdup("(null)")))
			return (-1);
		apply_flags_char(ptf, flag);
	}
	return (1);
}

static int		end_spe_ws(t_printf *ptf)
{
	check_buff_size(ptf);
	ptf->buff_s = ft_strlen(ptf->str);
	ft_strncpy(&ptf->str[ptf->buff_s], ptf->arg, ft_strlen(ptf->arg));
	ptf->buff_s = ft_strlen(ptf->str);
	free(ptf->arg);
	return (1);
}

int				spe_ws(t_printf *ptf, t_flags *flag)
{
	if (spe_ws_start(ptf, flag) == -1)
		return (-1);
	else if (ptf->swarg != NULL)
	{
		ptf->len = ft_strwlen(ptf->swarg);
		if (!(ptf->arg = (char*)malloc(sizeof(char) * (ptf->len * 4) + 1)))
			return (-1);
		while (ptf->swarg[flag->i])
		{
			flag->len = size_uni(ptf->swarg[flag->i]);
			if ((flag->period == 0 && flag->period_present == 1) ||
					(flag->period < flag->len && flag->period_present))
				break ;
			fill_char(ptf->swarg[flag->i++], ptf->arg, &flag->j, flag);
			flag->period -= flag->len;
			if (flag->high_surro == 1)
				return (-1);
		}
		ptf->arg[flag->j] = '\0';
		apply_flag_unicode_wc(ptf, flag);
	}
	if (end_spe_ws(ptf) != 1)
		return (-1);
	return (ptf->buff_s);
}
