/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgranger <lgranger@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:54:04 by lgranger          #+#    #+#             */
/*   Updated: 2025/11/19 11:24:57 by lgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*sub_line(char *s)
{
	char	*new_line;
	int		n;

	n = 0;
	while (s[n] && s[n] != '\n')
		n++;
	if (s[n] == '\n')
		n++;
	new_line = ft_substr(s, 0, n);
	if (!new_line)
		return (NULL);
	if (!new_line[0])
	{
		free(new_line);
		return (NULL);
	}
	return (new_line);
}

char	*update_static(char *s)
{
	char	*upto_date;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	upto_date = ft_substr(s, i, ft_strlen(s) - i);
	free(s);
	if (!upto_date || !*upto_date)
	{
		free(upto_date);
		return (NULL);
	}
	return (upto_date);
}

char	*find_new_line(char *next_line, char *buf, int fd)
{
	char	*temp;
	int		nbrread;

	nbrread = 1;
	while (nbrread > 0)
	{
		nbrread = read(fd, buf, BUFFER_SIZE);
		if (nbrread == -1)
		{
			free(next_line);
			return (NULL);
		}
		buf[nbrread] = '\0';
		if (!next_line)
			next_line = ft_strdup("");
		temp = next_line;
		next_line = ft_strjoin(temp, buf);
		if (!next_line)
			return (NULL);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*next_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free(next_line);
		next_line = NULL;
		return (NULL);
	}
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	next_line = find_new_line(next_line, buf, fd);
	free(buf);
	if (!next_line)
	{
		free(next_line);
		return (NULL);
	}
	line = sub_line(next_line);
	next_line = update_static(next_line);
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	char *s;

// 	fd = open("test.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	close(fd);
// 	return (0);
// }