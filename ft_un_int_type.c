/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_int_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 04:03:39 by ilya              #+#    #+#             */
/*   Updated: 2021/01/19 04:05:59 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_un_zero(int prec)
{
	int	len;

	len = 0;
	while (prec > 0)
	{
		ft_putchar('0');
		prec--;
		len++;
	}
	return (len);
}

int		print_un_non_prec(int wid, unsigned int num, int zero, int minus)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_un_itoa(num);
	wid -= ft_strlen(str);
	if (minus)
	{
		len += print_un_num(num);
		zero = 0;
	}
	if (minus || !zero)
		len += print_int_un_sapces(wid);
	if (zero)
		len += print_un_zero(wid);
	if (!minus)
		len += print_un_num(num);
	free(str);
	return (len);
}

int		print_un_minus(int wid, int prec, unsigned int num, int s_len)
{
	int len;
	int prec_len;
	int wid_len;

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
	len += print_un_zero(prec_len);
	if (prec != 0 || num != 0)
		len += print_un_num(num);
	len += print_int_un_sapces(wid);
	return (len);
}

int		print_un_non_minus(int wid, int prec, unsigned int num, int s_len)
{
	int len;
	int prec_len;
	int wid_len;

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
	len += print_int_un_sapces(wid);
	len += print_un_zero(prec_len);
	if (prec != 0 || num != 0)
		len += print_un_num(num);
	return (len);
}

int		ft_un_int_type(t_mod *md, va_list *args)
{
	unsigned int	val;
	int				len;
	int				s_len;
	char			*str;

	len = 0;
	val = (unsigned int)va_arg(*args, unsigned int);
	str = ft_un_itoa(val);
	s_len = ft_strlen(str);
	if (md->minus && md->precision >= 0)
		len = print_un_minus(md->width, md->precision, val, s_len);
	else if (!md->minus && md->precision >= 0)
		len = print_un_non_minus(md->width, md->precision, val, s_len);
	else if (md->precision <= 0)
		len = print_un_non_prec(md->width, val, md->zero, md->minus);
	free(str);
	return (len);
}
