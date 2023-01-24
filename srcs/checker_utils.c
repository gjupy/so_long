/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:20:39 by gjupy             #+#    #+#             */
/*   Updated: 2022/06/13 22:12:20 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'E' || c == 'P' || c == 'C')
		return (true);
	return (false);
}

void	characters_parsing(t_game *game)
{
	t_index_vars	var;

	var.y = -1;
	while (game->map[++var.y])
	{
		var.x = 0;
		while (game->map[var.y][var.x])
		{
			if (is_valid_char(game->map[var.y][var.x]) == true)
			{
				if (game->map[var.y][var.x] == 'C')
					game->chars.collectible++;
				if (game->map[var.y][var.x] == 'E')
					game->chars.exit++;
				if (game->map[var.y][var.x] == 'P')
					game->chars.player++;
			}
			else
			{
				ft_putstr_fd("\033[31mERROR\nInvalid character\033[0m\n", 2);
				exit_game_failure(game);
			}
			var.x++;
		}
	}
}

void	walls_left_right_parsing(t_game *game, int x, int y)
{
	while (game->map[y][x])
	{
		if ((y == 0 && game->map[y][x] != '1')
			|| (y == game->height - 1 && game->map[y][x] != '1'))
		{
			ft_putstr_fd("\033[31mERROR\nMap must be surrounded\
 by walls\033[0m\n", 2);
			exit_game_failure(game);
		}
		x++;
	}
}
