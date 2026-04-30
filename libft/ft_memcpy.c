/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 10:27:55 by lgranger          #+#    #+#             */
/*   Updated: 2025/10/12 14:20:09 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destr;
	unsigned char	*srctr;

	destr = (unsigned char *)dest;
	srctr = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	while (n-- > 0)
	{
		*destr = *srctr;
		srctr++;
		destr++;
	}
	return (dest);
}
