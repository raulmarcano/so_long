/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:27:10 by rmarcano          #+#    #+#             */
/*   Updated: 2024/07/01 17:06:43 by rmarcano         ###   ########.fr       */
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

void	iter_animation(t_game *game, int counter, int x, int y)
{
	t_sprite	p_sprite;

	p_sprite = game->sprites;
	if (counter == 10000)
		mlx_put_image_to_window(game->mlx, game->window,
			p_sprite.badguy2, x * 64, y * 64);
	if (counter == 30000)
		mlx_put_image_to_window(game->mlx, game->window,
			p_sprite.badguy, x * 64, y * 64);
	if (counter == 50000)
		mlx_put_image_to_window(game->mlx, game->window,
			p_sprite.badguy2, x * 64, y * 64);
	if (counter == 70000)
		mlx_put_image_to_window(game->mlx, game->window,
			p_sprite.badguy, x * 64, y * 64);
}

void	put_bad_animation(t_game *game, int counter)
{
	int		y;
	int		x;

	y = 0;
	while (game->map->carte[y])
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->carte[y][x] == 'B')
				iter_animation(game, counter, x, y);
			x++;
		}
		y++;
	}
}

int	animation(t_game *game)
{
	static int	counter;

	if (!counter)
		counter = 0;
	put_bad_animation(game, counter);
	counter++;
	if (counter == 90000)
		counter = 0;
	return (0);
}
