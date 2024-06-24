/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:11:51 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/17 18:33:21 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int argc, char **argv)
{
	t_map *map;
    t_game *game;

    if (argc != 2)
    {
        exit(1);
    }
	map = malloc(sizeof(t_map));
    if(!map)
    {
        ft_printf("Error\n failure on map memory allocation");
        exit(EXIT_FAILURE);
    }
    game = malloc(sizeof(t_game));
    if(!game)
    {
        ft_printf("Error\n failure on game struct memory allocation");
        exit(EXIT_FAILURE);
    }
    save_map(map, argv[1]);
    game->mlx = mlx_init();
    game->window = mlx_new_window(game->mlx, map->width, map->height, "so_long");
	
	set_images(game);
	print_images(game, map);
    mlx_loop(game->mlx);
	//When the game is ended, it has to break the loop
    clean_n_exit(map);
    return (0);
}

void    set_images(t_game *game)
{
	int h;
	int w;

    game->sprites->floor = mlx_xpm_file_to_image(game->mlx, "./sprites/xpm/floor.xpm", &h, &w);
	game->sprites->wall = mlx_xpm_file_to_image(game->mlx, "./sprites/xpm/wall.xpm", &h, &w);
	game->sprites->player = mlx_xpm_file_to_image(game->mlx, "./sprites/xpm/player.xpm", &h, &w);
	game->sprites->coin = mlx_xpm_file_to_image(game->mlx, "./sprites/xpm/colectable.xpm", &h, &w);
	game->sprites->enemy = mlx_xpm_file_to_image(game->mlx, "./sprites/xpm/enemy.xpm", &h, &w);
	game->sprites->exit = mlx_xpm_file_to_image(game->mlx, "./sprites/xpm/exit_open.xpm", &h, &w);
}
void	print_images(t_game *game, t_map *map)
{
	int i;
	int j;

	while(i <= map->height)
	{
		while (j <= map->width)
		{
			if(map->carte[i][j] == 1)
				mlx_put_image_to_window(game->mlx, game->window, game->sprites->wall, i*50, j*50); //(mlx, window, coordenada x, coordenada y)
			else if(map->carte[i][j] == 0)
				mlx_put_image_to_window(game->mlx, game->window, game->sprites->floor, i*50, j*50);
			else if(map->carte[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, game->sprites->player, i*50, j*50);
			else if(map->carte[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->sprites->coin, i*50, j*50);
			else if(map->carte[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->sprites->exit, i*50, j*50);
			j++;
		}
		i++;
	}
}