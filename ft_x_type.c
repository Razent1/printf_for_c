/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:55:54 by ilya              #+#    #+#             */
/*   Updated: 2021/01/19 02:58:42 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_spaces(int wid, int prec, int ptr_len)
{
	int	len;

	len = 0;
	if (prec > ptr_len)
		wid -= prec;
	else
		wid -= ptr_len;
	while (wid > 0)
	{
		ft_putchar(' ');
		len++;
		wid--;
	}
	return (len);
}

static int		print_str(t_mod *md, int len, char *str, int zero_val)
{
	if (len == 1 && md->precision == 0 && zero_val)
		len = (len - 1) + print_spaces(md->width, md->precision, len - 1);
	else if (!md->zero || md->precision >= 0 || md->minus)
	{
		if (md->precision < md->width && !md->minus)
		{
			len = len + print_spaces(md->width, md->precision, len) +
			print_prec(md->precision, len);
			reverse(str);
		}
		else
		{
			len += print_prec(md->precision, len);
			reverse(str);
			len += print_spaces(md->width, md->precision, len);
		}
	}
	else
	{
		len = len + print_zeros(md->width, len);
		reverse(str);
	}
	return (len);
}

static int		print_x(t_mod *md, char type, unsigned int num)
{
	char	str[16];
	char	digits[16];
	int		len;
	int		zero_val;

	len = 0;
	zero_val = 0;
	fill_array(digits, type);
	if (num == 0)
	{
		str[len] = 48;
		zero_val = 1;
		len++;
	}
	while (num != 0)
	{
		str[len] = digits[num - num / 16 * 16];
		num /= 16;
		len++;
	}
	str[len] = '\0';
	len = print_str(md, len, str, zero_val);
	return (len);
}

int				ft_x_type(t_mod *md, va_list *args, char type)
{
	unsigned int	num;

	num = va_arg(*args, unsigned int);
	md->len = print_x(md, type, num);
	return (md->len);
}
