/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 13:35:11 by ichubare          #+#    #+#             */
/*   Updated: 2017/08/08 13:35:13 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/ft_printf.h"

typedef struct		s_room {
	char 			*name;
	int 			coord_x;
	int 			coord_y;
	int				id;
	int 			ant_id;
	struct s_room	*next;
}					t_room;

typedef struct			s_way
{
	int					*way;
	int					length;
	struct s_way		*next;
}						t_way;

typedef struct		s_lem_in {
	t_room			*rooms;
	char 			*output;
	int 			**links;
	t_way			*ways;
	char 			**temp_room;
	char 			**temp_link;
	int				room_start;
	int				room_end;
	int 			flag_rooms;
	int				num_rooms;
	int				num_ants;
	int				num_ways;
	int 			*used_rooms;
	int 			*path;
	int 			*checked;
	int 			*finished_ants;
	int 			found_start;
	int 			found_end;
	int 			found_link;
	int 			iter;
}					t_lem_in;

void				depth_first_search(t_lem_in *lem_in);
void				free_struct(t_lem_in *lem_in);
void				push_ants(t_lem_in *lem_in);
void				clear_ways(t_lem_in *lem_in);
void				sort_ways(t_lem_in *lem_in);
void				fill_graph(t_lem_in *lem_in);
void				error_message(char *str);
t_room				*get_room_by_id(t_room *rooms, int id);
void				del_last(t_lem_in *lem_in, int *queue, int flag);
void				new_way(t_lem_in *lem_in);
int					last_checked(t_lem_in *lem_in);
void				init_path_checked_used(t_lem_in *lem_in);


#endif
