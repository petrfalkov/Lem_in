/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:37:59 by ichubare          #+#    #+#             */
/*   Updated: 2016/11/26 19:20:31 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict dst, const char *restrict src, size_t n)
{
	char	*s1;
	char	*s2;
	int		i;
	int		l;

	s1 = dst;
	s2 = (char*)src;
	i = 0;
	l = 0;
	while (s1[i])
		i++;
	while (s2[l] && n > 0)
	{
		s1[i + l] = s2[l];
		l++;
		n--;
	}
	s1[i + l] = '\0';
	return (s1);
}
