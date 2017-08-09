/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:52:53 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/19 12:23:42 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_for_prec(t_spec_list *list)
{
	if (list->precission < 0 && !(list->type == 's' || list->type == 'c'))
	{
		if (list->width < list->precission)
		{
			list->width = list->precission * -1;
			list->flag[0] = 1;
			list->flag[2] = 0;
		}
		list->precission = 0;
	}
}

void	nothing_ret(t_param_list *param, size_t z)
{
	z = 0;
	*param->link = param->count_bytes;
}

void	out_arg(t_spec_list *list, va_list v_lst, t_for_chk_l *fcl,
				t_param_list *param)
{
	check_for_prec(list);
	if (list->type == 'd' || list->type == 'i' || list->type == 'D')
		ft_putstr(dec_ret(list, get_dec(list, v_lst), 10));
	else if (list->type == 'u' || list->type == 'U')
		ft_putstr(unsigned_ret(list, get_u(list, v_lst), 10));
	else if (list->type == 'x' || list->type == 'X')
		ft_putstr(hex_ret(list, get_x(list, v_lst), 16));
	else if (list->type == 'o' || list->type == 'O')
		ft_putstr(
				octal_ret(list, oct_ret(list, get_o(list, v_lst), 8), param));
	else if (list->type == 's')
		str_ret(list, get_str_arg(list, v_lst), fcl);
	else if (list->type == 'c' && list->length != 3)
		ch_ret(list, (unsigned char)get_ch_arg(v_lst), param);
	else if (list->type == 'c' && list->length == 3)
		w_char_ret(list, get_wchar_arg(v_lst), param);
	else if (list->type == 'n')
		nothing_ret(param, (size_t)get_arg_type(list, v_lst, param));
	else if (list->type == 'p')
		ft_putstr(hex_ret(list, get_arg_type(list, v_lst, param), 16));
	else if (list->type >= 32 && list->type <= 126)
		ch_ret(list, (unsigned char)list->type, param);
}
