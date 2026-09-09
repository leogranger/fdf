/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:06:27 by lgranger          #+#    #+#             */
/*   Updated: 2026/09/09 09:42:24 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <limits.h>
#include <math.h>

t_matrix	*matrix_multiply(t_data *data, t_matrix *m, t_matrix *n)
{
	t_matrix	*o;
	int			i;
	int			j;
	int			k;

	i = 0;
	o = ft_calloc(1, sizeof(t_matrix));
	if (!o)
		ft_error("Memory allocation of the matrix failed.", data);
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			k = 0;
			while (k < 3)
			{
				o->m[i][j] += m->m[i][k] * n->m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (o);
}

t_matrix	*create_matrix(t_data *data)
{
	t_matrix	*m;

	m = ft_calloc(1, sizeof(t_matrix));
	if (!m)
		ft_error("Memory allocation of the matrix failed.", data);
	m->m[0][0] = 1.0;
	m->m[1][1] = 1.0;
	m->m[2][2] = 1.0;
	return (m);
}

t_matrix	*rotate_x(t_data *data, float steps)
{
	t_matrix	*m;
	float		c;
	float		s;

	m = create_matrix(data);
	c = cosf(steps);
	s = sinf(steps);
	m->m[1][1] = c;
	m->m[2][1] = s;
	m->m[1][2] = -s;
	m->m[2][2] = c;
	return (m);
}

t_matrix	*rotate_z(t_data *data, float steps)
{
	t_matrix	*m;
	float		c;
	float		s;

	m = create_matrix(data);
	c = cosf(steps);
	s = sinf(steps);
	m->m[0][0] = c;
	m->m[1][0] = s;
	m->m[0][1] = -s;
	m->m[1][1] = c;
	return (m);
}

t_matrix	*rotate_y(t_data *data, float steps)
{
	t_matrix	*m;
	float		c;
	float		s;

	m = create_matrix(data);
	c = cosf(steps);
	s = sinf(steps);
	m->m[0][0] = c;
	m->m[2][0] = -s;
	m->m[0][2] = s;
	m->m[2][2] = c;
	return (m);
}
