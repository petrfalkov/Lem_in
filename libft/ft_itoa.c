/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:40:40 by ichubare          #+#    #+#             */
/*   Updated: 2016/12/01 17:48:38 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numb(int n)
{
	int		len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int		power(int num, int len)
{
	int		res;

	if (len <= 0)
		return (1);
	res = 1;
	while (len--)
		res *= num;
	return (res);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*res;
	int		i;

	len = numb(n);
	if (n <= 0)
		res = (char*)malloc(sizeof(char) * (len + 2));
	else
		res = (char*)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	i = 0;
	if (n < 0 && ++i)
		res[0] = '-';
	if (n == 0 && ++i)
		res[0] = '0';
	while (--len >= 0)
	{
		if (n < 0)
			res[i++] = '0' - (n / power(10, len)) % 10;
		else
			res[i++] = '0' + (n / power(10, len)) % 10;
	}
	res[i] = 0;
	return (res);
}
