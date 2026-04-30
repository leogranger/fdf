/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:48:18 by lgranger          #+#    #+#             */
/*   Updated: 2025/10/12 14:25:39 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trimmer(char const *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimstr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	while (ft_trimmer(set, s1[i]) == 1)
		i++;
	while (ft_trimmer(set, s1[len - 1]) == 1)
		len--;
	trimstr = ft_substr(s1, i, len - i);
	return (trimstr);
}
