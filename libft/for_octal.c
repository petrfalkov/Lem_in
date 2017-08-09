/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_octal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:15:35 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/19 12:18:06 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*octal_check(t_spec_list *lst, t_param_list *param, char *num)
{
	int i;

	i = 0;
	if (!ft_isdigit(num[i]))
	{
		while (num[i] && !ft_isdigit(num[i]))
			i++;
		num = ft_memset(num + i - 1, '0', 1);
		while (lst->width-- > (int)ft_strlen(num))
			num = ft_strjoin(" ", num);
		return (num);
	}
	else if (ft_strlen(num) != 1 && num[0] != '0')
	{
		param->count_bytes++;
		return (ft_strjoin("0", num));
	}
	return (num);
}

char		*octal_ret(t_spec_list *lst, char *num, t_param_list *param)
{
	if ((lst->flag[3] == 1 && lst->flag[0] == 1)
		|| (lst->type == 'O' && lst->flag[3] == 1))
	{
		param->count_bytes++;
		return (ft_strjoin("0", num));
	}
	else if (lst->flag[3] == 1 && lst->flag[4] == 0
			&& lst->flag[0] == 0 && lst->type != 'O')
		return (octal_check(lst, param, num));
	return (num);
}

uintmax_t	get_o(t_spec_list *list, va_list v_lst)
{
	if (list->length == 4 || (list->type == 'O' && list->length != 1))
		return (va_arg(v_lst, unsigned long long));
	else if (list->length == 1 && list->type != 'O')
		return (unsigned char)(va_arg(v_lst, uintmax_t));
	else if (list->length == 3)
		return (va_arg(v_lst, unsigned long));
	else if (list->length == 2 || (list->length == 1 && list->type == 'O'))
		return (unsigned short)(va_arg(v_lst, uintmax_t));
	else if (list->length == 7)
		return (va_arg(v_lst, size_t));
	else if (list->length == 6)
		return (va_arg(v_lst, uintmax_t));
	else
		return (va_arg(v_lst, unsigned int));
}
