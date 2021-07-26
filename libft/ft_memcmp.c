/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashley <aashley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:53:25 by aashley           #+#    #+#             */
/*   Updated: 2020/11/17 16:59:03 by aashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t size)
{
	unsigned int	i;
	unsigned char	*mem_s1;
	unsigned char	*mem_s2;

	i = 0;
	mem_s1 = (unsigned char *)s1;
	mem_s2 = (unsigned char *)s2;
	if (size == 0)
		return (0);
	while (size-- > 0)
	{
		if (mem_s1[i] > mem_s2[i])
			return ((int)mem_s1[i] - (int)mem_s2[i]);
		else if (mem_s1[i] < mem_s2[i])
			return (-1 * (int)(mem_s2[i] - mem_s1[i]));
		i++;
	}
	return (0);
}
