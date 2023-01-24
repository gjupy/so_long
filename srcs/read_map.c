/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:12:31 by gjupy             #+#    #+#             */
/*   Updated: 2022/06/14 12:12:07 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_and_exit_if_malloc_fails(char ***ss, int j)
{
	if (((*ss)[j]) == NULL)
	{
		while (j >= 0)
		{
			free((*ss)[j]);
			j--;
		}
		free(*ss);
		exit(EXIT_FAILURE);
	}
}

static void	get_dimensions(t_game *game, char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	game->height = 0;
	game->width = 0;
	game->tmp_line = get_next_line_with_exiting(fd);
	while (1)
	{
		game->height++;
		game->width = ft_strlen(game->tmp_line);
		free(game->tmp_line);
		game->tmp_line = get_next_line_with_exiting(fd);
		if (game->tmp_line == NULL)
			break ;
		if (game->tmp_line && ft_strlen(game->tmp_line) != game->width)
		{
			ft_putstr_fd("\033[31mERROR\nMap must be rectangular\033[0m\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	if (game->tmp_line)
		free(game->tmp_line);
	close(fd);
}

static void	create_map(t_game *game, char *s)
{
	int	fd;
	int	i;

	i = -1;
	fd = open(s, O_RDONLY);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		exit (EXIT_FAILURE);
	while (++i < game->height)
	{
		game->map[i] = get_next_line_without_exiting(fd);
		free_and_exit_if_malloc_fails(&game->map, i);
	}
	game->map[i] = NULL;
	close(fd);
}

void	read_map(char *s, t_game *game)
{
	get_dimensions(game, s);
	create_map(game, s);
	check_walls(game);
	check_characters(game);
}
