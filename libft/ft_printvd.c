/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printvd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:50:14 by lgranger          #+#    #+#             */
/*   Updated: 2025/10/27 11:04:10 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printadress(unsigned long long s, char *base)
{
	int	count;

	count = 0;
	if (s >= 16)
	{
		count += ft_printadress((s / 16), base);
		count += ft_printadress((s % 16), base);
	}
	else
		count += ft_printchar(base[s]);
	return (count);
}

int	ft_printvd(unsigned long long s, char *base)
{
	int	count;

	count = 0;
	if (!s)
		return (ft_printstr("(nil)"));
	count += ft_printstr("0x");
	count += ft_printadress(s, base);
	return (count);
}
