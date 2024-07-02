/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:59:55 by rmarcano          #+#    #+#             */
/*   Updated: 2024/07/02 12:58:55 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	load_images_error(t_game *game, t_sprite *sprites)
{
	if (!sprites->floor || !sprites->wall
		|| !sprites->player || !sprites->coin
		|| !sprites->exit || !sprites->badguy
		|| !sprites->badguy2 || !sprites->portal2)
	{
		ft_printf("Error\n Failed while loading images\n");
		ft_free_array(&game->map->carte);
		free(game->map);
		destroy_all(game);
		exit(EXIT_FAILURE);
	}
}

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
	sprites->badguy = mlx_xpm_file_to_image(game->mlx,
			"./sprites/xpm/badguy.xpm", &h, &w);
	sprites->badguy2 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/xpm/badguy2.xpm", &h, &w);
	sprites->background = mlx_xpm_file_to_image(game->mlx,
			"./sprites/xpm/background1.xpm", &h, &w);
	sprites->portal2 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/xpm/portal2.xpm", &h, &w);
	load_images_error(game, sprites);
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
	counter_on_screen(game, game->count_moves);
}

void	clean_images(t_game *game, t_sprite *sprites)
{
	if (sprites->floor)
		mlx_destroy_image(game->mlx, sprites->floor);
	if (sprites->wall)
		mlx_destroy_image(game->mlx, sprites->wall);
	if (sprites->player)
		mlx_destroy_image(game->mlx, sprites->player);
	if (sprites->coin)
		mlx_destroy_image(game->mlx, sprites->coin);
	if (sprites->exit)
		mlx_destroy_image(game->mlx, sprites->exit);
	if (sprites->badguy)
		mlx_destroy_image(game->mlx, sprites->badguy);
	if (sprites->badguy2)
		mlx_destroy_image(game->mlx, sprites->badguy2);
	if (sprites->background)
		mlx_destroy_image(game->mlx, sprites->background);
	if (sprites->portal2)
		mlx_destroy_image(game->mlx, sprites->portal2);
}
