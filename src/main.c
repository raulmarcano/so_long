/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:11:51 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/17 18:33:21 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int argc, char **argv)
{
	t_map *map;
    void *mlx;
    void *window;
    void *img;
    int h;
    int w;

    if (argc != 2)
    {
        exit(1);
    }
	map = malloc(sizeof(t_map));
    if(!map)
    {
        ft_printf("Error\n failure on map memory allocation");
        exit(EXIT_FAILURE);
    }
    mlx = mlx_init();
    window = mlx_new_window(mlx, 1000, 700, "so_long");
    img = mlx_xpm_file_to_image(mlx, "./FLOOR.xpm", &h, &w);
    mlx_put_image_to_window(mlx, window, img, 10*52, 10); //(mlx, window, coordenada x, coordenada y)
    mlx_loop(mlx);
    window = window;
    save_map(map, argv[1]);
    clean_n_exit(map);
    return (0);
}
