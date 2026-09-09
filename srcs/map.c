/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:25:22 by lgranger          #+#    #+#             */
/*   Updated: 2026/09/09 09:42:20 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

void	allocate_rows(t_data *data, int height, int len)
{
	int	y;

	y = 0;
	while (y < height)
	{
		data->map->land[y] = ft_calloc(len + 1, sizeof(t_point *));
		if (!data->map->land[y])
			ft_error("Couldn't allocate memory to the rows of land.", data);
		data->map->land[y][len] = NULL;
		y++;
	}
}

void	allocate_columns(t_data *data, int height, int len)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < len)
		{
			data->map->land[y][x] = ft_calloc(1, sizeof(t_point));
			if (!data->map->land[y][x])
				ft_error("Couldn't allocate memory to the columns of land.",
					data);
			x++;
		}
		y++;
	}
}

void	check_content(t_data *data, char *almost_map, char *whole_map)
{
	if (!whole_map)
	{
		free(almost_map);
		ft_error("The file is empty.", data);
	}
	if (find_str(whole_map, "\n\n"))
	{
		free(whole_map);
		ft_error("There is an empty line in the file.", data);
	}
	data->map->landscape = ft_split(whole_map, '\n');
	free(whole_map);
	check_map(data);
}

void	set_map(t_data *data)
{
	char	*line;
	char	*almost_map;
	char	*whole_map;

	ft_printf("Loading map...\n");
	whole_map = NULL;
	almost_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(data->map->fd);
		if (!line)
		{
			free(line);
			break ;
		}
		whole_map = ft_strjoin(almost_map, line);
		free(almost_map);
		free(line);
		almost_map = whole_map;
	}
	check_content(data, almost_map, whole_map);
	allocate_mem(data);
	create_points(data);
}
