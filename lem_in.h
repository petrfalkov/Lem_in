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
	struct s_room	*next;
}					t_room;

typedef struct		s_lem_in {
	t_room			*rooms;
	char 			**temp_room;
	int				room_start;
	int				room_end;
	int				num_rooms;
	int				num_ants;
	int				**ways;
	int 			found_start;
	int 			found_end;
	int 			found_link;
}					t_lem_in;

#endif
