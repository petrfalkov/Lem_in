/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:17:49 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/07 15:28:59 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		if_flag(const char *ch, int *point)
{
	ch += *point;
	if (*ch == '-' || *ch == '+' || *ch == ' ' || *ch == '#' || *ch == '0')
	{
		*point += 1;
		return (1);
	}
	return (0);
}

void	what_the_flag(const char *ch, t_spec_list *list, int prev)
{
	if (ch[prev - 1] == '-')
		list->flag[0] = 1;
	else if (ch[prev - 1] == '+')
		list->flag[1] = 1;
	else if (ch[prev - 1] == ' ')
		list->flag[2] = 1;
	else if (ch[prev - 1] == '#')
		list->flag[3] = 1;
	else if (ch[prev - 1] == '0')
		list->flag[4] = 1;
}

char	*with_plus(char *num, intmax_t number)
{
	unsigned int i;

	i = 0;
	if (number >= 0 && num[0] != '+')
	{
		while (!(ft_isdigit(num[i])) && num[i])
			i++;
		return (ft_strjoin(ft_strsub(num, 0, i),
					ft_strjoin("+", ft_strsub(num, i, ft_strlen(num)))));
	}
	else if (number < 0 && num[0] != '-')
		return (ft_strjoin(ft_strsub(num, 0, i),
					ft_strjoin("-", ft_strsub(num, i, ft_strlen(num)))));
	else
		return (num);
}
