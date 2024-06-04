/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:12:07 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/04 18:45:05 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	clean_n_exit(t_map *map)
{
	ft_free_array(&map->carte);
	free(map);
	exit(EXIT_FAILURE);
}

void	check_borders(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->carte[i][j])
		{
			if ((i == 0 || i == map->height - 1) && map->carte[i][j] != '1')
			{
				ft_printf("Error\n Borders not correct\n");
				clean_n_exit(map);
			}
			if ((j == 0 || j == map->width - 1) && map->carte[i][j] != '1')
			{
				ft_printf("Error\n Borders not correct\n");
				clean_n_exit(map);
			}
			j++;
		}
		i++;
	}
}

void	count_pec(t_map *map, int cap_p, int cap_e, int cap_c)
{
	int	err;

	err = 0;
	if (cap_p != 1)
	{
		ft_printf("Error\n Invalid number of Player (Expeted 1 Player)\n");
		err = 1;
	}
	if (cap_e != 1)
	{
		ft_printf("Error\n Invalid number of Exit (Expeted 1 Exit)\n");
		err = 1;
	}
	if (cap_c < 1)
	{
		ft_printf("Error\n Coins must be more than 0\n");
		err = 1;
	}
	if (err)
		clean_n_exit(map);
}

void	check_count_characters(t_map *map, int i, int j)
{
	int	cap_p;
	int	cap_e;
	int	cap_c;

	cap_p = 0;
	cap_e = 0;
	cap_c = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->carte[i][j])
		{
			if (map->carte[i][j] == 'P')
				cap_p++;
			else if (map->carte[i][j] == 'E')
				cap_e++;
			else if (map->carte[i][j] == 'C')
				cap_c++;
			j++;
		}
		i++;
	}
	map->coins = cap_c;
	count_pec(map, cap_p, cap_e, cap_c);
}

void	check_characters(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->carte[i][j])
		{
			c = map->carte[i][j];
			if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
			{
				ft_printf("Error\n Forbidden characters\n");
				clean_n_exit(map);
			}
			j++;
		}
		i++;
	}
	i = 0;
	check_borders(map);
	check_count_characters(map, i, j);
}
