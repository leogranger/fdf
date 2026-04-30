/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 09:19:24 by lgranger          #+#    #+#             */
/*   Updated: 2025/12/18 14:49:15 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_horizontal(t_data *data, int h, int l)
{
	int	x;

	while (h >= 0)
	{
		x = l;
		while (x - 1 >= 0)
		{
			dda_line(data, data->map->land[h][x], data->map->land[h][x - 1]);
			x--;
		}
		h--;
	}
}

void	draw_vertical(t_data *data, int h, int l)
{
	int	y;

	while (l >= 0)
	{
		y = h;
		while (y - 1 >= 0)
		{
			dda_line(data, data->map->land[y][l], data->map->land[y - 1][l]);
			y--;
		}
		l--;
	}
}

int	find_str(char *s1, char *s2)
{
	while (*s1)
	{
		if (!ft_strncmp(s1, s2, ft_strlen(s2)))
		{
			return (1);
		}
		s1++;
	}
	return (0);
}

void	find_min_max_z(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->map->min_z = data->map->land[0][0]->z;
	data->map->max_z = data->map->land[0][0]->z;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->len)
		{
			if (data->map->land[y][x]->z < data->map->min_z)
				data->map->min_z = data->map->land[y][x]->z;
			if (data->map->land[y][x]->z > data->map->max_z)
				data->map->max_z = data->map->land[y][x]->z;
			x++;
		}
		y++;
	}
}

void	scale_map(t_data *data)
{
	int		x;
	int		y;
	double	range;

	y = 0;
	find_min_max_z(data);
	range = data->map->max_z - data->map->min_z;
	if (range == 0.0)
		data->map->z_scale = 1;
	else
		data->map->z_scale = 10.0 / range;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->len)
		{
			screen_coord(data, data->map->land[y][x]);
			x++;
		}
		y++;
	}
}
