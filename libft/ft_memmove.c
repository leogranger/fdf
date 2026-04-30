/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 10:53:03 by lgranger          #+#    #+#             */
/*   Updated: 2025/10/12 14:20:36 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_s;
	unsigned char	*temp_d;

	temp_s = (unsigned char *)src;
	temp_d = (unsigned char *)dest;
	if (temp_d < temp_s)
	{
		while (n-- > 0)
			*temp_d++ = *temp_s++;
	}
	if (temp_d > temp_s)
	{
		while (n-- > 0)
			temp_d[n] = temp_s[n];
	}
	return (dest);
}
