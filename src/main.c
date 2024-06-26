/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:11:51 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/26 13:03:46 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void print_map(t_map *map)
{
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            printf("%c", map->carte[i][j]);
        }
        printf("\n");
    }
}

void move_up(t_game *game, int x, int y)
{
    game->map->carte[y][x] = '0';
    game->map->carte[y - 1][x] = 'P';
    game->map->player.y--;
    game->count_moves++;
    ft_printf("\nMoves: %d\n", game->count_moves);
}

void move_down(t_game *game, int x, int y)
{
    game->map->carte[y][x] = '0';
    game->map->carte[y + 1][x] = 'P';
    game->map->player.y++;
    game->count_moves++;
    ft_printf("\nMoves: %d\n", game->count_moves);
}

void move_left(t_game *game, int x, int y)
{
    game->map->carte[y][x] = '0';
    game->map->carte[y][x - 1] = 'P';
    game->map->player.x--;
    game->count_moves++;
    ft_printf("\nMoves: %d\n", game->count_moves);
}

void move_right(t_game *game, int x, int y)
{
    game->map->carte[y][x] = '0';
    game->map->carte[y][x + 1] = 'P';
    game->map->player.x++;
    game->count_moves++;
    ft_printf("\nMoves: %d\n", game->count_moves);
}


int ft_key_press(int key, t_game *game)
{
    if (key == XK_Escape)
    {
        mlx_destroy_window(game->mlx, game->window);
        exit(EXIT_SUCCESS);
    }
    else if (key == XK_Up || key == XK_w)
    {
        move_up(game, game->map->player.x, game->map->player.y);
    }
    else if (key == XK_Left || key == XK_a)
    {
        move_left(game, game->map->player.x, game->map->player.y);
    }
    else if (key == XK_Down || key == XK_s)
    {
        move_down(game, game->map->player.x, game->map->player.y);
    }
    else if (key == XK_Right || key == XK_d)
    {
        move_right(game, game->map->player.x, game->map->player.y);
    }
    print_images(game, game->map, &game->sprites);
    return (0);
}

int	click_x(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
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
    game->count_moves = 0;
    game->mlx = mlx_init();
    save_map(map, argv[1]);
    game->map = map;
	max_screensize(game, map);
    game->window = mlx_new_window(game->mlx, map->width * 64, map->height * 64, "so_long");
	
	set_images(game, &game->sprites);
	print_images(game, map, &game->sprites);
	//When the game is ended, it has to break the loop

	mlx_key_hook(game->window, ft_key_press, game);
    mlx_hook(game->window, DestroyNotify, 0, click_x, game);
    mlx_loop(game->mlx);
	free(game->mlx);
	free(game->window);
	free(game);
    clean_n_exit(map);
    return (0);
}
