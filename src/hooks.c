/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:52:21 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/27 11:04:53 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	click_x(t_game *game)
{
	ft_printf("\nYou gave up :(\n");
	ft_free_array(&game->map->carte);
	free(game->map);
	destroy_all(game);
	exit(EXIT_SUCCESS);
}

int	ft_key_press(int key, t_game *game)
{
	if (key == XK_Escape)
		click_x(game);
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
