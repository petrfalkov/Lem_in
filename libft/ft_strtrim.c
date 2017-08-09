/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:55:06 by ichubare          #+#    #+#             */
/*   Updated: 2016/12/18 20:51:17 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char				*str;
	unsigned int		beg;
	unsigned int		end;

	if (s)
	{
		if (!*s)
			return (ft_strnew(1));
		beg = 0;
		end = ft_strlen(s) - 1;
		while ((s[beg] == ' ' || s[beg] == '\t' || s[beg] == '\n'
					|| s[beg] == '.') && beg < end + 1)
			beg++;
		while ((s[end] == ' ' || s[end] == '\t' || s[end] == '\n'
					|| s[end] == '.') && &s[end] != s)
			end--;
		if (beg >= end || beg == ft_strlen(s))
			return (ft_strnew(1));
		if ((str = ft_strnew(end - beg + 1)))
		{
			ft_strncpy(str, s + beg, end - beg + 1);
			return (str);
		}
	}
	return (NULL);
}
