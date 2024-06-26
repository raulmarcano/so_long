/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:11:51 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/26 14:51:34 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_game(t_map *map, t_game *game, char **argv)
{
	int	window_w;
	int	window_h;

	game->count_moves = 0;
	game->mlx = mlx_init();
	save_map(map, argv[1]);
	game->map = map;
	max_screensize(game, map);
	window_w = map->width * 64;
	window_h = map->height * 64;
	game->window = mlx_new_window(game->mlx, window_w, window_h, "so_long");
	map->carte[map->exit.y][map->exit.x] = '0';
	set_images(game, &game->sprites);
	mlx_key_hook(game->window, ft_key_press, game);
	mlx_hook(game->window, DestroyNotify, 0, click_x, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (argc != 2)
		exit(1);
	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_printf("Error\n failure on map memory allocation");
		exit(EXIT_FAILURE);
	}
	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_printf("Error\n failure on game struct memory allocation");
		exit(EXIT_FAILURE);
	}
	set_game(map, game, argv);
	free(game->mlx);
	free(game->window);
	free(game);
	clean_n_exit(map);
	return (0);
}
