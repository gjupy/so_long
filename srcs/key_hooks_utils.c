/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:43:30 by gjupy             #+#    #+#             */
/*   Updated: 2022/06/13 22:13:04 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	no_collects_left(t_game *game)
{
	t_index_vars	var;

	var.y = -1;
	while (game->map[++var.y])
	{
		var.x = 0;
		while (game->map && game->map[var.y][var.x])
		{
			if (game->map[var.y][var.x] == 'C')
				return (false);
			var.x++;
		}
	}
	return (true);
}

bool	is_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (no_collects_left(game))
		{
			print_keydata(game);
			exit_game_success(game);
		}
		return (true);
	}
	return (false);
}

void	print_keydata(t_game *game)
{
	game->my_keydata.nbr_of_movements++;
	ft_printf("CURRENT NUMBER OF MOVEMENTS: %d\n",
		game->my_keydata.nbr_of_movements);
}

void	draw_wall(t_game *game, int x, int y)
{
	game->map[y][x] = '0';
	mlx_draw_texture(game->window.image, game->texture.floor,
		x * WIDTH, y * WIDTH);
}

void	move_player(t_game *game, int x, int y)
{
	game->map[y][x] = 'P';
	mlx_draw_texture(game->window.image, game->texture.player,
		x * WIDTH, y * WIDTH);
}
