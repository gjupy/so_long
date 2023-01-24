/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:00:46 by gjupy             #+#    #+#             */
/*   Updated: 2022/06/14 17:36:29 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	load_textures(t_game *game)
{
	game->texture.floor = mlx_load_png("./assets/textures/floor.png");
	game->texture.wall = mlx_load_png("./assets/textures/wall.png");
	game->texture.collectible_1 = mlx_load_png
		("./assets/textures/collectible_vinyl.png");
	game->texture.collectible_2 = mlx_load_png
		("./assets/textures/collectible_wine.png");
	game->texture.collectible_3 = mlx_load_png
		("./assets/textures/collectible_bananas.png");
	game->texture.player = mlx_load_png("./assets/textures/player.png");
	game->texture.exit = mlx_load_png("./assets/textures/exit.png");
}

static void	draw_collects_and_player(int x, int y, int *j, t_game *game)
{
	if (game->map[y][x] == 'P')
		mlx_draw_texture(game->window.image, game->texture.player,
			x * WIDTH, y * HEIGHT);
	else if (game->map[y][x] == 'C')
	{
		if (*j == 0)
			mlx_draw_texture(game->window.image, game->texture.collectible_1,
				x * WIDTH, y * HEIGHT);
		else if (*j == 1)
			mlx_draw_texture(game->window.image, game->texture.collectible_2,
				x * WIDTH, y * HEIGHT);
		else if (*j == 2)
			mlx_draw_texture(game->window.image, game->texture.collectible_3,
				x * WIDTH, y * HEIGHT);
		*j += 1;
		if (*j == 3)
			*j = 0;
	}
}

static void	draw_map(t_game *game)
{
	t_index_vars	var;

	var.j = 0;
	var.y = -1;
	while (game->map[++var.y])
	{
		var.x = 0;
		while (game->map && game->map[var.y][var.x])
		{
			if (game->map[var.y][var.x] == '1')
				mlx_draw_texture(game->window.image, game->texture.wall,
					var.x * WIDTH, var.y * HEIGHT);
			else if (game->map[var.y][var.x] == '0')
				mlx_draw_texture(game->window.image, game->texture.floor,
					var.x * WIDTH, var.y * WIDTH);
			else if (game->map[var.y][var.x] == 'E')
				mlx_draw_texture(game->window.image, game->texture.exit,
					var.x * WIDTH, var.y * WIDTH);
			else
				draw_collects_and_player(var.x, var.y, &var.j, game);
			var.x++;
		}
	}
}

static void	game_init(t_game *game)
{
	game->my_keydata.nbr_of_movements = 0;
	game->window.mlx = mlx_init(game->width * WIDTH, game->height * HEIGHT,
			"so_long", false);
	if (!game->window.mlx)
		exit_game_failure(game);
	game->window.image = mlx_new_image(game->window.mlx, game->width * WIDTH,
			game->height * HEIGHT);
	if (!game->window.image)
		exit_game_failure(game);
	load_textures(game);
	mlx_image_to_window(game->window.mlx,
		game->window.image, 0, 0);
	draw_map(game);
	mlx_key_hook(game->window.mlx, &my_keyhook, game);
}

void	start(t_game *game, int argc, char **argv)
{
	check_parms_and_file(game, argc, argv);
	read_map(argv[1], game);
	game_init(game);
	mlx_loop(game->window.mlx);
}
