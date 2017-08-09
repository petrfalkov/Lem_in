/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:16:28 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/23 15:16:29 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	get_x(t_spec_list *list, va_list v_lst)
{
	if (list->length == 4)
		return (va_arg(v_lst, unsigned long long));
	else if (list->length == 1)
		return (unsigned char)(va_arg(v_lst, uintmax_t));
	else if (list->length == 3)
		return (va_arg(v_lst, unsigned long));
	else if (list->length == 2)
		return (unsigned short)(va_arg(v_lst, uintmax_t));
	else if (list->length == 7)
		return (va_arg(v_lst, size_t));
	else if (list->length == 6)
		return (va_arg(v_lst, uintmax_t));
	else
		return (va_arg(v_lst, unsigned int));
}

intmax_t	get_dec(t_spec_list *list, va_list v_lst)
{
	if (list->length == 4)
		return (va_arg(v_lst, long
					long));
	else if (list->length == 1)
		return (char)(va_arg(v_lst, int));
	else if (list->length == 3)
		return (va_arg(v_lst, long));
	else if (list->length == 2)
		return (short)(va_arg(v_lst, int));
	else if (list->length == 7)
		return (va_arg(v_lst, size_t));
	else if (list->length == 6)
		return (va_arg(v_lst, intmax_t));
	else
		return (va_arg(v_lst, int));
}

char		*heks_ret(t_spec_list *list, uintmax_t arg, unsigned int base)
{
	uintmax_t	dec;
	char		*num;

	if (list->parameter != 0 && (list->length == 4 || list->length == 3
				|| list->length == 6 || list->length == 7))
		dec = (unsigned int)arg;
	else
		dec = arg;
	if (list->width < 0)
	{
		list->flag[0] = 1;
		list->width *= -1;
	}
	if ((dec == 0 && ((list->if_prec == 1 && list->flag[3] == 0)
					|| (list->if_prec == 1 && list->type != 'o'))))
		num = "";
	else
		num = ft_itoa_base_hex(dec, base);
	num = check_prec_width(list, num, dec);
	list->n_len = ft_strlen(num);
	return (num);
}

char		*oct_ret(t_spec_list *list, uintmax_t arg, unsigned int base)
{
	uintmax_t	dec;
	char		*num;

	if (list->parameter != 0 && (list->length == 4 || list->length == 3
				|| list->length == 6 || list->length == 7))
		dec = (unsigned int)arg;
	else
		dec = arg;
	if (list->width < 0)
	{
		list->flag[0] = 1;
		list->width *= -1;
	}
	if ((dec == 0 && ((list->if_prec == 1 && list->flag[3] == 0)
					|| (list->if_prec == 1 && list->type != 'o'))))
		num = "";
	else if (list->length != 1)
		num = ft_itoa_base_hex(dec, base);
	else if (list->type != 'O' && list->length == 1)
		num = ft_itoa_base((unsigned char)dec, base);
	else
		num = ft_itoa_base((unsigned short)dec, base);
	num = check_prec_width(list, num, dec);
	list->n_len = ft_strlen(num);
	return (num);
}

char		*unsigned_ret(t_spec_list *list, uintmax_t arg, unsigned int base)
{
	uintmax_t	dec;
	char		*num;

	list->flag[2] = 0;
	if (list->parameter != 0 && (list->length == 4 || list->length == 3
				|| list->length == 6 || list->length == 7))
		dec = (unsigned int)arg;
	else
		dec = arg;
	if (list->width < 0)
	{
		list->flag[0] = 1;
		list->width *= -1;
	}
	if (dec == 0 && list->if_prec == 1)
		num = "";
	else
		num = ft_itoa_base_hex(dec, base);
	if (list->flag[1] == 1)
		list->flag[2] = 0;
	num = check_prec_width(list, num, dec);
	list->n_len = ft_strlen(num);
	return (num);
}
