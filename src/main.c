/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:11:51 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/25 16:45:18 by rmarcano         ###   ########.fr       */
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
void max_screensize(t_game *game, t_map *map)
{
	int x;
    int y;
	mlx_get_screen_size(game->mlx, &x, &y);
	if((map->width * 64) > x || ((map->height + 3) * 64) > y)
	{
		ft_printf("Error\n Map too big\n");
		free(game->mlx);
		free(game);
		clean_n_exit(map);
	}
}

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
    game->mlx = mlx_init();
    save_map(map, argv[1]);
	max_screensize(game, map);
    game->window = mlx_new_window(game->mlx, map->width * 64, map->height * 64, "so_long");
	
	set_images(game, &game->sprites);
	print_images(game, map, &game->sprites);
    mlx_loop(game->mlx);
	//When the game is ended, it has to break the loop
    clean_n_exit(map);
    return (0);
}
