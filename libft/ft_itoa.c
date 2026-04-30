/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:43:49 by lgranger          #+#    #+#             */
/*   Updated: 2025/10/12 14:18:32 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_size(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		i = 1;
		return (i);
	}
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char		*dest;
	size_t		i;
	size_t		count;
	long int	n;

	i = 0;
	n = nbr;
	count = ft_count_size(nbr);
	dest = (char *)ft_calloc(count + 1, sizeof(char));
	if (!dest)
		return (NULL);
	dest[count] = '\0';
	if (n < 0)
	{
		n *= -1;
		dest[0] = '-';
		i++;
	}
	while (count > i)
	{
		count --;
		dest[count] = (n % 10) + 48;
		n /= 10;
	}
	return (dest);
}
