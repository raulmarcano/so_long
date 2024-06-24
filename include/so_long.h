/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:12:28 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/17 18:22:22 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"

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

typedef struct s_sprite
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*coin;
	void	*exit;
	void	*enemy;
	void	*exit_close;
}	t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_sprite	*sprites;
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

	// KEYCODES
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_CLOSE_WIN 17

#endif