/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashley <aashley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:54:21 by aashley           #+#    #+#             */
/*   Updated: 2020/11/17 16:59:03 by aashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (dest[i] != '\0' && size > i)
		i++;
	if (size <= i)
		return (i + ft_strlen(src));
	l = i;
	while (i < size - 1 && src[i - l] != '\0')
	{
		dest[i] = src[i - l];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src) + l);
}
