/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashley <aashley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:53:19 by aashley           #+#    #+#             */
/*   Updated: 2020/11/17 16:59:03 by aashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *arr, int c, size_t size)
{
	size_t			i;
	unsigned char	*dest;

	i = 0;
	dest = (unsigned char *)arr;
	c = (unsigned char)c;
	while (size > i)
	{
		if (dest[i] == c)
			return ((void *)arr + i);
		i++;
	}
	return (NULL);
}
