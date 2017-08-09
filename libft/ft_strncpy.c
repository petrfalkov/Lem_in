/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:16:19 by ichubare          #+#    #+#             */
/*   Updated: 2016/11/26 19:17:49 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*s;

	s = dst;
	while (n > 0 && *src)
	{
		*s = *src;
		s++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*s = '\0';
		s++;
		n--;
	}
	return (dst);
}
