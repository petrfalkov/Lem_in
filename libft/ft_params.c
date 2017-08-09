/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 19:46:05 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/07 15:46:10 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		if_param(const char *str, int *point, int *prev)
{
	int i;
	int shift;

	i = *point;
	*prev = *point;
	shift = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			shift++;
			i++;
		}
		else
			break ;
	}
	if (str[i] == '$')
	{
		*point += shift + 1;
		return (1);
	}
	return (0);
}

int		what_a_param(const char *str, int point)
{
	int par;
	int i;

	i = point;
	str += i - 2;
	while (*str && ft_isdigit(*str))
		str--;
	str++;
	par = ft_atoi((char *)str);
	return (par);
}
