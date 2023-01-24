/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:01:17 by gjupy             #+#    #+#             */
/*   Updated: 2023/01/24 18:39:39 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player_right(t_game *game)
{
	t_index_vars	var;

	var.y = -1;
	while (game->map[++var.y])
	{
		var.x = 0;
		while (game->map && game->map[var.y][var.x])
		{
			if (game->map[var.y][var.x] == 'P')
			{
				if (game->map[var.y][var.x + 1] != '1'
					&& (is_exit(game, (var.x + 1), var.y) == false))
				{
					draw_wall(game, var.x, var.y);
					move_player(game, (var.x + 1), var.y);
					print_keydata(game);
				}
				return ;
			}
			var.x++;
		}
	}
}

void	move_player_left(t_game *game)
{
	t_index_vars	var;

	var.y = -1;
	while (game->map[++var.y])
	{
		var.x = 0;
		while (game->map && game->map[var.y][var.x])
		{
			if (game->map[var.y][var.x] == 'P')
			{
				if (game->map[var.y][var.x - 1] != '1'
					&& (is_exit(game, (var.x - 1), var.y) == false))
				{
					draw_wall(game, var.x, var.y);
					move_player(game, (var.x - 1), var.y);
					print_keydata(game);
				}
				return ;
			}
			var.x++;
		}
	}
}

void	move_player_down(t_game *game)
{
	t_index_vars	var;

	var.y = -1;
	while (game->map[++var.y])
	{
		var.x = 0;
		while (game->map && game->map[var.y][var.x])
		{
			if (game->map[var.y][var.x] == 'P')
			{
				if (game->map[var.y + 1][var.x] != '1'
					&& (is_exit(game, var.x, (var.y + 1)) == false))
				{
					draw_wall(game, var.x, var.y);
					move_player(game, var.x, (var.y + 1));
					print_keydata(game);
				}
				return ;
			}
			var.x++;
		}
	}
}

void	move_player_up(t_game *game)
{
	t_index_vars	var;

	var.y = -1;
	while (game->map[++var.y])
	{
		var.x = 0;
		while (game->map && game->map[var.y][var.x])
		{
			if (game->map[var.y][var.x] == 'P')
			{
				if (game->map[var.y - 1][var.x] != '1'
					&& (is_exit(game, var.x, (var.y - 1)) == false))
				{
					draw_wall(game, var.x, var.y);
					move_player(game, var.x, (var.y - 1));
					print_keydata(game);
				}
				return ;
			}
			var.x++;
		}
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player_up(param);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player_down(param);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player_left(param);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player_right(param);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit_game_success(param);
}
