/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:22:27 by ichubare          #+#    #+#             */
/*   Updated: 2016/11/26 19:55:52 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
		const void *restrict src, int c, size_t n)
{
	char	*s1;
	char	*s2;
	int		i;

	i = 0;
	s1 = (char*)dst;
	s2 = (char*)src;
	while (n)
	{
		s1[i] = s2[i];
		if (s2[i] == c)
			return (&s1[i + 1]);
		n--;
		i++;
	}
	return (NULL);
}
