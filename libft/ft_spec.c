/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fpf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:27:49 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/21 17:32:07 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_lists(t_spec_list **list, t_for_chk_l **fcl)
{
	if (*list == NULL)
		*list = ft_new_spec_lst();
	*fcl = ft_new_fcl();
}

void	what_to_find(t_spec_list *spec_lst, t_for_chk_l *fcl, va_list v_lst,
					const char *str)
{
	if (spec_lst->parameter > 1)
	{
		while (spec_lst->parameter-- > 1)
			va_arg(v_lst, void*);
	}
	while ((fcl->width = if_width(str, &spec_lst->point, &spec_lst->prev)) ||
			(fcl->precission = if_precision(str, &spec_lst->point)) ||
			(fcl->length = if_length(str, &spec_lst->point, &spec_lst->prev)) ||
			(if_flag(str, &spec_lst->point)))
	{
		if (fcl->width)
			what_the_width(str, spec_lst->prev, spec_lst, v_lst);
		else if (fcl->precission)
		{
			what_a_precision(str, &spec_lst->point, spec_lst, v_lst);
			fcl->if_prec = 1;
			if (spec_lst->precission == 0)
				spec_lst->if_prec = 1;
		}
		else if (fcl->length)
			what_the_length(str, spec_lst->prev, spec_lst);
		else
			what_the_flag(str, spec_lst, spec_lst->point);
	}
}

int		ret_point(const char *str, int i, va_list v_lst, t_param_list *param)
{
	t_for_chk_l			*fcl;
	static t_spec_list	*spec_list = NULL;

	init_lists(&spec_list, &fcl);
	if (spec_list->point != 0)
	{
		spec_list = NULL;
		init_lists(&spec_list, &fcl);
	}
	spec_list->point = i;
	if (if_param(str, &spec_list->point, &spec_list->prev)
		&& spec_list->parameter == 0)
	{
		spec_list->parameter = what_a_param(str, spec_list->point);
		va_end(v_lst);
		return (-1);
	}
	what_to_find(spec_list, fcl, v_lst, str);
	if (if_type(str, &spec_list->point, &spec_list->prev))
		what_the_type(str, spec_list->prev, spec_list);
	out_arg(spec_list, v_lst, fcl, param);
	param->count_bytes += spec_list->n_len;
	return (spec_list->point);
}
