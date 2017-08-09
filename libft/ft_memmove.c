/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:43:14 by ichubare          #+#    #+#             */
/*   Updated: 2016/11/26 18:44:29 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	if (len)
	{
		s1 = (char*)dst;
		s2 = (char*)src;
		if (s2 < s1)
		{
			s1 += len;
			s2 += len;
			while (len)
			{
				*--s1 = *--s2;
				len--;
			}
		}
		else
		{
			while (len--)
				*s1++ = *s2++;
		}
	}
	return (dst);
}
