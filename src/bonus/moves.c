/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:27:50 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/27 13:06:24 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_move(t_game *game, int x, int y)
{
	if (game->map->carte[y][x] == 'E')
	{
		game->count_moves++;
		ft_printf("\nMoves: %d", game->count_moves);
		ft_printf("\n\n¡YOU WIN!\n\n");
		ft_free_array(&game->map->carte);
		free(game->map);
		destroy_all(game);
		exit(EXIT_FAILURE);
	}
	if (game->map->carte[y][x] == 'B')
	{
		game->count_moves++;
		ft_printf("\nMoves: %d", game->count_moves);
		ft_printf("\n\n¡YOU LOSE!\n\n");
		ft_free_array(&game->map->carte);
		free(game->map);
		destroy_all(game);
		exit(EXIT_FAILURE);
	}
	else if (game->map->carte[y][x] == '1')
		return (1);
	else if (game->map->carte[y][x] == 'C')
		game->map->coins--;
	else
		return (0);
	return (0);
}

void	move_up(t_game *game, int x, int y)
{
	if (!check_move(game, game->map->player.x, game->map->player.y - 1))
	{
		game->map->carte[y][x] = '0';
		game->map->carte[y - 1][x] = 'P';
		game->map->player.y--;
		game->count_moves++;
		ft_printf("\nMoves: %d", game->count_moves);
	}
}

void	move_down(t_game *game, int x, int y)
{
	if (!check_move(game, game->map->player.x, game->map->player.y + 1))
	{
		game->map->carte[y][x] = '0';
		game->map->carte[y + 1][x] = 'P';
		game->map->player.y++;
		game->count_moves++;
		ft_printf("\nMoves: %d", game->count_moves);
	}
}

void	move_left(t_game *game, int x, int y)
{
	if (!check_move(game, game->map->player.x - 1, game->map->player.y))
	{
		game->map->carte[y][x] = '0';
		game->map->carte[y][x - 1] = 'P';
		game->map->player.x--;
		game->count_moves++;
		ft_printf("\nMoves: %d", game->count_moves);
	}
}

void	move_right(t_game *game, int x, int y)
{
	if (!check_move(game, game->map->player.x + 1, game->map->player.y))
	{
		game->map->carte[y][x] = '0';
		game->map->carte[y][x + 1] = 'P';
		game->map->player.x++;
		game->count_moves++;
		ft_printf("\nMoves: %d", game->count_moves);
	}
}
