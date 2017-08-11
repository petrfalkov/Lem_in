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
	(*lem_in)->ways = 0;
	(*lem_in)->found_start = 0;
	(*lem_in)->found_end = 0;
	(*lem_in)->found_link = 0;
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
	free(str);
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


int 	char_count(char *str, int character)
{
	int 	number;
	int 	i;

	number = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == character)
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
	temp->next = NULL;
	while (*(lem_in->temp_room))
	{
		free(*(lem_in->temp_room));
		lem_in->temp_room++;
	}
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
}

int 	is_start(char *str, t_lem_in *lem_in)
{
	if (!ft_strequ(str, "##start"))
		return (0);
	lem_in->found_start = 1;
	return (1);
}

int 	is_end(char *str, t_lem_in *lem_in)
{
	if (!ft_strequ(str, "#end"))
		return (0);
	lem_in->found_end = 1;
	return (1);
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
	return (1);
}

void	add_link(t_lem_in *lem_in)
{
	t_link	*temp;
	t_link	*iter;

	temp = (t_link*)malloc(sizeof(t_link));
	temp->link[0] = lem_in->temp_link[0];
	temp->link[1] = lem_in->temp_link[1];
	temp->used = 0;
	temp->next = NULL;
	while (*(lem_in->temp_link))
	{
		free(*(lem_in->temp_link));
		lem_in->temp_link++;
	}
	if (lem_in->links == NULL)
		lem_in->links = temp;
	else
	{
		iter = lem_in->links;
		while (iter->next)
			iter = iter->next;
		iter->next = temp;
	}
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
			free(str);
		else if (!lem_in->found_link && is_room(str, lem_in))
			add_room(lem_in, 0);
		else if (!lem_in->found_start && !lem_in->found_link
				 && is_start(str, lem_in))
			add_room(lem_in, 1);
		else if (!lem_in->found_end && !lem_in->found_link
				 && is_end(str, lem_in))
			add_room(lem_in, 2);
		else if (lem_in->found_end && lem_in->found_start
				 && is_link(str, lem_in))
			add_link(lem_in);
		else
			error_message();
	}
}

int		main(int argc, char **argv)
{
	t_lem_in	*lem_in;

	init_struct(&lem_in);
	fill_struct(lem_in);
	return (0);
}