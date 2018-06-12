/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:40:33 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/06 13:51:11 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_conv			g_array_struct[] =
{
	{'s', &spe_s},
	{'S', &spe_ws},
	{'c', &spe_c},
	{'C', &spe_wc},
	{'i', &spe_d},
	{'d', &spe_d},
	{'D', &spe_d},
	{'%', &spe_pc},
	{'u', &spe_u},
	{'U', &spe_u},
	{'o', &spe_o},
	{'O', &spe_o},
	{'x', &spe_x},
	{'X', &spe_x},
	{'p', &spe_p},
	{0, NULL}
};

int							exec_sp(char *tmp_format, t_printf *ptf)
{
	int			j;
	t_flags		flag;

	ptf->maj = 0;
	j = 0;
	ft_memset(&flag, 0, sizeof(t_flags));
	check_flags(tmp_format, ptf, &flag);
	if (tmp_format[ptf->i] == 'O' || tmp_format[ptf->i] == 'X' ||
			tmp_format[ptf->i] == 'D' || tmp_format[ptf->i] == 'U')
		ptf->maj = 1;
	while (g_array_struct[j].sp != 0)
	{
		if (g_array_struct[j].sp == tmp_format[ptf->i])
		{
			if ((g_array_struct[j].f(ptf, &flag)) == -1)
				return (-1);
		}
		j++;
		ptf->previous = ptf->i + 1;
	}
	ptf->maj = 0;
	return (ptf->buff_s);
}

static void					end_of_format(char *tmp_format, t_printf *ptf)
{
	ptf->next = ptf->i;
	ft_strncpy(&ptf->str[ptf->buff_s],
			&tmp_format[ptf->previous], ptf->next);
	ptf->buff_s += ptf->i - ptf->previous;
	if (ft_strlen(ptf->str) == 1 && ptf->flag == 0)
		ptf->buff_s = 1;
	ft_putnstr(ptf->str, ptf->buff_s);
}

int							before_padding(char *format, t_printf *ptf)
{
	char *tmp_format;

	tmp_format = format;
	while (tmp_format[ptf->i])
	{
		if (tmp_format[ptf->i] == '%')
		{
			ft_bzero(&(ptf->i2),
				(size_t)((char*)&(ptf->maj) - (sizeof(ptf->maj) - 1)
					- (char*)&ptf->i2));
			ptf->next = ptf->i;
			ft_strncpy(&ptf->str[ptf->buff_s], &tmp_format[ptf->previous],
					ptf->next - ptf->previous);
			ptf->buff_s += (ptf->i - ptf->previous);
			if ((exec_sp(tmp_format, ptf)) == -1)
				return (-1);
		}
		ptf->i++;
	}
	if (tmp_format[ptf->i] == '\0')
		end_of_format(tmp_format, ptf);
	return (ptf->buff_s);
}

int							ft_printf(const char *format, ...)
{
	t_printf	ptf;

	ft_bzero(&(ptf.spe_c),
			(size_t)((char*)&(ptf.maj) - (sizeof(ptf.maj) - 1) -
				(char*)&ptf.spe_c));
	ft_bzero(&ptf.str, sizeof(ptf.str));
	if (format)
	{
		va_start(ptf.ap, format);
		if ((ptf.ret = before_padding((char*)format, &ptf)) == -1)
			return (-1);
		va_end(ptf.ap);
	}
	return (ptf.ret);
}
