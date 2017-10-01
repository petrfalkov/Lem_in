/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:51:35 by ichubare          #+#    #+#             */
/*   Updated: 2017/01/16 15:29:46 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*ft_lstnew(int fd)
{
	t_gnl	*link;

	link = (t_gnl*)malloc(sizeof(t_gnl));
	if (link == NULL)
		return (NULL);
	link->temp = ft_strnew(0);
	link->fd = fd;
	link->next = NULL;
	return (link);
}
