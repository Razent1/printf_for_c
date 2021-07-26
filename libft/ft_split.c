/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashley <aashley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:54:06 by aashley           #+#    #+#             */
/*   Updated: 2020/11/17 16:59:03 by aashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(const char *str, char c)
{
	int		i;
	int		w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			w++;
		i++;
	}
	return (w);
}

static int	length(char const *str, char c)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		l++;
	}
	return (l);
}

static void	*ft_free(char **str, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**split(char **arr, char const *str, int w, char c)
{
	int		i;
	int		l;
	int		j;

	i = 0;
	while (i < w)
	{
		while (*str == c)
			str++;
		l = length(str, c);
		if (!(arr[i] = (char *)malloc(sizeof(char) * (l + 1))))
			return (ft_free(arr, i));
		j = 0;
		while (j < l)
			arr[i][j++] = *str++;
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	int		w;

	if (!s)
		return (NULL);
	w = words(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (w + 1))))
		return (NULL);
	arr = split(arr, s, w, c);
	return (arr);
}
