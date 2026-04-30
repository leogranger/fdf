/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:50:26 by lgranger          #+#    #+#             */
/*   Updated: 2025/12/18 14:50:29 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "struct.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

// errors
void	free_tab(char **tab);
void	free_3d_array(t_data *data);
void	ft_error(char *s, t_data *data);

// checks
void	check_arg(int argc, char **argv, t_data *data);
void	check_map(t_data *data);
void	check_content(t_data *data, char *almost_map, char *whole_map);
bool	check_rgb_hex(char *line, int len);
bool	check_no_rgb(char *line, int len);
bool	check_line(char *line);
bool	check_length(t_data *data);
int		check_file(char *arg);

// utils
int		find_linelength(char *s);
int		find_map_height(t_data *data);
int		find_str(char *s1, char *s2);
void	find_min_max_z(t_data *data);
void	allocate_mem(t_data *data);
void	allocate_rows(t_data *data, int height, int len);
void	allocate_columns(t_data *data, int height, int len);
void	scale_map(t_data *data);
bool	is_hexdigits(int c);

// landscape
void	set_data(t_data *data);
void	set_map(t_data *data);
void	set_window(t_data *data);

// points
void	create_points(t_data *data);
void	set_points(t_data *data, char **tmp, int y);
void	screen_coord(t_data *data, t_point *point);
void	new_point(t_data *data, char *s, int x, int y);
// lines
float	fabs_value(float n);
void	put_line(t_data *data, int steps, t_point *p1);
void	dda_line(t_data *data, t_point *p1, t_point *p2);

// draw
int		put_pix_img(t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
void	clear_image(t_data *data);
void	draw_horizontal(t_data *data, int h, int l);
void	draw_vertical(t_data *data, int h, int l);

// hooks
int		key_hook(int keycode, t_data *data);

// events
int		close_win(t_data *data);

#endif