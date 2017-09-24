/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:18:57 by ichubare          #+#    #+#             */
/*   Updated: 2017/09/24 16:18:59 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				room_position(int *current_way, int way_length, int room_id)
{
	int	iter;

	iter = 0;
	while (iter < way_length && current_way[iter] != -1)
	{
		if (current_way[iter] == room_id)
			return (iter);
		iter++;
	}
	return (-1);
}

void			show_move(int ant_id, char *room_name)
{
	write(1, "L", 1);
	ft_putnbr(ant_id);
	write(1, "-", 1);
	ft_putstr(room_name);
	write(1, " ", 1);
}

void			push_current(t_lem_in *lem_in, t_room *room)
{
	int			pos;
	t_room		*next_room;
	t_way		*ways;

	ways = lem_in->ways;
	while (ways)
	{
		pos = room_position(ways->way, lem_in->num_rooms, room->id);
		if (pos != -1)
		{
			next_room = get_room_by_id(lem_in->rooms, ways->way[pos + 1]);
			if (next_room->ant_id == -1)
			{
				room->ant_id = -1;
				if (next_room->id == lem_in->num_rooms - 1 &&
						lem_in->num_ants-- >= 0)
					lem_in->finished_ants[lem_in->iter] = 0;
				else
					next_room->ant_id = lem_in->iter + 1;
				show_move(lem_in->iter + 1, next_room->name);
				break ;
			}
		}
		ways = ways->next;
	}
}

t_room			*get_room_by_ant_id(t_lem_in *lem_in)
{
	t_room		*current_r;
	int			ant_id;

	current_r = lem_in->rooms;
	ant_id = lem_in->iter + 1;
	while (current_r)
	{
		if (current_r->ant_id == ant_id)
			return (current_r);
		current_r = current_r->next;
	}
	return (lem_in->rooms);
}

void			push_ants(t_lem_in *lem_in)
{
	int			ant_num;
	t_room		*room;
	int			i;

	i = 0;
	lem_in->finished_ants = (int*)malloc(sizeof(int) * lem_in->num_ants);
	while (i < lem_in->num_ants)
		lem_in->finished_ants[i++] = 1;
	ant_num = lem_in->num_ants;
	while (lem_in->num_ants != 0)
	{
		lem_in->iter = 0;
		while (lem_in->iter < ant_num)
		{
			if (lem_in->finished_ants[lem_in->iter] == 1)
			{
				room = get_room_by_ant_id(lem_in);
				push_current(lem_in, room);
			}
			lem_in->iter++;
		}
		write(1, "\n", 1);
	}
}
