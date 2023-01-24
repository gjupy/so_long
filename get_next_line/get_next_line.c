/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 00:40:52 by cboubour          #+#    #+#             */
/*   Updated: 2022/08/22 13:26:33 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_with_exiting(int fd)
{
	char		*buff;
	static char	*line;
	int			sz;

	if (fd < 0 || read(fd, &line, 0) < 0)
		exit(EXIT_FAILURE);
	buff = ft_calloc(2, 1);
	if (!buff)
		exit(EXIT_FAILURE);
	sz = read(fd, buff, 1);
	if (!sz)
	{
		free(buff);
		return (NULL);
	}
	line = ft_strdup(buff);
	while (sz > 0 && buff[0] != '\n')
	{
		sz = read(fd, buff, 1);
		buff[1] = 0;
		if (sz && buff[0] != '\n')
			line = ft_strjoin2(&line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line_without_exiting(int fd)
{
	char		*buff;
	static char	*line;
	int			sz;

	if (fd < 0 || read(fd, &line, 0) < 0)
		exit(EXIT_FAILURE);
	buff = ft_calloc(2, 1);
	if (!buff)
		return (NULL);
	sz = read(fd, buff, 1);
	if (!sz)
	{
		free(buff);
		return (NULL);
	}
	line = ft_strdup(buff);
	while (sz > 0 && buff[0] != '\n')
	{
		sz = read(fd, buff, 1);
		buff[1] = 0;
		if (sz && buff[0] != '\n')
			line = ft_strjoin2(&line, buff);
	}
	free(buff);
	return (line);
}