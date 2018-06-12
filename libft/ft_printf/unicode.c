/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:53:28 by dalauren          #+#    #+#             */
/*   Updated: 2018/03/13 16:12:11 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fill_char(wchar_t chr, char *ret, int *i, t_flags *flag)
{
	if (chr <= 0x7F)
		ret[(*i)++] = chr;
	else if (chr <= 0x7FF)
	{
		ret[(*i)++] = ((chr >> 6) & 31) + 0xC0;
		ret[(*i)++] = (chr & 0x3F) + 0x80;
	}
	else if (chr <= 0xFFFF)
	{
		if (chr >= 0xd800 && chr <= 0xdb7f)
			flag->high_surro = 1;
		ret[(*i)++] = ((chr >> 12) & 15) + 0xE0;
		ret[(*i)++] = ((chr >> 6) & 0x3F) + 0x80;
		ret[(*i)++] = (chr & 0x3F) + 0x80;
	}
	else if (chr <= 0x10FFFF)
	{
		ret[(*i)++] = ((chr >> 18) & 7) + 0xF0;
		ret[(*i)++] = ((chr >> 12) & 0x3F) + 0x80;
		ret[(*i)++] = ((chr >> 6) & 0x3F) + 0x80;
		ret[(*i)++] = (chr & 0x3F) + 0x80;
	}
}

int				size_uni(wchar_t chr)
{
	int		size;

	size = 0;
	if (chr <= 0x7F)
		size = 1;
	else if (chr <= 0x7FF)
		size = 2;
	else if (chr <= 0xFFFF)
		size = 3;
	else if (chr <= 0x10FFFF)
		size = 4;
	return (size);
}
