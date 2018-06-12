/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:40:53 by dalauren          #+#    #+#             */
/*   Updated: 2018/06/03 17:47:30 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

# define BUFF_SIZE 1500

typedef struct		s_printf
{
	char			str[BUFF_SIZE];
	int				spe_c;
	int				buff_s;
	int				size;
	int				j;
	char			*skip;
	int				previous;
	int				next;
	int				i;
	va_list			ap;
	int				ret;
	int				i2;
	int				printed;
	int				flag;
	char			*str3;
	uintmax_t		arg_p;
	int				spe_p;
	int				value_arg;
	intmax_t		arg_int;
	uintmax_t		uarg_int;
	int				len;
	wint_t			warg;
	wchar_t			*swarg;
	char			car;
	char			*str2;
	char			*arg;
	char			*tmp;
	int				base;
	int				end_space;
	int				pos_start;
	int				maj;
}					t_printf;

typedef struct		s_flags
{
	int				i;
	int				len;
	int				j;
	int				pc;
	int				octet;
	int				high_surro;
	int				flag_null;
	int				spe_x;
	int				preci_unicode;
	int				string;
	int				numb_present;
	int				period_present;
	int				zero_present;
	int				first_time;
	int				hashtag;
	int				plus;
	int				minus;
	int				space;
	int				zero;
	int				numb;
	int				period;
	int				cast_j;
	int				cast_h;
	int				cast_l;
	int				cast_z;
}					t_flags;

typedef struct		s_conv
{
	char			sp;
	int				(*f)(t_printf *ptf, t_flags *flag);
}					t_conv;

int					ft_printf(const char *format, ...);
int					spe_s(t_printf *ptf, t_flags *flag);
int					spe_c(t_printf *ptf, t_flags *flag);
int					spe_d(t_printf *ptf, t_flags *flag);
int					spe_pc(t_printf *ptf, t_flags *flag);
int					spe_u(t_printf *ptf, t_flags *flag);
int					spe_o(t_printf *ptf, t_flags *flag);
int					spe_x(t_printf *ptf, t_flags *flag);
int					spe_p(t_printf *ptf, t_flags *flag);
int					spe_wc(t_printf *ptf, t_flags *flag);
int					spe_ws(t_printf *ptf, t_flags *flag);
void				check_flags(char *format, t_printf *ptf, t_flags *flag);
void				apply_flags(t_flags *flag, t_printf *ptf);
void				apply_flags_char(t_printf *ptf, t_flags *flag);
void				apply_flag_unicode_wc(t_printf *ptf, t_flags *flag);
int					skip_to_sp(int c);
int					flag_plus(t_printf *ptf, t_flags *flag);
int					flag_space(t_printf *ptf, t_flags *flag);
int					flag_hash(t_printf *ptf);
int					flag_zero(t_printf *ptf, t_flags *flag);
int					flag_period_int(t_printf *ptf, t_flags *flag);
int					flag_mini_field_int(t_printf *ptf, t_flags *flag);
int					flag_minus(t_printf *ptf, t_flags *flag);
int					flag_preci_char(t_printf *ptf, t_flags *flag);
int					flag_mini_field_char(t_printf *ptf, t_flags *flag);
intmax_t			cast_signed(t_printf *ptf, t_flags *flag);
uintmax_t			cast_unsigned(t_printf *ptf, t_flags *flag);
void				check_buff_size(t_printf *ptf);
char				*ft_uitoabase(uintmax_t nb, int base, t_printf *ptf);
char				*ft_wchar_to_char(wchar_t chr);
void				fill_char(wchar_t chr, char *ret, int *i, t_flags *flag);
char				*fill_arg(t_printf *ptf);
int					handle_preci_for_p(t_printf *ptf, t_flags *flag);
int					handle_hash_and_preci_for_x(t_printf *ptf, t_flags *flag);
int					size_uni(wchar_t chr);
int					padding_zero_pc(t_flags *flag, t_printf *ptf);

#endif
