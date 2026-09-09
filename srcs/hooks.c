/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:03:47 by lgranger          #+#    #+#             */
/*   Updated: 2026/09/09 09:42:13 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == K_ESC)
		close_win(data);
	else if (keycode == ARR_L || keycode == ARR_R || keycode == ARR_U
		|| keycode == ARR_D)
		rotate_axis(data, keycode);
	else if (keycode == K_W || keycode == K_S || keycode == K_A
		|| keycode == K_D)
		translate_map(data, keycode);
	else if (keycode == ONE)
	{
		data->projection_mode = 1;
		re_draw(data);
	}
	else if (keycode == TWO)
	{
		data->projection_mode = 2;
		re_draw(data);
	}
	else if (keycode == K_R)
		reset_points(data);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	int	w_x;
	int	w_y;
	int	new_x;
	int	new_y;

	if (keycode == SCROLL_D || keycode == SCROLL_U)
	{
		data->mouse_x = x;
		data->mouse_y = y;
		w_x = (data->mouse_x - data->offset_x) / data->zoom;
		w_y = (data->mouse_y - data->offset_y) / data->zoom;
		if (keycode == SCROLL_U)
			data->zoom *= 1.1;
		else if (keycode == SCROLL_D)
			data->zoom *= 0.9;
		new_x = w_x * data->zoom + data->offset_x;
		new_y = w_y * data->zoom + data->offset_y;
		data->offset_x -= (new_x - data->mouse_x);
		data->offset_y -= (new_y - data->mouse_y);
	}
	re_draw(data);
	return (0);
}
