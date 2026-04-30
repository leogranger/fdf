/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:12:34 by lgranger          #+#    #+#             */
/*   Updated: 2025/10/27 11:03:58 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *s)
{
	int	j;

	j = 0;
	if (!s)
		return (ft_printstr("(null)"));
	while (s[j])
	{
		write(1, &s[j], 1);
		j++;
	}
	return (j);
}

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}
