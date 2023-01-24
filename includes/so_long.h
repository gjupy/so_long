/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:57:07 by gjupy             #+#    #+#             */
/*   Updated: 2023/01/24 18:39:48 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "./MLX42/include/MLX42/MLX42.h"
# include "../srcs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

// # define malloc(...) NULL
# define WIDTH 64
# define HEIGHT 64

typedef struct s_texture
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collectible_1;
	mlx_texture_t	*collectible_2;
	mlx_texture_t	*collectible_3;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
}			t_texture;

typedef struct s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_window;

typedef struct s_my_key_data
{
	int	nbr_of_movements;
}	t_my_key_data;

typedef struct s_characters
{
	int		player;
	int		exit;
	int		collectible;
}	t_characters;

typedef struct s_game
{
	char			**map;
	int				width;
	int				height;
	char			*tmp_line;
	t_texture		texture;
	t_window		window;
	t_my_key_data	my_keydata;
	t_characters	chars;
}	t_game;

typedef struct s_index_vars
{
	int	x;
	int	y;
	int	j;
}	t_index_vars;

void	start(t_game *game, int argc, char **argv);
void	read_map(char *s, t_game *game);
void	check_parms_and_file(t_game *game, int argc, char **argv);
void	check_characters(t_game *game);
void	check_walls(t_game *game);
void	characters_parsing(t_game *game);
void	walls_left_right_parsing(t_game *game, int x, int y);

void	exit_game_success(t_game *game);
void	exit_game_failure(t_game *game);

bool	no_collects_left(t_game *game);
bool	is_exit(t_game *game, int x, int y);
void	move_player(t_game *game, int x, int y);
void	draw_wall(t_game *game, int x, int y);
void	print_keydata(t_game *game);
void	my_keyhook(mlx_key_data_t keydata, void *param);

#endif