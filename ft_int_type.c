/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:06:26 by ilya              #+#    #+#             */
/*   Updated: 2021/01/19 00:10:56 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_zero(int prec, int *num)
{
	int	len;

	len = 0;
	while (prec > 0)
	{
		if (*num < 0)
		{
			ft_putchar('-');
			*num *= -1;
			len++;
		}
		ft_putchar('0');
		prec--;
		len++;
	}
	return (len);
}

static int		print_non_prec(int wid, int num, int zero, int minus)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(num);
	wid -= ft_strlen(str);
	if (minus)
	{
		len += print_int_num(num);
		zero = 0;
	}
	if (minus || !zero)
		len += print_int_un_sapces(wid);
	if (zero)
		len += print_zero(wid, &num);
	if (!minus)
		len += print_int_num(num);
	free(str);
	return (len);
}

static int		print_minus(int wid, int prec, int num, int s_len)
{
	int len;
	int neg;
	int prec_len;
	int wid_len;

	len = 0;
	neg = 0;
	wid_len = wid;
	prec_len = prec;
	if (num < 0)
		neg = 1;
	if (wid > prec && s_len > prec)
		wid -= s_len;
	else
		wid -= prec;
	if (prec != 0 || num != 0)
		prec_len -= s_len;
	else if (wid_len != 0)
		wid += 1;
	len += print_zero(prec_len, &num);
	if (prec != 0 || num != 0)
		len += print_int_num(num);
	len += print_int_un_sapces(neg ? wid - 1 : wid);
	return (len);
}

static int		print_non_minus(int wid, int prec, int num, int s_len)
{
	int	len;
	int	prec_len;
	int	wid_len;

	len = 0;
	wid_len = wid;
	prec_len = prec;
	if (wid > prec && s_len > prec)
		wid -= s_len;
	else
		wid -= prec;
	if (prec != 0 || num != 0)
		prec_len -= s_len;
	else if (wid_len != 0)
		wid += 1;
	len += print_int_un_sapces(num < 0 ? wid - 1 : wid);
	len += print_zero(prec_len, &num);
	if (prec != 0 || num != 0)
		len += print_int_num(num);
	return (len);
}

int				ft_int_type(t_mod *md, va_list *args)
{
	int		len;
	int		val;
	int		s_len;
	char	*str;

	val = (int)va_arg(*args, int);
	len = 0;
	str = ft_itoa(val < 0 ? val * -1 : val);
	s_len = ft_strlen(str);
	if (md->minus && md->precision >= 0)
		len = print_minus(md->width, md->precision, val, s_len);
	else if (!md->minus && md->precision >= 0)
		len = print_non_minus(md->width, md->precision, val, s_len);
	else if (md->precision <= 0)
		len = print_non_prec(md->width, val, md->zero, md->minus);
	free(str);
	return (len);
}
