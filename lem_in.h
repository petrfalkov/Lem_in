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
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/ft_printf.h"

typedef struct		s_lem_in {
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
