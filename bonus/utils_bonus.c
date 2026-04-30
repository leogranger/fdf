/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 09:36:23 by lgranger          #+#    #+#             */
/*   Updated: 2025/12/18 14:48:16 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"
#include <limits.h>
#include <math.h>

void	isometric_mode(t_data *data, t_point *point)
{
	double	iso_x;
	double	iso_y;

	point->visible = 1;
	iso_x = (point->x - point->y) * cos(0.523599);
	iso_y = (point->x + point->y) * sin(0.523599) - (point->z
			* data->map->z_scale);
	point->depth = -1000.0 * (point->x + point->y + point->z);
	point->screen_x = (iso_x * data->zoom) + data->offset_x;
	point->screen_y = (iso_y * data->zoom) + data->offset_y;
}

void	perspective_mode(t_data *data, t_point *point)
{
	double	ry;
	double	rz;

	ry = point->y * cos(0.523599) - point->z * sin(0.523599);
	rz = point->y * sin(0.523599) + point->z * cos(0.523599);
	if (data->distance - rz > 1)
	{
		point->depth = data->distance - rz;
		point->visible = 1;
		point->screen_x = (point->x * data->distance) / (data->distance - rz)
			* data->zoom + data->offset_x;
		point->screen_y = (ry * data->distance) / (data->distance - rz)
			* data->zoom + data->offset_y;
	}
	else
		point->visible = 0;
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

void	draw_horizontal(t_data *data, int h, int l)
{
	int	x;

	while (h >= 0)
	{
		x = l;
		while (x - 1 >= 0)
		{
			if (data->map->land[h][x]->visible && data->map->land[h][x
				- 1]->visible)
				dda_line(data, data->map->land[h][x], data->map->land[h][x
					- 1]);
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
			if (data->map->land[y][l]->visible && data->map->land[y
				- 1][l]->visible)
				dda_line(data, data->map->land[y][l], data->map->land[y
					- 1][l]);
			y--;
		}
		l--;
	}
}
