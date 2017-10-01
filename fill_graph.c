/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:26:08 by ichubare          #+#    #+#             */
/*   Updated: 2017/09/24 16:26:09 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		create_queue(t_lem_in *lem_in, int *queue)
{
	int		checked;
	int		i;
	int		count;

	checked = last_checked(lem_in);
	i = 0;
	count = 0;
	while (i < lem_in->num_rooms)
	{
		if (lem_in->links[checked][i] == 1)
			queue[count++] = i;
		i++;
	}
	while (count < lem_in->num_rooms)
		queue[count++] = -1;
}

int			is_visited(t_lem_in *lem_in, int last_queue)
{
	int	i;

	i = 0;
	while (lem_in->checked[i] != -1)
	{
		if (lem_in->checked[i] == last_queue)
			return (1);
		i++;
	}
	return (0);
}

void		move_in(t_lem_in *lem_in, int *queue)
{
	int		i;
	int		last;

	while (!(queue[0] == 0 && queue[1] == -1) && queue[0] != -1)
	{
		i = 0;
		while (queue[i] != -1)
			i++;
		last = queue[i - 1];
		if (last != -1 && !is_visited(lem_in, last))
		{
			i = 0;
			while (i < lem_in->num_rooms)
			{
				if (lem_in->checked[i] == -1)
					break ;
				i++;
			}
			lem_in->checked[i] = last;
			del_last(lem_in, queue, 2);
			depth_first_search(lem_in);
		}
		is_visited(lem_in, last) == 1 ? del_last(lem_in, queue, 2) : 0;
	}
	del_last(lem_in, queue, 1);
}

void		depth_first_search(t_lem_in *lem_in)
{
	int		queue[lem_in->num_rooms];

	if (last_checked(lem_in) == lem_in->num_rooms - 1)
	{
		lem_in->num_ways++;
		new_way(lem_in);
		del_last(lem_in, queue, 0);
		return ;
	}
	create_queue(lem_in, queue);
	move_in(lem_in, queue);
}

void		fill_graph(t_lem_in *lem_in)
{
	if (!(lem_in->found_link))
		error_message();
	init_path_checked_used(lem_in);
	depth_first_search(lem_in);
	if (lem_in->ways == NULL)
		error_message();
}
