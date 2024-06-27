/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:11:51 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/27 11:37:50 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (argc != 2)
		exit(1);
	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_printf("Error\n failure on map memory allocation");
		exit(EXIT_FAILURE);
	}
	game = malloc(sizeof(t_game));
	if (!game)
	{
		free(map);
		ft_printf("Error\n failure on game struct memory allocation");
		exit(EXIT_FAILURE);
	}
	set_game(map, game, argv);
	return (0);
}
