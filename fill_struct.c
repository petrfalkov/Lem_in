/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 14:11:16 by ichubare          #+#    #+#             */
/*   Updated: 2017/10/01 14:11:18 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		swap_start_end(t_lem_in *lem_in)
{
	t_room	*temp;

	if (lem_in->found_start == 0 || lem_in->found_end == 0)
		error_message();
	temp = lem_in->rooms;
	swap_rooms(lem_in->rooms,
			get_room_by_id(lem_in->rooms, lem_in->room_start));
	while (temp->next)
		temp = temp->next;
	swap_rooms(temp, get_room_by_id(lem_in->rooms, lem_in->room_end));
	lem_in->room_start = 0;
	lem_in->room_end = lem_in->num_rooms - 1;
}

int			is_link(char *str, t_lem_in *lem_in)
{
	char	**link;

	if (char_count(str, '-') != 1)
		return (0);
	link = ft_strsplit(str, '-');
	if (!is_alnum(link[0]) || !is_alnum(link[1]))
		return (0);
	if (!already_exists(link[0], lem_in) || !already_exists(link[1], lem_in))
		return (0);
	lem_in->temp_link = link;
	if (lem_in->found_link == 0)
		swap_start_end(lem_in);
	lem_in->found_link = 1;
	return (1);
}

int			find_id(t_lem_in *lem_in, int i)
{
	t_room	*temp;

	temp = lem_in->rooms;
	if (!ft_strcmp(temp->name, lem_in->temp_link[i]))
		return (temp->id);
	while (temp->next)
	{
		temp = temp->next;
		if (!ft_strcmp(temp->name, lem_in->temp_link[i]))
			return (temp->id);
	}
	return (-1);
}

void		add_link(t_lem_in *lem_in)
{
	int		first_id;
	int		second_id;

	if (lem_in->links == NULL)
		create_links_matrix(lem_in);
	first_id = find_id(lem_in, 0);
	second_id = find_id(lem_in, 1);
	free(lem_in->temp_link);
	if (first_id == -1 || second_id == -1)
		error_message();
	lem_in->links[first_id][second_id] = 1;
	lem_in->links[second_id][first_id] = 1;
}

void		fill_struct(t_lem_in *lem_in)
{
	char	*str;

	num_ants(lem_in);
	while (get_next_line(0, &str))
	{
		join_fn(lem_in, str);
		if (is_comment(str))
			free(str);
		else if (!lem_in->found_link && is_room(str, lem_in))
			add_room(lem_in, lem_in->flag_rooms);
		else if (!lem_in->found_start && !lem_in->found_link
				&& is_start(str, lem_in))
			continue ;
		else if (!lem_in->found_end && !lem_in->found_link
				&& is_end(str, lem_in))
			continue ;
		else if (lem_in->found_end && lem_in->found_start
				&& is_link(str, lem_in))
			add_link(lem_in);
		else
			error_message();
	}
}
