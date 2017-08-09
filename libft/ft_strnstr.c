/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:43:04 by ichubare          #+#    #+#             */
/*   Updated: 2016/11/26 19:49:46 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	const char	*s1;
	const char	*s2;
	size_t		k;
	size_t		i;

	k = 0;
	if (!*little)
		return (char*)(big);
	while (*big && k < n)
	{
		s1 = big;
		s2 = little;
		i = k;
		while (*s1 && *s2 && !(*s1 - *s2) && i < n)
		{
			s2++;
			s1++;
			i++;
		}
		if (!*s2)
			return (char*)(big);
		big++;
		k++;
	}
	return (NULL);
}
