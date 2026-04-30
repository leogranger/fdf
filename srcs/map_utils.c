/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 09:19:54 by lgranger          #+#    #+#             */
/*   Updated: 2025/12/18 14:51:20 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	allocate_mem(t_data *data)
{
	data->map->land = ft_calloc((data->map->height + 1), sizeof(t_point **));
	if (!data->map->land)
		ft_error("Couldn't allocate memory to land.", data);
	data->map->land[data->map->height] = NULL;
	allocate_rows(data, data->map->height, data->map->len);
	allocate_columns(data, data->map->height, data->map->len);
}

bool	is_hexdigits(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || c == 'F')
		return (1);
	return (0);
}

int	find_linelength(char *s)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] && s[i] == 32)
			i++;
		if (!s[i])
			break ;
		len++;
		while (s[i] && s[i] != 32)
			i++;
	}
	return (len);
}

int	find_map_height(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->landscape[i])
	{
		i++;
	}
	return (i);
}

bool	check_length(t_data *data)
{
	int	len_1;
	int	len_2;
	int	i;

	i = 0;
	while (data->map->landscape[i + 1])
	{
		len_1 = find_linelength(data->map->landscape[i]);
		len_2 = find_linelength(data->map->landscape[i + 1]);
		if (len_1 != len_2)
			return (false);
		i++;
	}
	data->map->len = len_1;
	data->map->height = find_map_height(data);
	return (true);
}
