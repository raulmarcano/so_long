/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:27:10 by rmarcano          #+#    #+#             */
/*   Updated: 2024/07/01 12:08:15 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	counter_on_screen(t_game *game, int counter)
{
	char	*string;

	mlx_put_image_to_window(game->mlx, game->window,
		game->sprites.background, 0, 0);
	string = ft_itoa(counter);
	mlx_string_put(game->mlx, game->window, 15, 25, 0xffc64b, "Moves:");
	mlx_string_put(game->mlx, game->window, 100, 25, 0xffc64b, string);
	free(string);
}

// int	animation()
// {

// }
