/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:36:12 by ichubare          #+#    #+#             */
/*   Updated: 2016/11/22 16:36:42 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	const char *s1;
	const char *s2;

	if (!*little)
		return (char*)(big);
	while (*big)
	{
		s1 = big;
		s2 = little;
		while (*s1 && *s2 && !(*s1 - *s2))
		{
			s2++;
			s1++;
		}
		if (!*s2)
			return (char*)(big);
		big++;
	}
	return (0);
}
