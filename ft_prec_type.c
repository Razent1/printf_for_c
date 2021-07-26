/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:52:38 by ilya              #+#    #+#             */
/*   Updated: 2021/01/19 00:53:01 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_wid(int wid, int zero, int minus)
{
	int	len;

	len = 0;
	while (wid > len && (!zero || minus))
	{
		ft_putchar(' ');
		len++;
	}
	while (wid > len && zero && !minus)
	{
		ft_putchar('0');
		len++;
	}
	return (len);
}

int				ft_prec_type(t_mod *md)
{
	int	len;

	len = 1;
	if (md->minus)
	{
		ft_putchar('%');
		len += print_wid(md->width - 1, md->zero, md->minus);
	}
	else
	{
		len += print_wid(md->width - 1, md->zero, md->minus);
		ft_putchar('%');
	}
	return (len);
}
