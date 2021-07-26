/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 03:03:11 by ilya              #+#    #+#             */
/*   Updated: 2021/01/19 03:03:14 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_int_un_sapces(int wid)
{
	int	len;

	len = 0;
	while (wid > 0)
	{
		ft_putchar(' ');
		wid--;
		len++;
	}
	return (len);
}

int		print_int_num(int num)
{
	char	*str;
	int		len;

	str = ft_itoa(num);
	len = 0;
	while (str[len])
	{
		ft_putchar(str[len]);
		len++;
	}
	free(str);
	return (len);
}

int		print_un_num(unsigned int num)
{
	char	*str;
	int		len;

	str = ft_un_itoa(num);
	len = 0;
	while (str[len])
	{
		ft_putchar(str[len]);
		len++;
	}
	free(str);
	return (len);
}
