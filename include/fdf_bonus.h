/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:40:35 by lgranger          #+#    #+#             */
/*   Updated: 2025/12/22 11:22:10 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "struct_bonus.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

// errors
void		free_tab(char **tab);
void		free_3d_array(t_data *data);
void		ft_error(char *s, t_data *data);

// checks
void		check_arg(int argc, char **argv, t_data *data);
void		check_map(t_data *data);
void		check_content(t_data *data, char *almost_map, char *whole_map);
bool		check_rgb_hex(char *line, int len);
bool		check_no_rgb(char *line, int len);
bool		check_line(char *line);
bool		check_length(t_data *data);
int			check_file(char *arg);

// utils
int			find_linelength(char *s);
int			find_map_height(t_data *data);
int			find_str(char *s1, char *s2);
void		find_min_max_z(t_data *data);
void		allocate_mem(t_data *data);
void		allocate_rows(t_data *data, int height, int len);
void		allocate_columns(t_data *data, int height, int len);
bool		is_hexdigits(int c);
t_matrix	*create_matrix(t_data *data);

// landscape
void		set_data(t_data *data);
void		set_map(t_data *data);
void		set_window(t_data *data);

// points
void		create_points(t_data *data);
void		set_points(t_data *data, char **tmp, int y);
void		screen_coord(t_data *data, t_point *point);
void		isometric_mode(t_data *data, t_point *point);
void		perspective_mode(t_data *data, t_point *point);
void		new_point(t_data *data, char *s, int x, int y);
void		scale_map(t_data *data);
void		set_new_points(t_data *data);

// lines
float		fabs_value(float n);
void		put_line(t_data *data, int steps, t_point *p1);
void		dda_line(t_data *data, t_point *p1, t_point *p2);

// draw
int			put_pix_img(t_data *data);
void		put_pixel(t_data *data, int x, int y, int color);
void		re_draw(t_data *data);
void		clear_image(t_data *data);
void		draw_horizontal(t_data *data, int h, int l);
void		draw_vertical(t_data *data, int h, int l);

// colors
void		color_right_shift(t_point *point1, t_point *p2);
void		set_color_inc(t_data *data, t_point *p1, t_point *p2, int steps);
int			color_left_shift(t_point *point);
float		find_color_inc(float comp1, float comp2, int steps);

// rotate
void		rotate_axis(t_data *data, int keycode);
void		rotate_points(t_data *data, int keycode, float steps);
t_matrix	*rotate_x(t_data *data, float steps);
t_matrix	*rotate_y(t_data *data, float steps);
t_matrix	*rotate_z(t_data *data, float steps);

// translate
void		translate_map(t_data *data, int keycode);

// matrix
t_matrix	*matrix_multiply(t_data *data, t_matrix *M, t_matrix *N);
void		apply_matrix(t_matrix *R, t_point *p);

// hooks
int			key_hook(int keycode, t_data *data);
int			mouse_hook(int keycode, int x, int y, t_data *data);

// events
int			close_win(t_data *data);
void		reset_points(t_data *data);
void		print_controls(void);

#endif