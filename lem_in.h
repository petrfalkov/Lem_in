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
# include <unistd.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

typedef struct		s_room
{
	char			*name;
	int				coord_x;
	int				coord_y;
	int				id;
	int				ant_id;
	struct s_room	*next;
}					t_room;

typedef struct		s_way
{
	int				*way;
	int				length;
	struct s_way	*next;
}					t_way;

typedef struct		s_lem_in
{
	t_room			*rooms;
	char			*output;
	int				**links;
	t_way			*ways;
	char			**temp_room;
	char			**temp_link;
	int				room_start;
	int				room_end;
	int				flag_rooms;
	int				num_rooms;
	int				num_ants;
	int				num_ways;
	int				*used_rooms;
	int				*path;
	int				*checked;
	int				*finished_ants;
	int				found_start;
	int				found_end;
	int				found_link;
	int				iter;
}					t_lem_in;

typedef struct		s_gnl
{
	char			*temp;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

typedef struct		s_list
{
	int				wasted;
	int				repeat;
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_strrev(char const *str);
void				ft_memclr(void *ptr, size_t len);
void				ft_lstpush_back(t_list **lst, t_list *elem);
t_list				*ft_lstget_node(t_list *lst, size_t index);
int					ft_isspace(int ch);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *restrict dst, const char *restrict src,
								size_t n);
size_t				ft_strlcat(char *restrict dst, const char *restrict src,
								size_t siz);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
								size_t len);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(char *str);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
char				**ft_strsplit(char const *s, char c);
void				ft_striter(char *s, void (*f)(char *));
void				ft_putchar(unsigned char c);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strtrim(char const *s);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *restrict dst, const void *restrict src,
								int c, size_t n);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
							size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new_l);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_itoa_base(intmax_t value, int base);
char				*ft_itoa_base_hex(uintmax_t value, unsigned int base);
int					get_next_line(int fd, char **line);
int					get_next_line2(int fd, char **line);
void				depth_first_search(t_lem_in *lem_in);
void				free_struct(t_lem_in *lem_in);
void				push_ants(t_lem_in *lem_in);
void				clear_ways(t_lem_in *lem_in);
void				sort_ways(t_lem_in *lem_in);
void				fill_graph(t_lem_in *lem_in);
void				error_message(void);
t_room				*get_room_by_id(t_room *rooms, int id);
void				del_last(t_lem_in *lem_in, int *queue, int flag);
void				new_way(t_lem_in *lem_in);
int					last_checked(t_lem_in *lem_in);
void				init_path_checked_used(t_lem_in *lem_in);
void				fill_struct(t_lem_in *lem_in);
void				add_link(t_lem_in *lem_in);
int					find_id(t_lem_in *lem_in, int i);
int					is_link(char *str, t_lem_in *lem_in);
void				swap_start_end(t_lem_in *lem_in);
void				swap_rooms(t_room *current, t_room *swapable);
t_room				*get_room_by_id(t_room *rooms, int id);
void				create_links_matrix(t_lem_in *lem_in);
int					is_end(char *str, t_lem_in *lem_in);
int					is_start(char *str, t_lem_in *lem_in);
void				add_room(t_lem_in *lem_in, int just_room);
void				free_temp(char **temp_rl);
int					is_room(char *str, t_lem_in *lem_in);
int					char_count(char *string, int character);
int					already_exists(char *new_room, t_lem_in *lem_in);
int					is_alnum(char *str);
int					is_all_digit(char *str);
void				num_ants(t_lem_in *lem_in);
int					is_comment(char *str);
void				join_fn(t_lem_in *lem_in, char *str);

#endif
