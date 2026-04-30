/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:44:12 by lgranger          #+#    #+#             */
/*   Updated: 2025/10/27 11:03:47 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkchar(char c, va_list list, int count)
{
	if (c == 'c')
		count += ft_printchar(va_arg(list, int));
	else if (c == 's')
		count += ft_printstr(va_arg(list, char *));
	else if (c == 'p')
		count += ft_printvd((unsigned long long)va_arg(list, void *),
				"0123456789abcdef");
	else if (c == 'd' || c == 'i')
		count += ft_printint(va_arg(list, int));
	else if (c == 'u')
		count += ft_printunsignedint(va_arg(list, unsigned int));
	else if (c == 'x')
		count += ft_printint_hexa(va_arg(list, unsigned int),
				"0123456789abcdef");
	else if (c == 'X')
		count += ft_printint_hexa(va_arg(list, unsigned int),
				"0123456789ABCDEF");
	else if (c == '%')
		count += ft_printchar('%');
	return (count);
}
