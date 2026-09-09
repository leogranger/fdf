/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:24:42 by lgranger          #+#    #+#             */
/*   Updated: 2026/09/09 10:03:22 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel;
	int		offset;
	int		i;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	i = y * WIDTH + x;
	if (data->depth >= data->buf_depth[i])
		return ;
	data->buf_depth[i] = data->depth;
	offset = (y * data->size_line) + (x * (data->bits_per_pixel / 8));
	pixel = data->img_data + offset;
	*(unsigned int *)pixel = color;
}

void	put_line(t_data *data, int steps, t_point *p1)
{
	t_point	tmpp;
	int		i;
	float	new_x;
	float	new_y;

	i = 0;
	tmpp = *p1;
	new_x = p1->screen_x;
	new_y = p1->screen_y;
	while (i <= steps)
	{
		if (data->r_inc == 0 && data->g_inc == 0 && data->b_inc == 0)
			put_pixel(data, new_x, new_y, p1->color);
		else
		{
			put_pixel(data, new_x, new_y, color_left_shift(&tmpp));
			tmpp.r += data->r_inc;
			tmpp.g += data->g_inc;
			tmpp.b += data->b_inc;
		}
		new_x += data->x_inc;
		new_y += data->y_inc;
		data->depth += data->depth_inc;
		i++;
	}
}

float	fabs_value(float n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	dda_line(t_data *data, t_point *p1, t_point *p2)
{
	float	dx;
	float	dy;
	float	steps;
	if ((p1->screen_x < 0 && p2->screen_x < 0)
		|| (p1->screen_x >= WIDTH && p2->screen_x >= WIDTH)
		|| (p1->screen_y < 0 && p2->screen_y < 0)
		|| (p1->screen_y >= HEIGHT && p2->screen_y >= HEIGHT))
		return ;
	data->depth = p1->depth;
	color_right_shift(p1, p2);
	dx = p2->screen_x - p1->screen_x;
	dy = p2->screen_y - p1->screen_y;
	if (fabs_value(dx) > fabs_value(dy))
		steps = fabs_value(dx);
	else
		steps = fabs_value(dy);
	if (steps == 0)
		steps = 1;
	data->depth_inc = (p2->depth - p1->depth) / steps;
	set_color_inc(data, p1, p2, steps);
	data->x_inc = dx / steps;
	data->y_inc = dy / steps;
	put_line(data, steps, p1);
}

int	put_pix_img(t_data *data)
{
	static int	h;
	int			l;

	h = data->map->height - 1;
	l = data->map->len - 1;
	clear_image(data);
	draw_horizontal(data, h, l);
	draw_vertical(data, h, l);
	return (0);
}
