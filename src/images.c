/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:59:55 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/26 15:10:38 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_images(t_game *game, t_sprite *sprites)
{
	int	h;
	int	w;

	sprites->floor = mlx_xpm_file_to_image(game->mlx,
			"./sprites/xpm/floor.xpm", &h, &w);
	sprites->wall = mlx_xpm_file_to_image(game->mlx,
			"./sprites/xpm/wall.xpm", &h, &w);
	sprites->player = mlx_xpm_file_to_image(game->mlx,
			"./sprites/xpm/player.xpm", &h, &w);
	sprites->coin = mlx_xpm_file_to_image(game->mlx,
			"./sprites/xpm/colectable.xpm", &h, &w);
	sprites->exit = mlx_xpm_file_to_image(game->mlx,
			"./sprites/xpm/exit_portal.xpm", &h, &w);
}

void	put_images(t_game *game, t_map *map, int x, int y)
{
	if (map->carte[y][x] == '1')
		mlx_put_image_to_window(game->mlx,
			game->window, game->sprites.wall, x * 64, y * 64);
	else if (map->carte[y][x] == '0')
		mlx_put_image_to_window(game->mlx,
			game->window, game->sprites.floor, x * 64, y * 64);
	else if (map->carte[y][x] == 'P')
		mlx_put_image_to_window(game->mlx,
			game->window, game->sprites.player, x * 64, y * 64);
	else if (map->carte[y][x] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->window, game->sprites.coin, x * 64, y * 64);
	else if (map->carte[y][x] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->window, game->sprites.exit, x * 64, y * 64);
}

void	print_images(t_game *game, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->carte[y])
	{
		x = 0;
		while (x < map->width)
		{
			put_images(game, map, x, y);
			x++;
		}
		y++;
	}
}
