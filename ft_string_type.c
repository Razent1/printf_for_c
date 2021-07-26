/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 01:35:07 by ilya              #+#    #+#             */
/*   Updated: 2021/01/19 04:31:01 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_signs(int wid, char ch)
{
	int len;

	len = 0;
	while (wid > 0)
	{
		ft_putchar(ch);
		len++;
		wid--;
	}
	return (len);
}

int		print_str(int prec, const char *str)
{
	int	len;

	len = 0;
	if (prec > 0)
	{
		while (str[len] != '\0' && prec > 0)
		{
			ft_putchar(str[len]);
			len++;
			prec--;
		}
	}
	else if (prec < 0)
	{
		while (str[len] != '\0')
		{
			ft_putchar(str[len]);
			len++;
		}
	}
	return (len);
}

int		ft_print_string(t_mod *md, const char *str)
{
	int len;
	int str_len;

	len = 0;
	if (md->precision >= 0 && (int)ft_strlen(str) > md->precision)
		str_len = md->precision;
	else
		str_len = ft_strlen(str);
	if (md->minus)
	{
		len = print_str(md->precision, str);
		len += print_signs(md->width - len, ' ');
	}
	else if (md->zero)
	{
		len = print_signs(md->width - str_len, '0');
		len += print_str(md->precision, str);
	}
	else
	{
		len = print_signs(md->width - str_len, ' ');
		len += print_str(md->precision, str);
	}
	return (len);
}

int		ft_string_type(t_mod *md, va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (str == NULL)
		md->len = ft_print_string(md, "(null)");
	else
		md->len = ft_print_string(md, str);
	return (md->len);
}
