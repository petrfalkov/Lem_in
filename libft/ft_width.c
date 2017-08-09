/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:20:39 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/07 16:01:24 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		if_width(const char *str, int *point, int *prev)
{
	int num;

	num = *point;
	*prev = *point;
	if (str[num] == '*')
	{
		*point += 1;
		return (1);
	}
	else if (str[num] != '0')
	{
		if (str[num] == '-' && ft_isdigit(str[num + 1])
			&& str[num + 1] != '0')
			*point += 1;
		num = 0;
		str += *point;
		while (ft_isdigit(str[num]))
			num++;
		if (num == 0)
			return (0);
		*point += num;
		return (2);
	}
	return (0);
}

void	what_the_width(const char *str, int point, t_spec_list *list,
		va_list v_lst)
{
	int i;

	i = point;
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			i--;
		i++;
	}
	if (str[i] == '*')
	{
		list->width = va_arg(v_lst, int);
		if (list->width < 0)
			list->flag[0] = 1;
	}
	else
	{
		str += i;
		list->width = ft_atoi((char *)str);
	}
}
