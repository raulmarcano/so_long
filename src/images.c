/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:59:55 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/25 17:01:43 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    set_images(t_game *game, t_sprite *sprites)
{
	int h;
	int w;

    sprites->floor = mlx_xpm_file_to_image(game->mlx, "./sprites/xpm/floor.xpm", &h, &w);
	sprites->wall = mlx_xpm_file_to_image(game->mlx, "./sprites/xpm/wall.xpm", &h, &w);
	sprites->player = mlx_xpm_file_to_image(game->mlx, "./sprites/xpm/player.xpm", &h, &w);
	sprites->coin = mlx_xpm_file_to_image(game->mlx, "./sprites/xpm/colectable.xpm", &h, &w);
	sprites->enemy = mlx_xpm_file_to_image(game->mlx, "./sprites/xpm/enemy.xpm", &h, &w);
	sprites->exit = mlx_xpm_file_to_image(game->mlx, "./sprites/xpm/exit_portal.xpm", &h, &w);
}
void	print_images(t_game *game, t_map *map, t_sprite *sprites)
{
	int i;
	int j;
    
    i = 0;
	while(map->carte[i])
	{
        j = 0;
		while (j < map->width)
		{
			if(map->carte[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window, sprites->wall, j * 64, i * 64);
			else if(map->carte[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->window, sprites->floor, j * 64, i * 64);
			else if(map->carte[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, sprites->player, j * 64, i * 64);
			else if(map->carte[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, sprites->coin, j * 64, i * 64);
			else if(map->carte[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, sprites->exit, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
