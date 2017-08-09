/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:25:05 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/19 13:33:54 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FT_PRINTF_H
# define FT_PRINTF_FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <stdint.h>

typedef struct			s_spec_list
{
	int					flag[5];
	int					width;
	int					length;
	int					precission;
	int					parameter;
	char				type;
	size_t				n_len;
	int					if_prec;
	int					if_sl;
	int					if_p;
	int					len;
	int					point;
	int					prev;
	struct s_spec_list	*next;
}						t_spec_list;

typedef struct			s_for_chk_l
{
	int					flag;
	int					width;
	int					length;
	int					precission;
	int					if_prec;
	int					parameter;
	struct s_for_chk_l	*next;
}						t_for_chk_l;

typedef struct			s_param_list
{
	int					*link;
	int					count_bytes;
	struct s_param_list	*next;
}						t_param_list;

int						ft_printf(const char *format, ...);
int						ret_point(const char *str, int i, va_list va_lst,
		t_param_list *param);
t_spec_list				*ft_new_spec_lst(void);
t_for_chk_l				*ft_new_fcl(void);
t_param_list			*param_list();
int						if_param(const char *str, int *point, int *prev);
int						what_a_param(const char *str, int point);
int						if_flag(const char *ch, int *point);
void					what_the_flag(const char *ch, t_spec_list *list,
		int prev);
char					*with_plus(char *num, intmax_t number);
int						if_width(const char *str, int *point, int *prev);
void					what_the_width(const char *str, int point,
		t_spec_list *list, va_list v_lst);
int						if_precision(const char *str, int *point);
void					what_a_precision(const char *str, int *point,
		t_spec_list *list, va_list v_lst);
char					*num_precis(int precis, char *num);
int						if_length(const char *str, int *point, int *prev);
void					what_the_length(const char *str, int point,
		t_spec_list *list);
int						if_type(const char *str, int *point, int *prev);
void					what_the_type(const char *str, int point,
		t_spec_list *list);
void					out_arg(t_spec_list *list, va_list v_lst,
		t_for_chk_l *fcl, t_param_list *param);
char					*with_min(t_spec_list *list, char *with_width,
		char *num, int len);
char					*without_min(t_spec_list *list, char *with_width,
		char *num, int len);
char					*act_width(t_spec_list *list, char *num, intmax_t dec);
void					str_ret(t_spec_list *list, char *str, t_for_chk_l *fcl);
void					*ft_ret_str_width(char *str, t_spec_list *lst);
void					*ft_ret_str_precision(char *str, size_t precision,
		t_spec_list *list);
uintmax_t				get_arg_type(t_spec_list *list, va_list v_lst,
		t_param_list *param);
char					get_ch_arg(va_list v_lst);
char					*get_str_arg(t_spec_list *list, va_list v_lst);
uintmax_t				get_arg(t_spec_list *list, va_list v_lst,
		t_param_list *param);
void					nothing_ret(t_param_list *param, size_t link);
void					ch_ret(t_spec_list *list, unsigned char ch,
		t_param_list *param);
void					*for_hex(t_spec_list *list, char *num, uintmax_t dec);
void					*hex_ret(t_spec_list *list, uintmax_t num, int base);
void					ft_addition(const uint32_t symbol, char *wc);
char					*ft_get_wchar(wchar_t symbol);
char					*get_wchar_arg(va_list v_lst);
void					w_char_ret(t_spec_list *list, char *wch,
		t_param_list *param);
char					*dec_ret(t_spec_list *list, intmax_t arg, int base);
char					*unsigned_ret(t_spec_list *list, uintmax_t arg,
		unsigned int base);
intmax_t				get_dec(t_spec_list *list, va_list v_lst);
uintmax_t				get_u(t_spec_list *list, va_list v_lst);
uintmax_t				get_o(t_spec_list *list, va_list v_lst);
char					*oct_ret(t_spec_list *list, uintmax_t arg,
		unsigned int base);
uintmax_t				get_x(t_spec_list *list, va_list v_lst);
char					*heks_ret(t_spec_list *list, uintmax_t arg,
		unsigned int base);
char					*octal_ret(t_spec_list *lst,
		char *num, t_param_list *param);
char					*check_prec_width(t_spec_list *list,
		char *num, uintmax_t dec);

#endif
