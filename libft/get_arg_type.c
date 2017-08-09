/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:04:48 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/19 13:26:40 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	get_arg_type(t_spec_list *list, va_list v_lst,
		t_param_list *param)
{
	uintmax_t	arg;

	arg = 0;
	if (list->type == 'n')
		param->link = va_arg(v_lst, int *);
	else if (list->type == 'p')
	{
		list->flag[3] = 1;
		list->type = 'x';
		arg = (uintmax_t)va_arg(v_lst, void *);
	}
	return (arg);
}

char		get_ch_arg(va_list v_lst)
{
	char	arg;

	arg = va_arg(v_lst, int);
	return (arg);
}

char		*get_wchar_arg(va_list v_lst)
{
	char	*arg;

	arg = ft_get_wchar(va_arg(v_lst, wchar_t));
	return (arg);
}

char		*get_str_arg(t_spec_list *list, va_list v_lst)
{
	char	*arg;
	char	*ret;
	wchar_t *warg;

	ret = ft_strnew(0);
	if (list->type == 's' && list->length == 3)
	{
		warg = va_arg(v_lst, wchar_t*);
		if (warg == NULL)
			return (NULL);
		while (*warg)
		{
			ret = ft_strjoin(ret, ft_get_wchar(*warg));
			warg++;
		}
		arg = ret;
	}
	else
		arg = (char *)va_arg(v_lst, void*);
	return (arg);
}

uintmax_t	get_u(t_spec_list *list, va_list v_lst)
{
	if (list->length == 4 || (list->length == 2 && list->type == 'U')
			|| list->type == 'U')
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
