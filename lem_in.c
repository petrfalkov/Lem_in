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

void	error_message(char *str)
{
	ft_putstr("ERROR\n");
	ft_putstr(str);
	ft_putchar('\n');
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
	(*lem_in)->iter = 0;
	(*lem_in)->output = ft_strnew(0);
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
		!is_comment(str) ? error_message("num_ants") : 0;
	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			error_message("while after num ants");
	num_ants = ft_atoi(str);
	if (num_ants <= 0)
		error_message("zero num ants");
	lem_in->output = ft_strjoin(lem_in->output, str);
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
		error_message("room is not digit or already exists");
	lem_in->temp_room = room;
	return (1);
}

/*
 * flag [0 = link| 1 = room]
 */

void	free_temp(t_lem_in *lem_in, int flag)
{
	int 	i;

	i = 0;
	if (flag == 0)
		while (lem_in->temp_link[i])
			free(lem_in->temp_link[i++]);
	else
		while (lem_in->temp_room[i])
			free(lem_in->temp_room[i++]);
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
	free_temp(lem_in, 1);
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

t_room		*get_room_by_id(t_room *rooms, int id)
{
	t_room	*temp;

	temp = rooms;
	while (temp && temp->id != id)
		temp = temp->next;
	if (temp && temp->id == id)
		return (temp);
	error_message("room not found");
	return 0;
}

void		swap_rooms(t_room *current, t_room *swapable)
{
	t_room	*temp;

	temp = malloc(sizeof(t_room*));
	temp->name = current->name;
	temp->coord_x = current->coord_x;
	temp->coord_y = current->coord_y;
	current->name = swapable->name;
	current->coord_x = swapable->coord_x;
	current->coord_y = swapable->coord_y;
	swapable->name = temp->name;
	swapable->coord_x = temp->coord_x;
	swapable->coord_y = temp->coord_y;
}

void		swap_start_end(t_lem_in *lem_in)
{
	t_room	*temp;

	if (lem_in->found_start == 0 || lem_in->found_end == 0)
		error_message("end or start wasn't found\n");
	temp = lem_in->rooms;
	swap_rooms(lem_in->rooms, get_room_by_id(lem_in->rooms,
											 lem_in->room_start));
	while (temp->next)
		temp = temp->next;
	swap_rooms(temp, get_room_by_id(lem_in->rooms, lem_in->room_end));
	lem_in->room_start = 0;
	lem_in->room_end = lem_in->num_rooms - 1;
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
	if (lem_in->found_link == 0)
	{
		swap_start_end(lem_in);
		lem_in->found_link = 1;
	}
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
		error_message("id == -1 for link");
	lem_in->links[first_id][second_id] = 1;
	lem_in->links[second_id][first_id] = 1;
	free_temp(lem_in, 0);
}

void	fill_struct(t_lem_in *lem_in)
{
	char	*str;

	num_ants(lem_in);
	while (get_next_line(0, &str))
	{
		lem_in->output = ft_strjoin(lem_in->output, str);
		if (ft_strequ(str, "jope"))//for debug
			break;
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
			error_message(lem_in->output);
	}
}

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
//perepisat
int		last_checked(t_lem_in *lem_in)
{
	int		i;

	i = 0;
	while (i < lem_in->num_rooms - 1
		   && lem_in->checked[i] != -1)
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
		if (temp->way[i] != -1)
			temp->length++;
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
 *  flag = 2 - del queue_last
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

int		is_visited(t_lem_in *lem_in, int last_queue)
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

void	move_in(t_lem_in *lem_in, int *queue)
{
	int 	i;
	int 	last;

	while (!(queue[0] == 0 && queue[1] == -1) && queue[0] != -1)
	{
		i = 0;
		while (queue[i] != -1)
			i++;
		last = queue[i - 1];
		if (last != -1
			&& !is_visited(lem_in, last))
		{
			i = 0;
			while (i < lem_in->num_rooms)
			{
				if (lem_in->checked[i] == -1)
					break;
				i++;
			}
			lem_in->checked[i] = last;
			del_last(lem_in, queue, 2);
			depth_first_search(lem_in);
		}
		if (is_visited(lem_in, last))
			del_last(lem_in, queue, 2);
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

void	fill_graph(t_lem_in *lem_in)
{
	if (!(lem_in->found_link))
		error_message("didnt found link");
	init_path_checked_used(lem_in);
	depth_first_search(lem_in);
	if (lem_in->ways == NULL)
		error_message("zero ways found");
}

void		sort_ways(t_lem_in *lem_in)
{
	t_way	*way;
	t_way	*temp;

	way = lem_in->ways;
	while (way->next)
	{
		if (way->length > way->next->length)
		{
			temp = (t_way*)malloc(sizeof(t_way));
			temp->way = way->way;
			temp->length = way->length;
			way->way = way->next->way;
			way->length = way->next->length;
			way->next->way = temp->way;
			way->next->length = temp->length;
			free(temp);
			way = lem_in->ways;
		}
		else
			way = way->next;
	}
}

int		room_in_way(int num_rooms, int *way, int room)
{
	int	i;

	i = 1;
	while (i < num_rooms && way[i] != -1)
	{
		if (way[i] == room)
			return (1);
		i++;
	}
	return (0);
}

void		remove_way(t_way **head, t_way **current)
{
	t_way	*prev;
//	t_way	*head;

	//head = *path;
//	if (head == *current)
//	{
//		if (head == NULL)
//			return ;
//		head->way = head->next->way;
//		head->next = head->next->next;
//		free((*current)->way);
//		free((*current));
//		return ;
//	}
	prev = *head;
	while (prev->next && prev->next != *current)
		prev = prev->next;
	if (prev->next != NULL)
	{
		prev->next = prev->next->next;
		free((*current)->way);
		free((*current));
	}
}

void			clear_ways(t_lem_in *lem_in)
{
	t_way		*prev;
	t_way		*next;
	int			i;

	prev = lem_in->ways;
	while (prev)
	{
		i = 1;
		while (i < lem_in->num_rooms && prev->way[i] != -1)
		{
			if (prev->way[i] == lem_in->num_rooms - 1 ||
					prev->next == NULL)
				break ;
			next = prev->next;
			while (next)
			{
				if (room_in_way(lem_in->num_rooms, next->way, prev->way[i]))
					remove_way(&(lem_in->ways), &(next));
				next = next->next;
			}
			i++;
		}
		prev = prev->next;
	}
}

int		room_position(int *current_way, int way_length, int room_id)
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

void		show_move(int ant_id, char *room_name)
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
				if (next_room->id == lem_in->num_rooms - 1)
				{
					lem_in->num_ants--;
					lem_in->finished_ants[lem_in->iter] = 0;
				}
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
	int 		ant_id;

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
	int 		i;

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

void			free_rooms(t_room *rooms)
{
	t_room		*temp;

	while (rooms)
	{
		temp = rooms;
		rooms = rooms->next;
		free(temp->name);
		free(temp);
	}
}

void			free_ways(t_way *ways)
{
	t_way		*temp;

	while (ways)
	{
		temp = ways;
		ways = ways->next;
		free(temp->way);
		free(temp);
	}
}

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
	free_rooms(lem_in->rooms);
	free_ways(lem_in->ways);
	free_lem_in(lem_in);
}

int		main(int argc, char **argv)
{
	t_lem_in	*lem_in;

	init_struct(&lem_in);
	fill_struct(lem_in);
	fill_graph(lem_in);
	ft_putstr(lem_in->output);
	sort_ways(lem_in);
	clear_ways(lem_in);
	push_ants(lem_in);
	free_struct(lem_in);
	return (0);
}