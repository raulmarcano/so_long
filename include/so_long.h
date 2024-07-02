/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:12:28 by rmarcano          #+#    #+#             */
/*   Updated: 2024/07/02 12:36:36 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include <X11/Xlib.h>
# include <X11/keysym.h>

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
	void	*badguy;
	void	*badguy2;
	void	*background;
}	t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_sprite	sprites;
	t_map		*map;
	int			count_moves;
}	t_game;

	//MANDATORY

//GET_MAP
void	init_map(t_map *map, char *argv);
size_t	ft_strlen_notab(const char *str);
void	save_map(t_map *map, char *argv);

//DIMENSIONS
int		ft_height(char *argv);
int		ft_width(char *argv, t_map *map);
void	max_screensize(t_game *game, t_map *map);

//PARSE
void	check_characters(t_map *map);
void	clean_n_exit(t_map *map);

//FLOOD FILL
char	**cpy_map(t_map *map);
void	get_coord(t_map *map);
void	start_flood_fill(t_map *map);
void	flood_fill(t_map *map, int x, int y, char **map_cpy);

//IMAGES
void	set_images(t_game *game, t_sprite *sprites);
void	print_images(t_game *game, t_map *map);
void	clean_images(t_game *game, t_sprite *sprites);

//MOVES
void	move_up(t_game *game, int x, int y);
void	move_down(t_game *game, int x, int y);
void	move_left(t_game *game, int x, int y);
void	move_right(t_game *game, int x, int y);

//HOOKS
int		ft_key_press(int key, t_game *game);
int		click_x(t_game *game);

//SET AND DESTROY
void	destroy_all(t_game *game);
void	set_game(t_map *map, t_game *game, char **argv);

	//BONUS

//ANIMATIONS
void	counter_on_screen(t_game *game, int counter);
void	iter_animation(t_game *game, int counter, int x, int y);
void	put_bad_animation(t_game *game, int counter);
int		animation(t_game *game);

#endif