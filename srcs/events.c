/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:47:50 by lgranger          #+#    #+#             */
/*   Updated: 2026/09/09 09:42:05 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "math.h"

int	close_win(t_data *data)
{
	if (data->mlx && data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	ft_error("The window was closed.", data);
	return (0);
}

void	clear_image(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_line * HEIGHT)
	{
		data->img_data[i] = 0;
		i++;
	}
	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		data->buf_depth[i] = INFINITY;
		i++;
	}
}

void	reset_points(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->offset_x = WIDTH / 2;
	data->offset_y = HEIGHT / 2;
	data->projection_mode = 1;
	data->zoom = 1.0;
	data->distance = 150;
	free(data->r);
	data->r = create_matrix(data);
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->len)
		{
			data->map->land[y][x]->x = data->map->land[y][x]->orig_x;
			data->map->land[y][x]->y = data->map->land[y][x]->orig_y;
			data->map->land[y][x]->z = data->map->land[y][x]->orig_z;
			x++;
		}
		y++;
	}
	re_draw(data);
}

void	re_draw(t_data *data)
{
	clear_image(data);
	set_new_points(data);
	put_pix_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
