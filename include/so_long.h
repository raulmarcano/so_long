/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:12:28 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/04 19:37:31 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
//# include <../minilibx/mlx.h>

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_map
{
	int		fd;
	int		height;
	int		width;
	char	**carte;
	t_coord	player;
	t_coord	exit;
	int		coins;
}	t_map;

typedef struct s_game
{
	t_map	map;
}	t_game;

	//GET_MAP
void	init_map(t_map *map, char *argv);
size_t	ft_strlen_notab(const char *str);
void	save_map(t_map *map, char *argv);

	//DIMENSIONS
int		ft_height(char *argv);
int		ft_width(char *argv);

	//PARSE
void	check_characters(t_map *map);
void	clean_n_exit(t_map *map);

	//FLOOD FILL
char	**cpy_map(t_map *map);
void	get_coord(t_map *map);
void	start_flood_fill(t_map *map);
void	flood_fill(t_map *map, int x, int y, char **map_cpy);

#endif