/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:23:25 by lgranger          #+#    #+#             */
/*   Updated: 2025/12/18 14:47:41 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	free_3d_array(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (!data->map->land)
		return ;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->len)
		{
			free(data->map->land[y][x]);
			x++;
		}
		free(data->map->land[y]);
		y++;
	}
	free(data->map->land);
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_error(char *s, t_data *data)
{
	ft_printf("%s\n", s);
	if (data && data->map->fd > 0)
		close(data->map->fd);
	if (data && data->mlx)
		free(data->mlx);
	if (data && data->map->land)
		free_3d_array(data);
	if (data && data->map)
		free(data->map);
	if (data && data->buf_depth)
		free(data->buf_depth);
	if (data && data->r)
		free(data->r);
	exit(0);
}
