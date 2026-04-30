/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_scaling_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:31:43 by lgranger          #+#    #+#             */
/*   Updated: 2025/12/22 09:56:55 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	print_controls(void)
{
	ft_printf("====== Controls ======\n");
	ft_printf("Press R to reset.\n");
	ft_printf("Use the arrows to rotate.\n");
	ft_printf("Press 1 for isometric projection.\n");
	ft_printf("Press 2 for perspective projection.\n");
	ft_printf("Scroll up to zoom in, down to zoom out.\n");
	ft_printf("Press A, S, D or W to translate.\n");
	ft_printf("Press ESC to close the window.\n");
}

void	translate_map(t_data *data, int keycode)
{
	if (keycode == K_D)
		data->offset_x += 5.0;
	if (keycode == K_A)
		data->offset_x -= 5.0;
	if (keycode == K_W)
		data->offset_y -= 5.0;
	if (keycode == K_S)
		data->offset_y += 5.0;
	re_draw(data);
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
	if (range <= 1)
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
