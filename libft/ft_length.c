/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:28:08 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/07 15:30:07 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		if_length(const char *str, int *point, int *prev)
{
	*prev = *point;
	if ((str[*point] == 'l' && str[*point + 1] == 'l') ||
		(str[*point] == 'h' && str[*point + 1] == 'h'))
	{
		*point += 2;
		return (2);
	}
	else if (str[*point] == 'l' || str[*point] == 'h'
			|| str[*point] == 'L' || str[*point] == 'z'
			|| str[*point] == 'j' || str[*point] == 't')
	{
		*point += 1;
		return (1);
	}
	return (0);
}

void	what_the_length(const char *str, int point, t_spec_list *list)
{
	if (str[point] == 'l' && str[point + 1] == 'l')
		list->length = 4;
	else if (str[point] == 'h' && str[point + 1] == 'h')
		list->length = 1;
	else if (str[point] == 'l')
		list->length = 3;
	else if (str[point] == 'h')
		list->length = 2;
	else if (str[point] == 'L')
		list->length = 5;
	else if (str[point] == 'z')
		list->length = 7;
	else if (str[point] == 'j')
		list->length = 6;
	else
		list->length = 8;
	if (list->length > list->len)
		list->len = list->length;
	else
		list->length = list->len;
}
