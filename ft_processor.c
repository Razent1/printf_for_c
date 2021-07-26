/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 01:32:39 by ilya              #+#    #+#             */
/*   Updated: 2021/01/19 01:32:44 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_processor(t_mod *md, char type, va_list *args)
{
	if (type == 'd' || type == 'i')
		md->len = ft_int_type(md, args);
	else if (type == 'u')
		md->len = ft_un_int_type(md, args);
	else if (type == 'c')
		md->len = ft_char_type(md, args);
	else if (type == 's')
		md->len = ft_string_type(md, args);
	else if (type == 'p')
		md->len = ft_pointer_type(md, args);
	else if (type == 'x' || type == 'X')
		md->len = ft_x_type(md, args, type);
	else if (type == '%')
		md->len = ft_prec_type(md);
	return (md->len);
}
