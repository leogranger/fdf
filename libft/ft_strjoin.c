/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:12:31 by lgranger          #+#    #+#             */
/*   Updated: 2025/11/13 15:39:11 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s12;
	int		s1len;
	int		s2len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s12 = (char *)ft_calloc(s1len + s2len + 1, sizeof(char));
	if (!s12)
		return (NULL);
	ft_strlcpy(s12, (const char *)s1, s1len + 1);
	ft_strlcpy(s12 + s1len, (const char *)s2, s2len + 1);
	return (s12);
}
