/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:12:28 by rmarcano          #+#    #+#             */
/*   Updated: 2024/05/29 17:42:03 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
//# include <../minilibx/mlx.h>

typedef struct s_map
{
	int fd;
	int	heigth;
	int width;
	char **carte;
} t_map;

typedef struct s_game
{  
	t_map map;
} t_game;

	//GET_MAP
size_t	ft_strlen_notab(const char *str);
int	ft_heigth(char *argv);
int	ft_width(char *argv);
void save_map(t_map *map, char *argv);

#endif