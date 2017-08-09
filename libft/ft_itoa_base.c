/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:07:55 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/19 12:29:23 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fhex(uintmax_t value, unsigned int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789ABCDEF";
	if (value != 0)
	{
		if (value >= (size_t)base)
			fhex(value / base, base, str, i);
		str[(*i)++] = tmp[(value % base)];
	}
	else
		str[(*i)++] = '0';
}

char		*ft_itoa_base_hex(uintmax_t value, unsigned int base)
{
	char	*s;
	int		i;

	i = 0;
	if (base < 2 || base > 16 || !(s = (char *)malloc(32)))
		return (0);
	fhex(value, base, s, &i);
	s[i] = '\0';
	return (s);
}

static void	f(intmax_t value, int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789ABCDEF";
	if (value <= -base || value >= base)
		f(value / base, base, str, i);
	str[(*i)++] = tmp[(value % base) < 0 ? -(value % base) : (value % base)];
}

char		*ft_itoa_base(intmax_t value, int base)
{
	char	*s;
	int		i;

	i = 0;
	if (base < 2 || base > 16 || !(s = (char *)malloc(32)))
		return (0);
	if (base == 10 && value < 0)
		s[i++] = '-';
	f(value, base, s, &i);
	s[i] = '\0';
	return (s);
}
