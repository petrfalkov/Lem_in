/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:22:06 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/21 15:27:52 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*lstpush_back(t_gnl **start, t_gnl *new_node)
{
	t_gnl	*node_start;

	if (start)
	{
		if (*start)
		{
			node_start = *start;
			while (node_start->next)
				node_start = node_start->next;
			node_start->next = new_node;
		}
		else
			*start = new_node;
	}
	return (new_node);
}

static int		get_smal_line(char **temp, char ***line)
{
	int		len;
	int		n;

	n = ft_strchr(*temp, '\n');
	while ((len = ft_strlen(*temp)))
	{
		if (n == -1 && len <= BUFF_SIZE)
		{
			**line = ft_strjoin(**line, ft_strsub(*temp, 0, len));
			*temp = ft_strnew(0);
			return (1);
		}
		else if (n == -1 && len > BUFF_SIZE)
		{
			**line = ft_strjoin(**line, ft_strsub(*temp, 0, BUFF_SIZE));
			*temp = ft_strsub(*temp, BUFF_SIZE, len - BUFF_SIZE);
		}
		else if (n != -1 && len >= BUFF_SIZE)
		{
			**line = ft_strjoin(**line, ft_strsub(*temp, 0, n));
			*temp = ft_strsub(*temp, n + 1, len - n - 1);
			return (1);
		}
	}
	return (0);
}

static int		get_big_line(char **temp, char ***line)
{
	int		len;
	int		n;

	n = ft_strchr(*temp, '\n');
	while ((len = ft_strlen(*temp)))
	{
		if (n == -1 && len < BUFF_SIZE)
		{
			**line = ft_strjoin(**line, ft_strsub(*temp, 0, len));
			*temp = ft_strnew(0);
			return (1);
		}
		else if (n != -1 && len <= BUFF_SIZE)
		{
			**line = ft_strjoin(**line, ft_strsub(*temp, 0, n));
			*temp = ft_strsub(*temp, n + 1, len - n - 1);
			return (1);
		}
	}
	return (0);
}

static int		get_line(t_gnl *this, int fd, char **line)
{
	int			bt;
	char		*buff;

	buff = ft_strnew(BUFF_SIZE);
	while ((bt = read(fd, buff, BUFF_SIZE)))
	{
		this->temp = ft_strjoin(this->temp, buff);
		buff = ft_strnew(BUFF_SIZE);
	}
	if (BUFF_SIZE > ft_strlen(this->temp))
		return (get_big_line(&this->temp, &line));
	else
		return (get_smal_line(&this->temp, &line));
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*mulfd = NULL;
	t_gnl			*this;

	if (read(fd, NULL, 0) == -1 || !line || fd < 0)
		return (-1);
	*line = ft_strnew(0);
	if (mulfd == NULL)
	{
		mulfd = ft_lstnew(fd);
		this = mulfd;
	}
	else
	{
		this = mulfd;
		while (this != NULL)
		{
			if (this->fd == fd)
				break ;
			this = this->next;
		}
		if (this == NULL)
			this = lstpush_back(&mulfd, ft_lstnew(fd));
	}
	return (get_line(this, fd, line));
}
