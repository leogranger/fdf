/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:48:23 by lgranger          #+#    #+#             */
/*   Updated: 2025/10/27 11:04:03 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		count;

	va_start(list, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count = ft_checkchar(str[i + 1], list, count);
			i++;
		}
		else if (str[i] != '%')
		{
			write(1, &str[i], 1);
			count += 1;
		}
		i++;
	}
	va_end(list);
	return (count);
}

// int	main()
// {
// 	int	c;
// 	int	d;
// 	c = printf("%X \n", 15);
// 	d = ft_printf("%X \n", 15);
// 	printf("%d\n", c);
// 	printf("%d\n", d);
// }