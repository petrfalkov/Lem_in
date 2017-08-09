/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_char_t.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:26:46 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/19 12:07:08 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BIT7 127
#define BIT11 2047
#define BIT16 65535
#define BIT21 2097151
#define BIT26 67108863
#define BIT31 2147483647

void	ft_addition(const uint32_t symbol, char *wc)
{
	if (symbol <= BIT21)
	{
		wc[0] = ((symbol & 1835008) >> 18) | 240;
		wc[1] = ((symbol & 258048) >> 12) | 128;
		wc[2] = ((symbol & 4032) >> 6) | 128;
		wc[3] = (symbol & 63) | 128;
	}
	else if (symbol <= BIT26)
	{
		wc[0] = ((symbol & 50331648) >> 24) | 248;
		wc[1] = ((symbol & 16515072) >> 18) | 128;
		wc[2] = ((symbol & 258048) >> 12) | 128;
		wc[3] = ((symbol & 4032) >> 6) | 128;
		wc[4] = (symbol & 63) | 128;
	}
	else if (symbol <= BIT31)
	{
		wc[0] = ((symbol & 1073741824) >> 30) | 252;
		wc[1] = ((symbol & 1056964608) >> 24) | 128;
		wc[2] = ((symbol & 16515072) >> 18) | 128;
		wc[3] = ((symbol & 258048) >> 12) | 128;
		wc[4] = ((symbol & 4032) >> 6) | 128;
		wc[5] = (symbol & 63) | 128;
	}
}

char	*ft_get_wchar(wchar_t symbol)
{
	char	*wc;

	wc = ft_strnew(6);
	if (symbol <= BIT7)
		wc[0] = symbol;
	else if (symbol <= BIT11)
	{
		wc[0] = ((symbol & 1984) >> 6) | 192;
		wc[1] = (symbol & 63) | 128;
	}
	else if (symbol <= BIT16)
	{
		wc[0] = ((symbol & 61440) >> 12) | 224;
		wc[1] = ((symbol & 4032) >> 6) | 128;
		wc[2] = (symbol & 63) | 128;
	}
	else
		ft_addition(symbol, wc);
	return (wc);
}

void	w_char_ret(t_spec_list *list, char *wch, t_param_list *param)
{
	if (wch[0] == '\0')
	{
		write(1, "", 1);
		param->count_bytes++;
	}
	else
	{
		if (list->width < 0)
		{
			list->flag[0] = 1;
			list->width *= -1;
		}
		if (list->width > 0)
			wch = ft_ret_str_width(wch, list);
		list->n_len = ft_strlen(wch);
		ft_putstr(wch);
	}
}
