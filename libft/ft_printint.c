/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:22:59 by lgranger          #+#    #+#             */
/*   Updated: 2025/10/27 11:04:06 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printint(int n)
{
	int			count;
	long int	nbr;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		count += 1;
	}
	if (nbr > 9)
		count += ft_printint(nbr / 10);
	count += ft_printchar((nbr % 10) + 48);
	return (count);
}

int	ft_printint_hexa(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_printint_hexa(n / 16, base);
		count += ft_printint_hexa(n % 16, base);
	}
	else
		count += ft_printchar(base[n]);
	return (count);
}

int	ft_printunsignedint(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_printunsignedint(n / 10);
	count += ft_printchar((n % 10) + 48);
	return (count);
}
