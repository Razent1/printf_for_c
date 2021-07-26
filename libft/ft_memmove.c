/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashley <aashley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:53:40 by aashley           #+#    #+#             */
/*   Updated: 2020/11/17 16:59:03 by aashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*dest_point;
	unsigned char	*src_point;

	i = 0;
	dest_point = (unsigned char *)dest;
	src_point = (unsigned char *)src;
	if (dest == src)
		return ((void *)dest_point);
	if (dest > src)
	{
		i = size;
		while (i-- > 0)
			dest_point[i] = src_point[i];
	}
	else
	{
		while (i < size)
		{
			dest_point[i] = src_point[i];
			i++;
		}
	}
	return ((void *)dest_point);
}
