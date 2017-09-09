/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 13:42:13 by ichubare          #+#    #+#             */
/*   Updated: 2017/08/08 13:42:16 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "lem_in.h"

void	error_message(void)
{
	ft_putstr("ERROR\n");
	exit(0);
}

void	init_struct(t_lem_in **lem_in)
{
	(*lem_in) = (t_lem_in *) malloc(sizeof(t_lem_in));
	(*lem_in)->num_ants = 0;
	(*lem_in)->num_rooms = 0;
	(*lem_in)->room_end = 0;
	(*lem_in)->room_start = 0;
	(*lem_in)->num_ways = 0;
	(*lem_in)->found_start = 0;
	(*lem_in)->found_end = 0;
	(*lem_in)->found_link = 0;
	(*lem_in)->flag_rooms = 0;
	(*lem_in)->rooms = NULL;
	(*lem_in)->links = NULL;
	(*lem_in)->ways = NULL;
	(*lem_in)->temp_room = NULL;
	(*lem_in)->temp_link = NULL;
}

int		is_comment(char *str)
{
	if ((str[0] == '#' && str[1] != '#') || (ft_strnequ(str, "###", 3)))
		return (1);
	return (0);
}

void	num_ants(t_lem_in *lem_in)
{
	char 	*str;
	int 	num_ants;
	int 	i;

	while (get_next_line(0, &str) && !ft_isdigit(str[0]))
		!is_comment(str) ? error_message() : 0;
	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			error_message();
	num_ants = ft_atoi(str);
	if (num_ants <= 0)
		error_message();
	free(&str);
	lem_in->num_ants = num_ants;
}

int 	is_all_digit(char *str)
{
	int 	i;

	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

int 	is_alnum(char *str)
{
	int 	i;

	i = 0;
	while (str[i])
		if(!ft_isalnum(str[i++]))
			return (0);
	return (1);
}

int 	already_exists(char *new_room, t_lem_in *lem_in)
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


int 	char_count(char *string, int character)
{
	int 	number;
	int 	i;

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

int 	is_room(char *str, t_lem_in *lem_in)
{
	char 	**room;

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

void	free_temp(char **temp)
{
}
/*
 * just_room[0 = yes|1 = start|2 = end]
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
	temp->ant_id = 0;
	temp->next = NULL;
	free_temp(lem_in->temp_room);
	if (lem_in->rooms == NULL)
		lem_in->rooms = temp;
	else
	{
		iter = lem_in->rooms;
		while (iter->next)
			iter = iter->next;
		iter->next = temp;
	}
	just_room == 1 ? lem_in->room_start = lem_in->temp_room[0] : 0;
	just_room == 2 ? lem_in->room_end = lem_in->temp_room[0] : 0;
	lem_in->flag_rooms = 0;
	lem_in->num_rooms++;
}

int 	is_start(char *str, t_lem_in *lem_in)
{
	if (!ft_strequ(str, "##start"))
		return (0);
	lem_in->found_start = 1;
	lem_in->flag_rooms = 1;
	return (1);
}

int 	is_end(char *str, t_lem_in *lem_in)
{
	if (!ft_strequ(str, "##end"))
		return (0);
	lem_in->found_end = 1;
	lem_in->flag_rooms = 2;
	return (1);
}

void		create_links_matrix(t_lem_in *lem_in)
{
	int	i;
	int	j;

	i = 0;
	lem_in->links = (int**)malloc(sizeof(int *) * lem_in->num_rooms);
	while (i < lem_in->num_rooms)
		lem_in->links[i++] = (int*)malloc(sizeof(int) * lem_in->num_rooms);
	i = 0;
	while (i < lem_in->num_rooms)
	{
		j = 0;
		while (j < lem_in->num_rooms)
			lem_in->links[i][j++] = 0;
		i++;
	}
}


int 	is_link(char *str, t_lem_in *lem_in)
{
	char 	**link;

	if (char_count(str, '-') != 1)
		return (0);
	link = ft_strsplit(str, '-');
	if (!is_alnum(link[0]) || !is_alnum(link[1]))
		return (0);
	if (!already_exists(link[0], lem_in) || !already_exists(link[1], lem_in))
		return (0);
	lem_in->temp_link = link;
	lem_in->found_link = 1;
	return (1);
}

int		find_id(t_lem_in *lem_in, int i)
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

void	add_link(t_lem_in *lem_in)
{
	int 	first_id;
	int 	second_id;

	if (lem_in->links == NULL)
		create_links_matrix(lem_in);
	first_id = find_id(lem_in, 0);
	second_id = find_id(lem_in, 1);
	if (first_id == -1 || second_id == -1)
		error_message();
	lem_in->links[first_id][second_id] = 1;
	lem_in->links[second_id][first_id] = 1;
}

void	fill_struct(t_lem_in *lem_in)
{
	char	*str;

	num_ants(lem_in);
	while (get_next_line(0, &str))
	{
		if (ft_strequ(str, "jope"))//for debug
			break;
		if (is_comment(str))
			free(&str);
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

void		init_path_checked_used(t_lem_in *lem_in)
{
	int		i;

	i = 0;
	lem_in->path = malloc(sizeof(int) * lem_in->num_rooms);
	lem_in->used_rooms = malloc(sizeof(int) * lem_in->num_rooms);
	lem_in->checked = (int *)malloc(sizeof(int) * lem_in->num_rooms);
	lem_in->checked[0] = 0;
	while (i < lem_in->num_rooms)
	{
		lem_in->path[i] = -1;
		lem_in->used_rooms[i] = 0;
		lem_in->checked[i] = -1;
		i++;
	}
}
//perepisat
int		last_checked(t_lem_in *lem_in)
{
	int		i;

	i = 0;
	while (i + 1 < lem_in->num_rooms - 1
		   && lem_in->checked[i + 1] != -1)
		i++;
	return (lem_in->checked[i]);
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
		temp->next->way[i] = lem_in->checked[i];
		if (temp->next->way[i] != -1)
			temp->next->length++;
		i++;
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
 *  flag = 0 - dell both,
 *  flag = 1 - del checked_last,
 *  flag = 2 - del quene_last
 */
