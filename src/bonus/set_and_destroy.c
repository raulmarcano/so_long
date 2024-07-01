/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:34:31 by rmarcano          #+#    #+#             */
/*   Updated: 2024/07/01 16:59:50 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	destroy_all(t_game *game)
{
	clean_images(game, &game->sprites);
	if (game->window)
	{
		mlx_destroy_window(game->mlx, game->window);
		game->window = NULL;
	}
	if (game->mlx)
	{
		mlx_loop_end(game->mlx);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free(game);
}

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
	mlx_set_font(game->mlx, game->window, "12x24romankana");
	mlx_key_hook(game->window, ft_key_press, game);
	mlx_hook(game->window, DestroyNotify, 0, click_x, game);
	mlx_loop_hook(game->mlx, animation, game);
	mlx_loop(game->mlx);
}
