/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:13:00 by ichubare          #+#    #+#             */
/*   Updated: 2016/11/24 17:08:14 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	ss1;
	unsigned char	ss2;

	while (n-- > 0)
	{
		ss1 = *(unsigned char*)s1;
		ss2 = *(unsigned char*)s2;
		if (ss1 != ss2)
			return (ss1 - ss2);
		s1++;
		s2++;
	}
	return (0);
}
