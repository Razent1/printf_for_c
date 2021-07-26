/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 03:00:33 by ilya              #+#    #+#             */
/*   Updated: 2021/01/19 03:00:48 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_numbers(const char **format, t_mod *pr, char c)
{
	int	num;

	num = 0;
	while (ft_isdigit(**format) && **format != '\0')
	{
		num = num * 10 + (**format - 48);
		(*format)++;
	}
	if (c == 'w')
		pr->width = num;
	else if (c == 'p')
		pr->precision = num;
}
