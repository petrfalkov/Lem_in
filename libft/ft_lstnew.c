/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:22:09 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/17 13:42:24 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*a;
	unsigned char	*b;
	unsigned char	*c;
	size_t			d;

	d = -1;
	if (!(a = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		a->content = 0;
		a->content_size = 0;
	}
	else
	{
		b = (unsigned char*)content;
		c = (unsigned char*)malloc(sizeof(content_size) + 1);
		while (++d < content_size + 1)
			c[d] = b[d];
		a->content = c;
		a->content_size = content_size;
	}
	a->next = 0;
	return (a);
}
