/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:11:51 by rmarcano          #+#    #+#             */
/*   Updated: 2024/05/29 18:14:23 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void check_top_bttm(char **map, int coord)
{
    int i;

    i = 0;
    while(map[coord][i])
    {
        if (map[coord][i] != '1')
        {
            ft_printf("Error: Borders not correct\n");

            exit(EXIT_FAILURE);
        }
        i++;
    }
}
void check_borders(t_map *map)
{
    check_top_bttm(map->carte, 0);
    check_top_bttm(map->carte, (map->height - 1));
}


int main(int argc, char **argv)
{
	t_map *map;

    if (argc != 2)
    {
        exit(1);
    }
	map = malloc(sizeof(t_map));
    if(!map)
    {
        ft_printf("Error: failure on map memory allocation");
        exit(EXIT_FAILURE);
    }
    save_map(map, argv[1]);
    check_borders(map);
    return (0);
}
