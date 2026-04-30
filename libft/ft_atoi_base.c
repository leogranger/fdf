/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:52:48 by lgranger          #+#    #+#             */
/*   Updated: 2025/12/17 08:44:13 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static void	lower_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_tolower(s[i]);
		i++;
	}
}

int	ft_atoi_base(char *nptr)
{
	char	*base;
	int		result;
	int		index;
	int		i;

	lower_str(nptr);
	base = "0123456789abcdef";
	result = 0;
	i = 0;
	if (nptr[i] == '0')
		i++;
	if (nptr[i] == 'x')
		i++;
	while (nptr[i])
	{
		index = get_index(nptr[i], base);
		if (index == -1)
			break ;
		result = (result * 16) + index;
		i++;
	}
	return (result);
}
