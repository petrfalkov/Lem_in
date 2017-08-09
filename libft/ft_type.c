/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:05:08 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/19 12:04:39 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		if_type(const char *str, int *point, int *prev)
{
	*prev = *point;
	if (str[*point] == 'd' || str[*point] == 'i' || str[*point] == 'u'
		|| str[*point] == 'f' || str[*point] == 'F' || str[*point] == 'e'
		|| str[*point] == 'E' || str[*point] == 'g' || str[*point] == 'G'
		|| str[*point] == 'x' || str[*point] == 'X' || str[*point] == 'o'
		|| str[*point] == 's' || str[*point] == 'c' || str[*point] == 'p'
		|| str[*point] == 'a' || str[*point] == 'A' || str[*point] == 'n'
		|| str[*point] == 'U' || (str[*point] >= 32 && str[*point] <= 126)
		|| str[*point] == 'S' || str[*point] == 'O' || str[*point] == 'D')
	{
		*point += 1;
		return (1);
	}
	return (0);
}

void	what_the_type(const char *str, int point, t_spec_list *list)
{
	list->type = str[point];
	if (list->type == 'u' || list->type == 'o' || list->type == 'x'
		|| list->type == 'X' || list->type == 'U' || list->type == 'O')
		list->flag[1] = 0;
	if (list->type == 'S')
	{
		list->type = 's';
		list->length = 3;
		list->if_sl = 1;
	}
	else if (list->type == 'C')
	{
		list->type = 'c';
		list->length = 3;
	}
	else if (list->type == 'p')
		list->if_p = 1;
	else if (list->type == 'D')
		list->length = 3;
}
