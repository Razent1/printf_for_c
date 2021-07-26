/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:25:05 by ilya              #+#    #+#             */
/*   Updated: 2021/01/19 02:05:11 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_xo(void)
{
	ft_putchar('0');
	ft_putchar('x');
	return (0);
}

static int		print_spaces(int wid, int prec, int ptr_len)
{
	int	len;

	len = 0;
	if (prec > ptr_len)
		wid -= (prec + 2);
	else
		wid = wid - (ptr_len + 2);
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
		len = (len - 1) + (!md->minus ? print_spaces(md->width, md->precision,
		len - 1) + print_xo() : print_xo() +
		print_spaces(md->width, md->precision, len - 1));
	else if (!md->zero || md->precision >= 0 || md->minus)
	{
		if (md->precision < md->width && !md->minus)
		{
			len = len + print_spaces(md->width, md->precision,
			len) + print_xo() + print_prec(md->precision, len);
			reverse(str);
		}
		else
		{
			len += print_xo() + print_prec(md->precision, len);
			reverse(str);
			len += print_spaces(md->width, md->precision, len);
		}
	}
	else
	{
		len = len + print_zeros(md->width, len + 2);
		reverse(str);
	}
	return (len + 2);
}

static int		print_pointer(t_mod *md, unsigned long num)
{
	char	str[16];
	char	digits[16];
	int		len;
	int		zero_val;

	len = 0;
	zero_val = 0;
	fill_array(digits, 'x');
	if (num == 0)
	{
		str[len] = 48;
		len++;
		zero_val = 1;
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

int				ft_pointer_type(t_mod *md, va_list *args)
{
	void			*pointer;
	unsigned long	p;

	pointer = va_arg(*args, void *);
	p = (unsigned long)pointer;
	md->len = print_pointer(md, p);
	return (md->len);
}
