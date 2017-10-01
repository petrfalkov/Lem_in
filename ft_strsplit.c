/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:37:48 by ichubare          #+#    #+#             */
/*   Updated: 2016/11/30 19:21:23 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countofw(char const *s, char c)
{
	int		count;
	int		flag;
	int		len;

	count = 0;
	flag = 0;
	len = ft_strlen(s);
	while (*s && *s == c && len-- >= 0)
		s++;
	while (*s && len-- >= 0)
	{
		while (*s != c && len-- >= 0)
		{
			flag = 1;
			s++;
		}
		if (flag == 1)
		{
			flag = 0;
			count++;
		}
		s++;
	}
	return (count);
}

static int	countofl(char const *s, char c, int *point)
{
	int		count;
	int		len;
	int		i;

	count = 0;
	i = *point;
	len = ft_strlen(s);
	while (s[i] && s[i] == c && len-- > 0)
		i++;
	while (s[i] && s[i] != c && len-- > 0)
	{
		count++;
		i++;
	}
	*point = i;
	return (count);
}

static char	**memal(char const *s, char c)
{
	int		point;
	int		cow;
	char	**arr;
	int		i;
	int		j;

	point = 0;
	i = 0;
	cow = countofw(s, c);
	arr = (char**)malloc(sizeof(char*) * cow + 1);
	if (arr == NULL)
		return (NULL);
	while (i < cow)
	{
		j = countofl(s, c, &point);
		arr[i] = ft_strnew(j);
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = 0;
	return (arr);
}

static char	**putin(char const *s, char c, int point, int len)
{
	char	**arr;
	int		iter[2];

	arr = memal(s, c);
	if (!arr)
		return (NULL);
	iter[0] = 0;
	while (s[point] && len >= 0)
	{
		iter[1] = 0;
		while (s[point] == c && len >= 0)
		{
			point++;
			len--;
		}
		while (s[point] && s[point] != c && len >= 0)
		{
			arr[iter[0]][iter[1]++] = s[point++];
			len--;
		}
		iter[0]++;
		point++;
		len--;
	}
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		len;
	int		k;

	arr = NULL;
	if (!s)
		return (NULL);
	k = 0;
	len = ft_strlen(s);
	while (s[k] && len > 0 && s[k] == c)
	{
		len--;
		k++;
	}
	arr = putin(s, c, k, len);
	if (!arr)
		return (NULL);
	return (arr);
}
