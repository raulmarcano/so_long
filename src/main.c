/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:11:51 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/25 20:21:34 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_close(int key, t_game *game)
{
    if(key == XK_Escape)
    {
        mlx_destroy_window(game->mlx, game->window);
        exit(EXIT_SUCCESS);
    }
	return (0);
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
	//When the game is ended, it has to break the loop

	mlx_key_hook(game->window, ft_close, game);
	ft_printf("Pasa por aquí");
    mlx_loop(game->mlx);
	free(game->mlx);
	free(game->window);
	free(game);
    clean_n_exit(map);
    return (0);
}
