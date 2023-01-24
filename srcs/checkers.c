/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:00:55 by gjupy             #+#    #+#             */
/*   Updated: 2022/08/22 13:22:51 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_walls(t_game *game)
{
	t_index_vars	var;

	var.y = -1;
	while (game->map[++var.y])
	{
		if (game->map[var.y][0] != '1'
			|| game->map[var.y][ft_strlen(game->map[var.y]) - 1] != '1')
		{
			ft_putstr_fd("\033[31mERROR\nMap must be surrounded\
 by walls\033[0m\n", 2);
			exit_game_failure(game);
		}
		var.x = 0;
		walls_left_right_parsing(game, var.x, var.y);
	}
}

void	check_characters(t_game *game)
{
	game->chars.player = 0;
	game->chars.exit = 0;
	game->chars.collectible = 0;
	characters_parsing(game);
	if (game->chars.collectible < 1 || game->chars.exit != 1
		|| game->chars.player != 1)
	{
		ft_putstr_fd("\033[31mERROR\nMap must contain at least one collectable 'C'\
, one exit 'E' and one starting position 'P'\033[0m\n", 2);
		exit_game_failure(game);
	}
}

void	check_parms_and_file(t_game *game, int argc, char **argv)
{
	if ((argc != 2
			|| (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)))
	{
		ft_putstr_fd("\033[31mERROR\nHow to run so_long: ./so_long 'file'.ber\
\033[0m\n", 2);
		exit(EXIT_FAILURE);
	}
}
