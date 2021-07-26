/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashley <aashley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:53:16 by aashley           #+#    #+#             */
/*   Updated: 2020/11/17 16:59:03 by aashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	size_t			i;
	unsigned char	*dest_point;
	unsigned char	*src_point;

	i = 0;
	dest_point = (unsigned char *)dest;
	src_point = (unsigned char *)src;
	while (size > i)
	{
		dest_point[i] = src_point[i];
		if (src_point[i] == (unsigned char)c)
			return ((void *)dest_point + i + 1);
		i++;
	}
	return (NULL);
}
