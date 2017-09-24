/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_ways.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:21:12 by ichubare          #+#    #+#             */
/*   Updated: 2017/09/24 16:21:14 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

int			room_in_way(int num_rooms, int *way, int room)
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

void		clear_ways(t_lem_in *lem_in)
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
