/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:39:30 by lgranger          #+#    #+#             */
/*   Updated: 2025/12/18 13:44:19 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"
#include <math.h>

void	apply_matrix(t_matrix *R, t_point *p)
{
	p->x = R->m[0][0] * p->orig_x + R->m[0][1] * p->orig_y + R->m[0][2]
		* p->orig_z;
	p->y = R->m[1][0] * p->orig_x + R->m[1][1] * p->orig_y + R->m[1][2]
		* p->orig_z;
	p->z = R->m[2][0] * p->orig_x + R->m[2][1] * p->orig_y + R->m[2][2]
		* p->orig_z;
}

void	prep_matrix(t_data *data, int keycode, float steps)
{
	t_matrix	*new_m;
	t_matrix	*rot_m;

	if (keycode == ARR_L || keycode == ARR_R)
		rot_m = rotate_z(data, steps);
	else
		rot_m = rotate_x(data, steps);
	new_m = matrix_multiply(data, data->r, rot_m);
	free(data->r);
	free(rot_m);
	data->r = new_m;
}

void	rotate_points(t_data *data, int keycode, float steps)
{
	int	x;
	int	y;

	if (keycode == ARR_L || keycode == ARR_R)
	{
		prep_matrix(data, keycode, steps);
	}
	if (keycode == ARR_U || keycode == ARR_D)
	{
		prep_matrix(data, keycode, steps);
	}
	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->len)
		{
			apply_matrix(data->r, data->map->land[y][x]);
			screen_coord(data, data->map->land[y][x]);
			x++;
		}
		y++;
	}
}

void	rotate_axis(t_data *data, int keycode)
{
	float	steps;

	steps = 0.0;
	if (keycode == ARR_L || keycode == ARR_U)
		steps += 0.05;
	if (keycode == ARR_R || keycode == ARR_D)
		steps -= 0.05;
	rotate_points(data, keycode, steps);
	clear_image(data);
	put_pix_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
