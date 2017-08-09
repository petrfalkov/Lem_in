/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_dec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:58:53 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/19 13:34:29 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*with_min(t_spec_list *list, char *with_width, char *num, int len)
{
	if (list->flag[2] != 0 || list->flag[1] != 0)
		len++;
	if (list->width > len)
	{
		with_width = ft_strnew((size_t)list->width - len);
		with_width = ft_memset(with_width, ' ', (size_t)list->width - len);
		with_width = ft_strjoin(num, with_width);
		return (with_width);
	}
	return (num);
}

char		*without_min(t_spec_list *list, char *with_width,
		char *num, int len)
{
	if (list->flag[2] == 0 && list->width > len)
	{
		with_width = (list->precission <= 0 && list->flag[4] == 1)
			? (ft_memset(with_width, '0', (size_t)list->width - len))
			: (ft_memset(with_width, ' ', (size_t)list->width - len));
		return (((num[0] == '+' || num[0] == '-') && list->flag[4] == 1
				&& list->precission == 0)
			? (ft_strjoin(ft_strjoin(ft_strsub(num, 0, 1), with_width),
						ft_strsub(num, 1, (size_t)len - 1)))
			: (ft_strjoin(with_width, num)));
	}
	else if (list->width > len)
	{
		with_width = (list->precission <= 0 && list->flag[4] == 1)
			? (ft_memset(with_width, '0', (size_t)list->width - (len + 1)))
			: (ft_memset(with_width, ' ', (size_t)list->width - (len + 1)));
		return (((num[0] == '+' || num[0] == '-') && list->flag[4] == 1)
				? (ft_strjoin(ft_strjoin(ft_strsub(num, 0, 1), with_width),
						ft_strsub(num, 1, (size_t)len - 1)))
				: (ft_strjoin(with_width, num)));
	}
	return (num);
}

char		*act_width(t_spec_list *list, char *num, intmax_t dec)
{
	char	*with_width;
	int		len;

	len = (int)ft_strlen(num);
	with_width = NULL;
	if (((list->type == 'x' || list->type == 'X')
				&& list->flag[4] == 1 && list->flag[3] == 1)
		|| (list->if_p == 1 && list->precission == 0 && list->flag[0] == 1))
		list->width -= 2;
	else if (list->type == 'o' && list->flag[0] == 1 && list->flag[3] == 1)
		list->width--;
	if (list->flag[1] == 1 && list->flag[0] != 1 && dec >= 0)
		len++;
	if (dec < 0)
	{
		list->flag[2] = 0;
		list->flag[1] = 0;
	}
	if (list->width > len)
		with_width = ((list->flag[2] == 0)
				? ft_strnew((size_t)list->width - len)
				: ft_strnew((size_t)list->width - (len + 1)));
	return ((list->flag[0] == 1) ? with_min(list, with_width, num, len)
			: without_min(list, with_width, num, len));
}

char		*check_prec_width(t_spec_list *list, char *num, uintmax_t dec)
{
	if (list->precission != 0)
	{
		list->flag[2] = 0;
		num = num_precis(list->precission, num);
	}
	if (list->precission <= 0 && list->if_prec == 1)
		list->flag[4] = 0;
	if (list->width != 0)
		num = act_width(list, num, dec);
	return (num);
}

char		*dec_ret(t_spec_list *list, intmax_t arg, int base)
{
	intmax_t	dec;
	char		*num;

	dec = ((list->parameter != 0
				&& (list->length == 4 || list->length == 3 || list->length == 6
					|| list->length == 7)) ? (unsigned int)arg : arg);
	if (list->width < 0)
	{
		list->flag[0] = 1;
		list->width *= -1;
	}
	num = ((dec == 0 && list->if_prec == 1) ? "" : ft_itoa_base(dec, base));
	if (list->flag[1] == 1)
		list->flag[2] = 0;
	num = check_prec_width(list, num, (uintmax_t)dec);
	if (list->flag[1] == 1 && dec >= 0)
		num = with_plus(num, dec);
	if (list->flag[2] != 0 && num[0] != '-')
		num = ft_strjoin(" ", num);
	list->n_len = ft_strlen(num);
	return (num);
}
