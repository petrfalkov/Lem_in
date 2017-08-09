/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:37:38 by ichubare          #+#    #+#             */
/*   Updated: 2016/12/02 14:39:49 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *str)
{
	char	*ret_str;
	size_t	len;
	size_t	i;

	ret_str = 0;
	if (str)
	{
		len = ft_strlen(str);
		ret_str = ft_strnew(len);
		i = 0;
		while (i != len)
		{
			ret_str[i] = str[len - 1 - i];
			i++;
		}
	}
	return (ret_str);
}