void		del_last(t_lem_in *lem_in, int *quene, int flag)
{
	int	i;

	i = 0;
	while ((flag == 0 || flag == 1) && i < lem_in->num_rooms - 1)
	{
		if (lem_in->checked[i + 1] == -1)
		{
			lem_in->checked[i] = -1;
			return ;
		}
		i++;
	}
	i = 0;
	while ((flag == 0 || flag == 2) && i < lem_in->num_rooms - 1)
	{
		if (quene[i + 1] == -1)
		{
			quene[i] = -1;
			return ;
		}
		i++;
	}
}

void		create_quene(t_lem_in *lem_in, int *quene)
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
			quene[++count] = i;
		i++;
	}
	while (count < lem_in->num_rooms)
		quene[++count] = -1;
}

int		is_visited(t_lem_in *lem_in, int last_quene)
{
	int	i;

	i = 0;
	while (lem_in->checked[i] != -1)
	{
		if (lem_in->checked[i] == last_quene)
			return (1);
		i++;
	}
	return (0);
}

void	move_in(t_lem_in *lem_in, int *quene)
{
	int 	i;
	int 	last;

	while (!(quene[0] == 0 && quene[1] == -1) && quene[0] != -1)
	{
		i = 0;
		while (quene[i] != -1)
			i++;
		last = quene[i - 1];
		if (last != -1
			&& !is_visited(lem_in, last))
		{
			i = 0;
			while (i < lem_in->num_rooms)
				if (lem_in->checked[i++] == -1)
					break ;
			lem_in->checked[i] = last;
			del_last(lem_in, quene, 2);
			depth_first_search(lem_in);
		}
		if (is_visited(lem_in, last))
			del_last(lem_in, quene, 2);
	}
	del_last(lem_in, quene, 1);
}

void		depth_first_search(t_lem_in *lem_in)
{
	int		quene[lem_in->num_rooms];

	if (last_checked(lem_in) == lem_in->num_rooms - 1)
	{
		lem_in->num_ways++;
		new_way(lem_in);
		del_last(lem_in, quene, 0);
		return ;
	}
	create_quene(lem_in, quene);
	move_in(lem_in, quene);
}

void	fill_graph(t_lem_in *lem_in)
{
	if (!(lem_in->found_link))
		error_message();
	init_path_checked_used(lem_in);
	depth_first_search(lem_in);
	if (lem_in->ways == NULL)
		error_message();
	//dopisat
}

int		main(int argc, char **argv)
{
	t_lem_in	*lem_in;

	init_struct(&lem_in);
	fill_struct(lem_in);
	fill_graph(lem_in);
	return (0);
}