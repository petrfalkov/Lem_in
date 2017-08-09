/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:28:10 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/07 15:40:59 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	just_print(t_param_list *param, char ch)
{
	param->count_bytes++;
	ft_putchar((unsigned char)ch);
}

int		ft_printf(const char *format, ...)
{
	va_list			v_list;
	int				i;
	int				temp;
	t_param_list	*param;

	i = 0;
	param = param_list();
	va_start(v_list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			temp = ret_point(format, i + 1, v_list, param);
			if (temp == -1)
				va_start(v_list, format);
			else
				i = temp;
		}
		else
			just_print(param, format[i++]);
	}
	va_end(v_list);
	return (param->count_bytes);
}
