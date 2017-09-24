/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_graph1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:54:43 by ichubare          #+#    #+#             */
/*   Updated: 2017/09/24 16:54:45 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		init_path_checked_used(t_lem_in *lem_in)
{
	int		i;

	i = 0;
	lem_in->path = (int *)malloc(sizeof(int) * lem_in->num_rooms);
	lem_in->used_rooms = (int *)malloc(sizeof(int) * lem_in->num_rooms);
	lem_in->checked = (int *)malloc(sizeof(int) * lem_in->num_rooms + 1);
	while (i < lem_in->num_rooms)
	{
		lem_in->path[i] = -1;
		lem_in->used_rooms[i] = 0;
		lem_in->checked[i] = -1;
		i++;
	}
	lem_in->checked[0] = 0;
}

int			last_checked(t_lem_in *lem_in)
{
	int		i;

	i = 0;
	while (i < lem_in->num_rooms - 1 && lem_in->checked[i] != -1)
		i++;
	return (lem_in->checked[i - 1]);
}

void		new_way(t_lem_in *lem_in)
{
	t_way	*temp;
	t_way	*iter;
	int		i;

	i = 0;
	iter = lem_in->ways;
	temp = (t_way *)malloc(sizeof(t_way));
	temp->way = (int *)malloc(sizeof(int) * lem_in->num_rooms);
	temp->next = NULL;
	temp->length = 0;
	while (i < lem_in->num_rooms)
	{
		temp->way[i] = lem_in->checked[i];
		if (temp->way[i++] != -1)
			temp->length++;
	}
	if (iter == NULL)
		lem_in->ways = temp;
	else
	{
		iter = lem_in->ways;
		while (iter->next)
			iter = iter->next;
		iter->next = temp;
	}
}

/*
** flag = 0 - dell both,
** flag = 1 - del checked_last,
** flag = 2 - del queue_last
*/

void		del_last(t_lem_in *lem_in, int *queue, int flag)
{
	int	i;

	i = 0;
	while ((flag == 0 || flag == 1) && i < lem_in->num_rooms - 1)
	{
		if (lem_in->checked[i + 1] == -1)
		{
			lem_in->checked[i] = -1;
			break ;
		}
		i++;
	}
	i = 0;
	while ((flag == 0 || flag == 2) && i < lem_in->num_rooms - 1)
	{
		if (queue[i + 1] == -1)
		{
			queue[i] = -1;
			break ;
		}
		i++;
	}
}
