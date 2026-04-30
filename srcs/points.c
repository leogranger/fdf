/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 09:19:34 by lgranger          #+#    #+#             */
/*   Updated: 2025/12/18 14:49:12 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <limits.h>
#include <math.h>

void	screen_coord(t_data *data, t_point *point)
{
	double	iso_x;
	double	iso_y;

	iso_x = (point->x - point->y) * cos(0.523599);
	iso_y = (point->x + point->y) * sin(0.523599) - (point->z
			* data->map->z_scale);
	point->depth = -1000.0 * (point->x + point->y + point->z);
	point->screen_x = (iso_x * data->zoom) + data->offset_x;
	point->screen_y = (iso_y * data->zoom) + data->offset_y;
}

void	new_point(t_data *data, char *s, int x, int y)
{
	int	white;

	white = 16777215;
	data->map->land[y][x]->x = x - data->map->center_x;
	data->map->land[y][x]->y = y - data->map->center_y;
	data->map->land[y][x]->z = ft_atoi(s);
	data->map->land[y][x]->color = white;
}

void	set_points(t_data *data, char **tmp, int y)
{
	int	x;

	x = 0;
	while (tmp[x])
	{
		new_point(data, tmp[x], x, y);
		x++;
	}
}

void	create_points(t_data *data)
{
	char	**tmp;
	int		y;

	y = 0;
	data->map->center_x = data->map->len / 2;
	data->map->center_y = data->map->height / 2;
	while (y < data->map->height)
	{
		tmp = ft_split(data->map->landscape[y], ' ');
		set_points(data, tmp, y);
		free_tab(tmp);
		y++;
	}
	free_tab(data->map->landscape);
}
