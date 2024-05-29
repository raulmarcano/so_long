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

void check_borders(t_map map)
{
    void check_top_bttm(map, 0);
    void check_top_bttm(map, map->height);
}

void check_top_bttm(char **map, int coord)
{
    int i;

    i = 0;
    while(map[coord][i])
    {
        if (map[coord][i] != 1)
        {
            ft_printf("Error de borders");
            exit(1);
        }
        
    }
}

int main(int argc, char **argv)
{
	t_map *map;

    if (argc != 2)
    {
        exit(1);
    }
	map = malloc(sizeof(t_map));
    save_map(map, argv[1]);
    check_map(map->carte);
    return (0);
}
