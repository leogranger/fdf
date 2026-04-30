/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:55:11 by lgranger          #+#    #+#             */
/*   Updated: 2025/10/12 14:25:57 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	realen;
	char	*subs;

	i = 0;
	if (!s)
		return (NULL);
	realen = ft_strlen(s) - start;
	if (realen > len)
		realen = len;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	subs = ft_calloc(realen + 1, sizeof(char));
	if (!subs)
		return (NULL);
	while (i < realen)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
