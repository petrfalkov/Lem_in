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
#include <string.h>
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

int 	already_exists(char *new_room, t_lem_in *lem_in)
{
	return (1);
}

int 	is_room(char *str, )
{
	int 	i;
	int 	count_spaces;
	char 	**room;

	i = 0;
	count_spaces = 0;
	while (str[i])
		if (str[i++] == ' ')
			count_spaces++;
	if (count_spaces != 2)
		return (0);
	room = ft_strsplit(str, ' ');
	if (room[0][0] == 'L')
		return (0);
	if (!(is_all_digit(room[1]) && is_all_digit(room[2])))
		error_message();
	if (already_exists(room[0], ))//write!
	return (1);
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
		else if (!lem_in->found_link && is_room(str))
			dsfa;
		else if (!lem_in->found_start && !lem_in->found_link && is_start())
			gfsg;
		else if (!lem_in->found_end && !lem_in->found_link && is_end())
			gshgdf;
		else if (is_link())
			fsdfsd;
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