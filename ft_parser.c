/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:16:12 by ilya              #+#    #+#             */
/*   Updated: 2021/01/19 00:21:49 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_parse(const char **format, t_mod *fl)
{
	while (ft_strchr("0-", **format) && **format != '\0')
	{
		if (**format == '-')
			fl->minus = 1;
		else if (**format == '0')
			fl->zero = 1;
		(*format)++;
	}
}

void	ft_width_parse(const char **format, t_mod *wd, va_list *args)
{
	if (**format == '*')
	{
		while (**format == '*')
		{
			wd->width = va_arg(*args, int);
			if (wd->width < 0)
			{
				wd->minus = 1;
				wd->width *= -1;
			}
			(*format)++;
		}
	}
	else if (ft_isdigit(**format))
		parse_numbers(format, wd, 'w');
}

void	ft_precision_parse(const char **format, t_mod *pr, va_list *args)
{
	while (**format == '.')
	{
		pr->precision = 0;
		(*format)++;
		if (**format == '*')
		{
			while (**format == '*')
			{
				pr->precision = va_arg(*args, int);
				(*format)++;
			}
		}
		else if (ft_isdigit(**format))
			parse_numbers(format, pr, 'p');
	}
}

void	ft_type_parse(const char **format, t_mod *tp)
{
	if (**format == '%')
		tp->type = '%';
	else if (**format == 'd')
		tp->type = 'd';
	else if (**format == 'i')
		tp->type = 'i';
	else if (**format == 'u')
		tp->type = 'u';
	else if (**format == 'c')
		tp->type = 'c';
	else if (**format == 's')
		tp->type = 's';
	else if (**format == 'p')
		tp->type = 'p';
	else if (**format == 'x')
		tp->type = 'x';
	else if (**format == 'X')
		tp->type = 'X';
}

int		ft_parser(const char **format, va_list *args, t_mod *md)
{
	int	len;

	len = 0;
	md->minus = 0;
	md->zero = 0;
	md->precision = -1;
	md->width = 0;
	md->type = 0;
	ft_flags_parse(format, md);
	ft_width_parse(format, md, args);
	ft_precision_parse(format, md, args);
	ft_type_parse(format, md);
	if (**format != '\0' && md->type != 0)
	{
		(*format)++;
		len = ft_processor(md, md->type, args);
	}
	return (len);
}
