/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:11:51 by rmarcano          #+#    #+#             */
/*   Updated: 2024/07/02 17:05:55 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error\n Required just 1 map as an argument");
		exit(EXIT_FAILURE);
	}
	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_printf("Error\n failure on map memory allocation");
		exit(EXIT_FAILURE);
	}
	game = NULL;
	set_game(map, game, argv);
	return (0);
}
