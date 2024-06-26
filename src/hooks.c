/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:52:21 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/26 15:11:58 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	click_x(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
}

int	ft_key_press(int key, t_game *game)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(game->mlx, game->window);
		exit(EXIT_SUCCESS);
	}
	else if (key == XK_Up || key == XK_w)
		move_up(game, game->map->player.x, game->map->player.y);
	else if (key == XK_Left || key == XK_a)
		move_left(game, game->map->player.x, game->map->player.y);
	else if (key == XK_Down || key == XK_s)
		move_down(game, game->map->player.x, game->map->player.y);
	else if (key == XK_Right || key == XK_d)
		move_right(game, game->map->player.x, game->map->player.y);
	if (game->map->coins == 0)
		game->map->carte[game->map->exit.y][game->map->exit.x] = 'E';
	print_images(game, game->map);
	return (0);
}
