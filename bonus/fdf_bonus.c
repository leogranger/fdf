/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:29:38 by lgranger          #+#    #+#             */
/*   Updated: 2025/12/22 09:56:28 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"
#include <stdio.h>
#include <stdlib.h>

int	check_file(char *arg)
{
	char	*sub;

	sub = ft_substr(arg, ft_strlen(arg) - 4, 4);
	if (ft_strncmp(sub, ".fdf", 4) == 0)
		return (free(sub), 1);
	free(sub);
	return (0);
}

void	check_arg(int argc, char **argv, t_data *data)
{
	if (argc != 2)
	{
		free(data->map);
		ft_printf("FdF needs 1 argument.\n");
		exit(EXIT_FAILURE);
	}
	if (!check_file(argv[1]))
	{
		free(data->map);
		ft_printf("Only .fdf files can be used.\n");
		exit(EXIT_FAILURE);
	}
	data->map->fd = open(argv[1], O_RDONLY);
	if (data->map->fd < 0)
	{
		free(data->map);
		ft_printf("Couldn't open the file.\n");
		exit(EXIT_FAILURE);
	}
}

void	set_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_error("mlx_init failed.", data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FdF");
	if (!data->win)
		ft_error("mlx_new_window failed.", data);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		ft_error("mlx_new_image failed.", data);
	data->img_data = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->size_line, &data->endian);
	if (!data->img_data)
		ft_error("mlx_det_data_addr failed.", data);
	data->buf_depth = malloc(WIDTH * HEIGHT * sizeof(float));
	if (!data->buf_depth)
		ft_error("Buf_depth malloc failed.", data);
}

void	set_data(t_data *data)
{
	data->r = create_matrix(data);
	data->offset_x = WIDTH / 2;
	data->offset_y = HEIGHT / 2;
	data->projection_mode = 1;
	data->zoom = 1.0;
	data->distance = 150;
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	data.map = ft_calloc(1, sizeof(t_map));
	if (!data.map)
		ft_error("Memory allocation of the map has failed.", &data);
	check_arg(argc, argv, &data);
	set_data(&data);
	set_map(&data);
	scale_map(&data);
	set_window(&data);
	put_pix_img(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	print_controls();
	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win, 4, 1L << 2, mouse_hook, &data);
	mlx_hook(data.win, 17, 0, close_win, &data);
	mlx_loop(data.mlx);
}
