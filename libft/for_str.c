/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:29:24 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/19 12:28:37 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		if_norm(char *s)
{
	while (*s)
	{
		if (*s < 32 || *s > 127)
			return (0);
		s++;
	}
	return (1);
}

void	*ft_ret_str_precision(char *str, size_t precision, t_spec_list *list)
{
	size_t		len;
	char		*str_emp;

	len = ft_strlen((const char *)str);
	if (list->if_sl == 1 && list->precission != 0 &&
			(list->width == 0 || (list->precission < list->width))
		&& !if_norm(str))
		precision--;
	if (precision < len && precision > 0)
		return (ft_strsub((const char *)str, 0, precision));
	else if (precision <= 0)
	{
		str_emp = ft_strnew(precision * -1);
		ft_memset(str_emp, ' ', precision * -1);
		return (str_emp);
	}
	else
		return (str);
}

void	*ft_ret_str_width(char *str, t_spec_list *lst)
{
	char	*new_str;
	size_t	len;

	len = ft_strlen(str);
	if (lst->width == 0)
		new_str = ft_strnew(len);
	else if (lst->width > (int)len)
		new_str = ft_strnew(lst->width - len);
	else
		new_str = ft_strnew(0);
	if (lst->width > (int)len && lst->flag[0] == 1)
	{
		new_str = ft_memset(new_str, ' ', lst->width - len);
		new_str = ft_strjoin(str, new_str);
		return (new_str);
	}
	else if (lst->width > (int)len)
	{
		new_str = (lst->flag[4] == 1)
			? (ft_memset(new_str, '0', lst->width - len))
			: (ft_memset(new_str, ' ', lst->width - len));
		new_str = ft_strjoin(new_str, str);
		return (new_str);
	}
	return (str);
}

void	str_ret(t_spec_list *list, char *str, t_for_chk_l *fcl)
{
	if (!str)
		str = "(null)";
	if (list->width < 0)
	{
		list->flag[0] = 1;
		list->width *= -1;
	}
	if (fcl->if_prec != 0)
		str = ft_ret_str_precision(str, (size_t)list->precission, list);
	if (list->precission >= 0)
		str = ft_ret_str_width(str, list);
	list->n_len = ft_strlen(str);
	ft_putstr(str);
}
