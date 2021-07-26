/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashley <aashley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:53:29 by aashley           #+#    #+#             */
/*   Updated: 2020/11/17 16:59:03 by aashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned int	i;
	unsigned char	*dest_point;
	unsigned char	*src_point;

	i = 0;
	dest_point = ((unsigned char *)dest);
	src_point = ((unsigned char *)src);
	if (!size || dest == src)
		return (dest);
	while (size > 0)
	{
		dest_point[i] = src_point[i];
		i++;
		size--;
	}
	return (dest);
}
