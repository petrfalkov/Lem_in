/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:16:38 by ichubare          #+#    #+#             */
/*   Updated: 2017/09/24 16:16:40 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_lem_in(t_lem_in *lem_in)
{
	int			i;

	i = 0;
	while (i < lem_in->num_rooms)
	{
		free(lem_in->links[i]);
		i++;
	}
	free(lem_in->links);
	free(lem_in->temp_room);
	free(lem_in->temp_link);
	free(lem_in->used_rooms);
	free(lem_in->checked);
	free(lem_in->output);
	free(lem_in->finished_ants);
	free(lem_in->path);
	free(lem_in);
}

void			free_struct(t_lem_in *lem_in)
{
	t_room		*temp_r;
	t_way		*temp_w;

	while (lem_in->rooms)
	{
		temp_r = lem_in->rooms;
		lem_in->rooms = lem_in->rooms->next;
		free(temp_r->name);
		free(temp_r);
	}
	while (lem_in->ways)
	{
		temp_w = lem_in->ways;
		lem_in->ways = lem_in->ways->next;
		free(temp_w->way);
		free(temp_w);
	}
	free_lem_in(lem_in);
}
