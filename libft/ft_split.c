/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 09:58:01 by lgranger          #+#    #+#             */
/*   Updated: 2025/11/25 16:57:20 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countstr(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	*ft_free(char **arr, size_t y)
{
	size_t	i;

	i = 0;
	while (i < y)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

static char	**ft_putarray(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	y;

	i = 0;
	y = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
		{
			i++;
		}
		arr[y] = ft_substr(s, start, i - start);
		if (!arr[y])
			return (ft_free(arr, y), NULL);
		y++;
	}
	arr[y] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	count;

	count = ft_countstr(s, c);
	arr = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	if (!ft_putarray(arr, s, c))
		return (NULL);
	return (arr);
}
