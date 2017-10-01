/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 14:12:40 by ichubare          #+#    #+#             */
/*   Updated: 2017/10/01 14:12:43 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_comment(char *str)
{
	if ((str[0] == '#' && str[1] != '#') || (ft_strnequ(str, "###", 3)))
		return (1);
	return (0);
}

void	num_ants(t_lem_in *lem_in)
{
	char	*str;
	int		num_ants;
	int		i;

	if (read(0, NULL, 0) == -1)
		error_message();
	while (get_next_line(0, &str) && !ft_isdigit(str[0]))
		!is_comment(str) ? error_message() : 0;
	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			error_message();
	num_ants = ft_atoi(str);
	if (num_ants <= 0)
		error_message();
	join_fn(lem_in, str);
	free(str);
	lem_in->num_ants = num_ants;
}

int		is_all_digit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

int		is_alnum(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		if (!ft_isalnum(str[i++]))
			return (0);
	return (1);
}
