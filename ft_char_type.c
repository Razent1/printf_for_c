/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:00:25 by ilya              #+#    #+#             */
/*   Updated: 2021/01/19 00:00:27 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_putstr(int wid, char ch)
{
	int	len;

	len = 0;
	while (wid - 1 > 0)
	{
		ft_putchar(ch);
		wid--;
		len++;
	}
	return (len);
}

static int		ft_print_char(int minus, int wid, int zero, char c)
{
	int len;

	len = 0;
	if (minus)
	{
		ft_putchar(c);
		len = ft_putstr(wid, ' ');
	}
	else if (zero)
	{
		len = ft_putstr(wid, '0');
		ft_putchar(c);
	}
	else
	{
		len = ft_putstr(wid, ' ');
		ft_putchar(c);
	}
	return (len + 1);
}

int				ft_char_type(t_mod *md, va_list *args)
{
	char c;

	c = (char)va_arg(*args, int);
	md->len = ft_print_char(md->minus, md->width, md->zero, c);
	return (md->len);
}
