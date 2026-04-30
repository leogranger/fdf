/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 09:19:43 by lgranger          #+#    #+#             */
/*   Updated: 2025/12/18 13:31:55 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

bool	check_rgb_hex(char *line, int len)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] && line[i] == 32)
			i++;
		if (!line[i])
			break ;
		if ((line[i] == '-' || line[i] == '+') && ft_isdigit(line[i + 1])
			&& line[i])
			i++;
		if (line[i] == ',' && line[i + 1] == '0' && line[i + 2] == 'x')
			i += 3;
		while (is_hexdigits(line[i]) && line[i])
			i++;
		if (!is_hexdigits(line[i]) && line[i] != '-' && line[i] != '+'
			&& line[i] != 32 && line[i] != ',' && line[i] != '0'
			&& line[i] != 'x')
			break ;
	}
	if (i != len)
		return (false);
	return (true);
}

bool	check_no_rgb(char *line, int len)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] && line[i] == 32)
			i++;
		if (!line[i])
			break ;
		if ((line[i] == '-' || line[i] == '+') && ft_isdigit(line[i + 1])
			&& line[i])
			i++;
		while (ft_isdigit(line[i]) && line[i])
			i++;
		if (!ft_isdigit(line[i]) && line[i] != '-' && line[i] != '+'
			&& line[i] != 32)
			break ;
	}
	if (len != i)
		return (false);
	return (true);
}

bool	check_line(char *lines)
{
	char	*tmp;
	char	*hex;
	int		len;

	tmp = lines;
	len = ft_strlen(tmp);
	hex = ft_strchr(tmp, ',');
	if (!hex)
	{
		if (!check_no_rgb(tmp, len))
			return (false);
	}
	else
	{
		if (!check_rgb_hex(tmp, len) || check_rgb_hex(tmp, len))
			return (false);
	}
	return (true);
}

void	check_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->landscape[i])
	{
		if (!check_line(data->map->landscape[i]))
		{
			free_tab(data->map->landscape);
			ft_error("The file contains unauthorized characters.", data);
		}
		i++;
	}
	if (!check_length(data))
	{
		free_tab(data->map->landscape);
		ft_error("The map should be rectangular.", data);
	}
}
