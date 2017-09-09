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

typedef struct 		s_link {
	char 			*link[2];
	int 			used;
	struct s_link	*next;
}					t_link;

typedef struct			s_way
{
	int					*way;
	int					length;
	struct s_way		*next;
}						t_way;

typedef struct		s_lem_in {
	t_room			*rooms;
	int 			**links;
	t_way			*ways;
	char 			**temp_room;
	char 			**temp_link;
	char			*room_start;
	char			*room_end;
	int 			flag_rooms;
	int				num_rooms;
	int				num_ants;
	int				num_ways;
	int 			*used_rooms; //is_visited
	int 			*path; //way
	int 			*checked; //visited
	int 			found_start;
	int 			found_end;
	int 			found_link;
}					t_lem_in;

void				depth_first_search(t_lem_in *lem_in);

#endif
