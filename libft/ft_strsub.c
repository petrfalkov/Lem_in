/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:37:38 by ichubare          #+#    #+#             */
/*   Updated: 2016/11/27 18:09:04 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s)
	{
		i = 0;
		str = (char*)malloc(sizeof(char) * len + 1);
		if (str == NULL)
			return (NULL);
		while (start > 0)
		{
			s++;
			start--;
		}
		while (i < len)
		{
			str[i] = *s;
			i++;
			s++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
