/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:48:28 by ichubare          #+#    #+#             */
/*   Updated: 2017/01/29 16:58:42 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		sum;

	sum = (int)(2 + ft_strlen(s1) + ft_strlen(s2));
	res = (char *)malloc(sum * sizeof(char));
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	ft_strcat(res, "\n");
	free(s1);
	return (res);
}
