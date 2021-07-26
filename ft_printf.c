/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 23:34:27 by ilya              #+#    #+#             */
/*   Updated: 2021/01/19 04:06:59 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				print(const char **str, int len)
{
	if (**str != '%' && **str != '\0')
	{
		ft_putchar(**str);
		len++;
		(*str)++;
	}
	return (len);
}

static t_mod			*init_struct(t_mod *pm)
{
	if ((pm = (t_mod *)malloc(sizeof(t_mod))) == NULL)
		return (NULL);
	pm->len = 0;
	return (pm);
}

int						ft_printf(const char *str, ...)
{
	va_list		args;
	t_mod		*mod;
	int			len;

	mod = NULL;
	if ((mod = init_struct(mod)) == NULL)
		return (-1);
	va_start(args, str);
	len = 0;
	while (*str)
	{
		len = print(&str, len);
		if (*str == '%')
		{
			str++;
			len += ft_parser(&str, &args, mod);
		}
	}
	va_end(args);
	free(mod);
	return (len);
}
