/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:29:24 by ichubare          #+#    #+#             */
/*   Updated: 2016/12/02 14:33:37 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget_node(t_list *start, size_t pos)
{
	size_t	i;

	if (start)
	{
		i = 0;
		while (i != pos && start)
		{
			i++;
			start = start->next;
		}
	}
	return (start);
}
