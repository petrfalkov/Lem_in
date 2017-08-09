/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:59:13 by oborysen          #+#    #+#             */
/*   Updated: 2016/12/09 21:09:58 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr(const char *s, int c)
{
	char			ch;
	size_t			i;
	char			*str;

	str = (char*)s;
	ch = c;
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return (str + i);
		i++;
	}
	if ((str[i] == '\0') && (ch == '\0'))
		return (&str[i]);
	return (NULL);
}
