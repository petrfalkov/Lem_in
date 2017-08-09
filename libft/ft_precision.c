/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:59:42 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/07 16:49:25 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		if_precision(const char *str, int *point)
{
	int		num;

	if (str[*point] == '.')
	{
		num = 1;
		if (str[*point + num] == '*')
		{
			*point += num + 1;
			str += *point;
			return (1);
		}
		else if (str[*point] == '0')
			*point += 1;
		else if (str[*point] != '0')
		{
			if (str[*point + num] == '+' || str[*point + num] == '-')
				num++;
			while (ft_isdigit(str[*point + num]))
				num++;
			*point += num;
			return (2);
		}
	}
	return (0);
}

void	what_a_precision(const char *str, int *point,
						t_spec_list *list, va_list v_lst)
{
	int		i;

	i = *point - 1;
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			i--;
		if (!(str[i] == '-' || str[i] == '+'))
			i++;
	}
	if (str[i] == '*')
	{
		list->precission = va_arg(v_lst, int);
	}
	else
	{
		str += i;
		list->precission = ft_atoi((char*)str);
	}
}

char	*num_precis(int precis, char *num)
{
	char	*with_pre;
	size_t	len;

	len = ft_strlen(num);
	if (precis <= 0)
		return (num);
	if ((num[0] == '+' || num[0] == '-') && (precis > (int)len - 1))
	{
		with_pre = ft_strnew((size_t)precis - (len - 1));
		with_pre = ft_memset(with_pre, '0', precis - (len - 1));
		with_pre = ft_strjoin(ft_strsub(num, 0, 1), with_pre);
		with_pre = ft_strjoin(with_pre, ft_strsub(num, 1, len - 1));
		return (with_pre);
	}
	else if (precis > (int)len)
	{
		with_pre = ft_strnew((size_t)precis - len);
		with_pre = ft_memset(with_pre, '0', precis - len);
		with_pre = ft_strjoin(with_pre, ft_strsub(num, 0, len));
		return (with_pre);
	}
	else
		return (num);
}
