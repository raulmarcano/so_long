/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:51:09 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/04 15:56:09 by rmarcano         ###   ########.fr       */
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
		ft_printf("%s\n", carte_cpy[i]);
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
		free(carte_cpy[i]); //esto quitarlo, luego se limpia con free_array
		i++;
	}
	free(carte_cpy); //esto quitarlo
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

void	flood_fill(t_map *map)
{
	//char **map_cpy;
	
	//map_cpy = cpy_map(map);
	get_coord(map);
}