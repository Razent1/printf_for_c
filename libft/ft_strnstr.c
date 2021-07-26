/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashley <aashley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:54:49 by aashley           #+#    #+#             */
/*   Updated: 2020/11/17 16:59:03 by aashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *str, const char *ptr, size_t size)
{
	unsigned int	i;
	size_t			fnd_size;

	if (*ptr == '\0')
		return (char *)str;
	fnd_size = ft_strlen(ptr);
	i = 0;
	while (*str)
	{
		if (i + fnd_size > size)
			return (NULL);
		if (ft_strncmp(str, ptr, fnd_size) == 0)
			return ((char *)(str));
		str++;
		i++;
	}
	return (NULL);
}
