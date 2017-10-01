/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 14:10:47 by ichubare          #+#    #+#             */
/*   Updated: 2017/10/01 14:10:49 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_start(char *str, t_lem_in *lem_in)
{
	if (!ft_strequ(str, "##start"))
		return (0);
	lem_in->found_start = 1;
	lem_in->flag_rooms = 1;
	return (1);
}

int			is_end(char *str, t_lem_in *lem_in)
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
	error_message();
	return (0);
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
	free(temp);
}
