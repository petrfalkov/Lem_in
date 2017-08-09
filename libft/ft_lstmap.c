/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:15:58 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/16 16:11:48 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_pushback(t_list *lst, t_list *news)
{
	t_list	*temp;

	if (lst != NULL)
	{
		temp = lst;
		while (lst->next)
			lst = lst->next;
		lst->next = news;
		lst = temp;
	}
	else
		lst = news;
	return (lst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_temp;
	t_list	*new_list;
	t_list	*temp1;
	t_list	*temp2;

	temp1 = lst;
	new_list = NULL;
	while (temp1)
	{
		temp2 = f((t_list*)temp1);
		new_temp = ft_lstnew(0, 0);
		new_list = ft_pushback(new_list, (t_list *)new_temp);
		temp1 = temp1->next;
	}
	return (new_list);
}
