/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 09:34:26 by lgranger          #+#    #+#             */
/*   Updated: 2025/10/12 14:17:02 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbelement, size_t size)
{
	unsigned char	*str;

	if (nbelement == 0 || size == 0)
	{
		return (malloc(0));
	}
	if (nbelement > SIZE_MAX / size)
		return (NULL);
	str = malloc(nbelement * size);
	if (!str)
		return (NULL);
	ft_bzero(str, nbelement * size);
	return (str);
}
