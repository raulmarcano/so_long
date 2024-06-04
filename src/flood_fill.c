/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:51:09 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/04 19:56:02 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**cpy_map(t_map *map)
{
	int		i;
	char **carte_cpy;
	
	carte_cpy = ft_calloc(((map->height) + 1), sizeof(char *));
	i = 0;
	while (i <= (map->height - 1))
	{
		carte_cpy[i] = ft_strdup(map->carte[i]);
		if(carte_cpy[i] == NULL)
		{
			while(i >= 0)
			{
				free(carte_cpy[i]);
				i--;
			}
			free(carte_cpy);
			clean_n_exit(map);
		}
		i++;
	}
	return(carte_cpy);
}

void	get_coord(t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->carte[y][x])
		{
			if (map->carte[y][x] == 'P')
			{
				map->player.x = x;
				map->player.y = y;
			}
			else if (map->carte[y][x] == 'E')
			{
				map->exit.x = x;
				map->exit.y = y;
			}
			x++;
		}
		y++;
	}
}
void flood_fill(t_map *map, int x, int y, char **map_cpy)
{
	if (map_cpy[y][x] == '1' || map_cpy[y][x] == 'R')
		return ;
	if (map_cpy[y][x] == 'C')
		map->coins--;
	map_cpy[y][x] = 'R';
		flood_fill(map, x, y - 1, map_cpy);//Up
		flood_fill(map, x + 1, y, map_cpy);//Right
		flood_fill(map, x, y + 1, map_cpy);//Down
		flood_fill(map, x - 1, y, map_cpy);//Left
}

void start_flood_fill(t_map *map)
{
	char **map_cpy;
	int coins_guard;

	coins_guard = map->coins;
	map_cpy = cpy_map(map);
	get_coord(map);
	flood_fill(map, map->player.x, map->player.y, map_cpy);
	int i;

	i = 0;
	while (i <= (map->height - 1))
	{
		ft_printf("%s\n", map_cpy[i]);
		i++;
	}
	if (map->coins != 0)
		ft_printf("Error: Not all coins collected, %d left.\n", map->coins);
	//clean and exit
	ft_free_array(&map_cpy);
	map->coins = coins_guard;
	ft_printf("coins:%d\n", map->coins);
}

