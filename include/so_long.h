/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:12:28 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/03 12:39:24 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
//# include <../minilibx/mlx.h>

typedef struct s_map
{
	int		fd;
	int		height;
	int		width;
	char	**carte;
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

#endif