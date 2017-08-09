/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:15:52 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/23 15:15:57 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_param_list	*param_list(void)
{
	t_param_list *params;

	params = (t_param_list *)malloc(sizeof(t_param_list));
	params->link = 0;
	params->count_bytes = 0;
	return (params);
}

t_spec_list		*ft_new_spec_lst(void)
{
	t_spec_list	*list;
	int			i;

	i = 0;
	list = (t_spec_list *)malloc(sizeof(t_spec_list));
	while (i < 5)
		list->flag[i++] = 0;
	list->length = 0;
	list->precission = 0;
	list->width = 0;
	list->parameter = 0;
	list->type = 0;
	list->next = NULL;
	list->n_len = 0;
	list->if_prec = 0;
	list->if_p = 0;
	list->if_sl = 0;
	list->len = 0;
	list->prev = 0;
	list->point = 0;
	return (list);
}

t_for_chk_l		*ft_new_fcl(void)
{
	t_for_chk_l *list;

	list = (t_for_chk_l *)malloc(sizeof(t_for_chk_l));
	list->flag = 0;
	list->length = 0;
	list->precission = 0;
	list->if_prec = 0;
	list->width = 0;
	list->parameter = 0;
	list->next = NULL;
	return (list);
}
