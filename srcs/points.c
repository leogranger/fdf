/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:25:58 by lgranger          #+#    #+#             */
/*   Updated: 2026/09/09 09:42:31 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <limits.h>
#include <math.h>

void	screen_coord(t_data *data, t_point *point)
{
	if (data->projection_mode == 1)
	{
		isometric_mode(data, point);
	}
	if (data->projection_mode == 2)
	{
		perspective_mode(data, point);
	}
}

void	new_point(t_data *data, char *s, int x, int y)
{
	char	**z_and_color;
	int		white;

	white = 16777215;
	data->map->land[y][x]->x = x - data->map->center_x;
	data->map->land[y][x]->y = y - data->map->center_y;
	if (ft_strrchr(s, ','))
	{
		z_and_color = ft_split(s, ',');
		data->map->land[y][x]->z = ft_atoi(z_and_color[0]);
		data->map->land[y][x]->color = ft_atoi_base(z_and_color[1]);
		free_tab(z_and_color);
	}
	else
	{
		data->map->land[y][x]->z = ft_atoi(s);
		data->map->land[y][x]->color = white;
	}
	data->map->land[y][x]->orig_x = x - data->map->center_x;
	data->map->land[y][x]->orig_y = y - data->map->center_y;
	data->map->land[y][x]->orig_z = data->map->land[y][x]->z;
}

void	set_new_points(t_data *data)
{
	int	x;
	int	y;

	y = 0;
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
