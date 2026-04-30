/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 09:20:07 by lgranger          #+#    #+#             */
/*   Updated: 2025/12/18 13:30:33 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <math.h>

int	key_hook(int keycode, t_data *data)
{
	if (keycode == K_ESC)
		close_win(data);
	return (0);
}

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
