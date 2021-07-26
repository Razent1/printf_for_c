/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashley <aashley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:54:53 by aashley           #+#    #+#             */
/*   Updated: 2020/11/17 16:59:03 by aashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int c)
{
	size_t	i;
	int		res;

	i = 0;
	res = -1;
	while (str[i])
	{
		if (str[i] == (char)c)
			res = i;
		i++;
	}
	if ((char)c == '\0')
		return (char *)&str[i];
	if (res >= 0)
		return (char *)&str[res];
	return (NULL);
}
