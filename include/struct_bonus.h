/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:36:29 by lgranger          #+#    #+#             */
/*   Updated: 2025/12/18 14:48:30 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

# define ARR_L 65361
# define ARR_R 65363
# define ARR_U 65362
# define ARR_D 65364
# define K_A 97
# define K_W 119
# define K_S 115
# define K_D 100
# define K_ESC 65307
# define CLICK_L 1
# define CLICK_R 3
# define SCROLL_U 4
# define SCROLL_D 5
# define HEIGHT 1080
# define WIDTH 1920
# define ONE 49
# define TWO 50
# define K_R 114

typedef struct s_matrix
{
	float		m[3][3];
}				t_matrix;

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	float		orig_x;
	float		orig_y;
	float		orig_z;
	float		r;
	float		g;
	float		b;
	float		screen_x;
	float		screen_y;
	float		depth;
	int			color;
	int			visible;
}				t_point;

typedef struct s_map
{
	int			fd;
	int			len;
	int			height;
	int			center_x;
	int			center_y;
	int			min_z;
	int			max_z;
	float		z_scale;
	char		**landscape;
	t_point		***land;
}				t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			projection_mode;
	int			distance;
	float		x_inc;
	float		y_inc;
	float		r_inc;
	float		g_inc;
	float		b_inc;
	float		depth_inc;
	float		depth;
	float		zoom;
	float		offset_x;
	float		offset_y;
	float		mouse_x;
	float		mouse_y;
	float		*buf_depth;
	t_matrix	*r;
	t_map		*map;
}				t_data;

#endif