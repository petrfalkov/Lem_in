/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:26:18 by ichubare          #+#    #+#             */
/*   Updated: 2016/12/01 17:33:28 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] && i < (unsigned int)n)
	{
		if ((unsigned char)s1[i] - (unsigned char)s2[i])
			return (0);
		i++;
	}
	if ((unsigned char)s1[i] - (unsigned char)s2[i]
			&& (i != (unsigned int)n))
		return (0);
	else
		return (1);
}
