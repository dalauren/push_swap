/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:36:41 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/12 14:37:09 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					flag_plus(t_printf *ptf, t_flags *flag)
{
	(void)flag;
	if (ptf->value_arg >= 0)
	{
		if (!(ptf->str2 = ft_strnew(1)))
			return (-1);
		ft_memset(ptf->str2, '+', 1);
		ptf->tmp = ptf->arg;
		if (!(ptf->arg = ft_strjoin(ptf->str2, ptf->tmp)))
			return (-1);
		free(ptf->tmp);
		free(ptf->str2);
		return (1);
	}
	return (0);
}

int					flag_space(t_printf *ptf, t_flags *flag)
{
	int argu;

	argu = ft_atoi(ptf->arg);
	if (!(flag->plus))
	{
		if (argu >= 0)
			ptf->str[ptf->buff_s] = ' ';
		ptf->buff_s += 1;
		return (1);
	}
	return (0);
}

int					flag_hash(t_printf *ptf)
{
	char *tmp;
	char *str;

	if (ptf->base == 8)
	{
		if (!(str = ft_strdup("0")))
			return (-1);
	}
	if (ptf->base == 16 && ptf->maj == 0)
	{
		if (!(str = ft_strdup("0x")))
			return (-1);
	}
	if (ptf->base == 16 && ptf->maj)
	{
		if (!(str = ft_strdup("0X")))
			return (-1);
	}
	tmp = ptf->arg;
	if (!(ptf->arg = ft_strjoinfree(str, tmp)))
		return (-1);
	return (1);
}

static int			flag_zero_end(t_printf *ptf, int i, char *str)
{
	if (!(str = ft_strnew(i + 1)))
		return (-1);
	ft_memset(str, '0', i);
	ptf->tmp = ptf->arg;
	if (ptf->j < 0)
	{
		str[0] = '-';
		ft_memset(&str[1], '0', i);
		if (!(ptf->arg = ft_strjoin(str, &ptf->tmp[1])))
			return (-1);
		free(str);
	}
	else
	{
		if (!(ptf->arg = ft_strjoinfree(str, ptf->tmp)))
			return (-1);
	}
	return (1);
}

int					flag_zero(t_printf *ptf, t_flags *flag)
{
	int		i;
	char	*str;

	str = NULL;
	if (flag->zero_present && flag->numb && ptf->value_arg != 0)
	{
		flag->zero = flag->numb;
		flag->numb = 0;
	}
	if (flag->minus)
		return (0);
	i = flag->zero - ft_strlen(ptf->arg);
	if (ptf->value_arg >= 0 && flag->plus == 1)
		i--;
	if (i <= 0)
		return (0);
	if (flag->hashtag)
		i -= 2;
	ptf->buff_s = ft_strlen(ptf->str);
	ptf->j = ft_atoi(ptf->arg);
	if (ptf->j == -1)
		ptf->j = 0;
	if (flag_zero_end(ptf, i, str) != 1)
		return (-1);
	return (1);
}
