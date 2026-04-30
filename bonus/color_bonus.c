/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:06:53 by lgranger          #+#    #+#             */
/*   Updated: 2025/12/18 09:20:36 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	set_color_inc(t_data *data, t_point *p1, t_point *p2, int steps)
{
	if (p1->color != p2->color)
	{
		data->r_inc = find_color_inc(p1->r, p2->r, steps);
		data->g_inc = find_color_inc(p1->g, p2->g, steps);
		data->b_inc = find_color_inc(p1->b, p2->b, steps);
	}
	else
	{
		data->r_inc = 0;
		data->g_inc = 0;
		data->b_inc = 0;
	}
}

void	color_right_shift(t_point *point1, t_point *point2)
{
	point1->r = (point1->color >> 16) & 255;
	point1->g = (point1->color >> 8) & 255;
	point1->b = point1->color & 255;
	point2->r = (point2->color >> 16) & 255;
	point2->g = (point2->color >> 8) & 255;
	point2->b = point2->color & 255;
}

int	color_left_shift(t_point *point)
{
	int	final_color;

	final_color = ((int)point->r << 16) | ((int)point->g << 8) | (int)point->b;
	return (final_color);
}

float	find_color_inc(float comp1, float comp2, int steps)
{
	float	inc;

	inc = (comp2 - comp1) / steps;
	return (inc);
}
