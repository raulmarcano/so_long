/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:22:52 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/25 16:56:28 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_width(int fd, int expected_width)
{
	char	*line;
	int		count_x;

	line = get_next_line(fd);
	while (line != NULL)
	{
		count_x = ft_strlen_notab(line);
		free(line);
		if (count_x != expected_width)
		{
			ft_printf("Error\n Bad map dimensions\n");
			close(fd);
			exit(EXIT_FAILURE);
		}
		line = get_next_line(fd);
	}
}

int	ft_width(char *argv)
{
	int		fd;
	int		x;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n Couldn't open map file\n");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_printf("Error\n Empty map file\n");
		close(fd);
		exit(EXIT_FAILURE);
	}
	x = ft_strlen_notab(line);
	free(line);
	check_width(fd, x);
	close(fd);
	return (x);
}

int	ft_height(char *argv)
{
	int		fd;
	int		count_y;
	char	*line;

	count_y = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n Couldn't open map file");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		count_y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count_y);
}

void	max_screensize(t_game *game, t_map *map)
{
	int	x;
	int	y;

	mlx_get_screen_size(game->mlx, &x, &y);
	if ((map->width * 64) > x || ((map->height + 3) * 64) > y)
	{
		ft_printf("Error\n Map too big\n");
		free(game->mlx);
		free(game);
		clean_n_exit(map);
	}
}
