/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:58:59 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/19 13:14:29 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	char_ret(t_spec_list *list, unsigned char ch,
						char *n_str)
{
	if (ch < 32)
	{
		if (list->flag[0] != 1)
		{
			ft_putstr(n_str);
			write(1, "", 1);
		}
		else
		{
			write(1, "", 1);
			ft_putstr(n_str);
		}
		list->n_len = ft_strlen(n_str);
	}
	else
	{
		list->n_len = ft_strlen(n_str);
		ft_putstr(n_str);
	}
}

void		ch_ret(t_spec_list *list, unsigned char ch, t_param_list *param)
{
	char	*n_str;

	if (ch < 32)
	{
		n_str = "";
		param->count_bytes++;
		if (ch < 32 && list->width > 0)
			list->width--;
		else if (ch < 32 && list->width < 0)
			list->width++;
	}
	else
		n_str = ft_memset(ft_strnew(1), ch, 1);
	if (list->width < 0)
	{
		list->flag[0] = 1;
		list->width *= -1;
	}
	if (list->width > 0)
		n_str = ft_ret_str_width(n_str, list);
	char_ret(list, ch, n_str);
}

void		*for_hex(t_spec_list *list, char *num, uintmax_t dec)
{
	int		i;
	size_t	len;

	i = 0;
	if ((list->flag[3] == 1 && dec != 0)
		|| (list->width != 0 && list->if_p == 1))
	{
		if (!ft_isdigit(num[i]))
		{
			while (num[i] && !(ft_isdigit(num[i]) ||
						(num[i] >= 65 && num[i] <= 70)))
				i++;
			i--;
			num = ft_memset(num + i, 'x', 1);
			num = ft_strjoin("0", num);
			len = ft_strlen(num);
			while (list->width-- > (int)len)
				num = ft_strjoin(" ", num);
		}
		else
			num = ft_strjoin("0x", num);
	}
	else if (list->flag[3] == 1 && list->if_p == 1)
		num = ft_strjoin("0x", num);
	return (num);
}

void		*hex_ret(t_spec_list *list, uintmax_t num, int base)
{
	char	*hex;
	int		i;
	char	ch;

	i = 0;
	hex = heks_ret(list, num, (unsigned int)base);
	hex = for_hex(list, hex, num);
	if (list->type == 'x')
	{
		while (hex[i])
		{
			ch = (char)ft_tolower(hex[i]);
			hex[i++] = ch;
		}
	}
	else
	{
		while (hex[i])
		{
			ch = (char)ft_toupper(hex[i]);
			hex[i++] = ch;
		}
	}
	list->n_len = ft_strlen(hex);
	return (hex);
}
