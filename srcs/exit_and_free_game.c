/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_free_game.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:58:37 by gjupy             #+#    #+#             */
/*   Updated: 2022/06/14 14:21:59 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_strings(char ***s, int len)
{
	while (len >= 0)
	{
		free((*s)[len]);
		len--;
	}
	free(*s);
}

void	exit_game_failure(t_game *game)
{
	free_strings(&game->map, game->height);
	exit(EXIT_FAILURE);
}

void	exit_game_success(t_game *game)
{
	mlx_close_window(game->window.mlx);
	mlx_delete_image(game->window.mlx, game->window.image);
	mlx_terminate(game->window.mlx);
	free_strings(&game->map, game->height);
	exit(EXIT_SUCCESS);
}
