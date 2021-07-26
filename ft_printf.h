/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:56:48 by ilya              #+#    #+#             */
/*   Updated: 2021/01/19 01:59:41 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "stdarg.h"
# include "string.h"
# include "stdio.h"
# include "unistd.h"
# include "string.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct		s_mod
{
	int		len;
	int		minus;
	int		zero;
	int		precision;
	int		width;
	char	type;
}					t_mod;
int					ft_printf(const char *str, ...);
int					ft_parser(const char **format, va_list *args, t_mod *md);
void				parse_numbers(const char **format, t_mod *pr, char c);
int					ft_processor(t_mod *md, char type, va_list *args);
int					ft_int_type(t_mod *md, va_list *args);
int					print_int_un_sapces(int wid);
int					print_int_num(int num);
int					print_un_num(unsigned int num);
int					ft_un_int_type(t_mod *md, va_list *args);
int					ft_char_type(t_mod *md, va_list *args);
int					ft_string_type(t_mod *md, va_list *args);
int					ft_pointer_type(t_mod *md, va_list *args);
int					ft_x_type(t_mod *md, va_list *args, char type);
int					ft_prec_type(t_mod *md);
char				*ft_un_itoa(unsigned int n);
void				reverse(char *str);
int					print_zeros(int wid, int ptr_len);
int					print_prec(int prec, int ptr_len);
void				fill_array(char *str, char type);

#endif
