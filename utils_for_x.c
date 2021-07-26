/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 03:03:40 by ilya              #+#    #+#             */
/*   Updated: 2021/01/19 03:04:04 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reverse(char *str)
{
	int len;

	len = (int)(ft_strlen(str) - 1);
	while (len >= 0)
	{
		ft_putchar(str[len]);
		len--;
	}
}

int		print_zeros(int wid, int ptr_len)
{
	int	len;

	len = 0;
	wid -= ptr_len;
	while (wid > 0)
	{
		ft_putchar('0');
		len++;
		wid--;
	}
	return (len);
}

int		print_prec(int prec, int ptr_len)
{
	int len;

	len = 0;
	prec -= ptr_len;
	while (prec > 0)
	{
		ft_putchar('0');
		len++;
		prec--;
	}
	return (len);
}

void	fill_array(char *str, char type)
{
	int	i;
	int dgt;

	i = 0;
	dgt = 48;
	while (ft_isdigit(dgt))
	{
		str[i] = (char)dgt;
		dgt++;
		i++;
	}
	if (type == 'x')
		dgt = 97;
	else if (type == 'X')
		dgt = 65;
	while (i != 16)
	{
		str[i] = (char)dgt;
		dgt++;
		i++;
	}
	str[i] = '\0';
}
