/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:55:20 by ichubare          #+#    #+#             */
/*   Updated: 2016/11/26 18:49:05 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	k;
	char	*s2;

	k = 0;
	if ((s2 = (char*)malloc(sizeof(*s2) * ft_strlen(s1) + 1)) != NULL)
	{
		while (k < ft_strlen(s1))
		{
			s2[k] = s1[k];
			k++;
		}
		s2[k] = '\0';
		return (s2);
	}
	else
		return (NULL);
}
