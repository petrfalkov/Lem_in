/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 14:11:54 by ichubare          #+#    #+#             */
/*   Updated: 2017/10/01 14:11:56 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		already_exists(char *new_room, t_lem_in *lem_in)
{
	t_room	*temp;

	temp = lem_in->rooms;
	while (temp)
	{
		if (ft_strequ(temp->name, new_room))
			return (1);
		temp = temp->next;
	}
	return (0);
}

int		char_count(char *string, int character)
{
	int		number;
	int		i;

	number = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] == character)
			number++;
		i++;
	}
	return (number);
}

int		is_room(char *str, t_lem_in *lem_in)
{
	char	**room;

	if (char_count(str, ' ') != 2)
		return (0);
	room = ft_strsplit(str, ' ');
	if (room[0][0] == 'L' || !is_alnum(room[0]))
		return (0);
	if (!(is_all_digit(room[1]) && is_all_digit(room[2]))
		|| (already_exists(room[0], lem_in)))
		error_message();
	lem_in->temp_room = room;
	return (1);
}

/*
** flag [0 = link| 1 = room]
*/

void	free_temp(t_lem_in *lem_in, int flag)
{
	int		i;

	i = 0;
	if (flag == 0)
		while (lem_in->temp_link[i])
			free(lem_in->temp_link[i++]);
	else
		while (lem_in->temp_room[i])
			free(lem_in->temp_room[i++]);
}

/*
** just_room[0 = yes|1 = start|2 = end]
*/

void	add_room(t_lem_in *lem_in, int just_room)
{
	t_room	*temp;
	t_room	*iter;

	temp = (t_room *)malloc(sizeof(t_room));
	temp->name = lem_in->temp_room[0];
	temp->coord_x = ft_atoi(lem_in->temp_room[1]);
	temp->coord_y = ft_atoi(lem_in->temp_room[2]);
	temp->id = lem_in->num_rooms;
	temp->ant_id = -1;
	temp->next = NULL;
	if (lem_in->rooms == NULL)
		lem_in->rooms = temp;
	else
	{
		iter = lem_in->rooms;
		while (iter->next)
			iter = iter->next;
		iter->next = temp;
	}
	just_room == 1 ? lem_in->room_start = lem_in->num_rooms : 0;
	just_room == 2 ? lem_in->room_end = lem_in->num_rooms : 0;
	lem_in->flag_rooms = 0;
	lem_in->num_rooms++;
}
