/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:36:01 by ichubare          #+#    #+#             */
/*   Updated: 2016/12/02 14:37:22 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memclr(void *memptr, size_t memlen)
{
	size_t	i;

	if (memptr)
	{
		i = -1;
		while (++i < memlen)
			((char*)memptr)[i] = 0;
	}
	free(memptr);
}
