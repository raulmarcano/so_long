/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:26:34 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/27 10:00:11 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_extension(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len < 5)
	{
		ft_printf("Error\n Map name too short");
		exit(EXIT_FAILURE);
	}
	if ((ft_strncmp(&map_name[len - 4], ".ber", 4) != 0)
		|| (ft_strncmp(&map_name[len - 5], "/.ber", 5) == 0))
	{
		ft_printf("Error\n Bad map extension, must be file_name.ber\n");
		exit(EXIT_FAILURE);
	}
}

size_t	ft_strlen_notab(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	init_map(t_map *map, char *argv)
{
	map->height = ft_height(argv);
	map->width = ft_width(argv);
	map->carte = ft_calloc(((map->height) + 1), sizeof(char *));
	if (!map->carte)
	{
		ft_printf("Error\n Failure on map memory allocation");
		exit(EXIT_FAILURE);
	}
}

void	save_map(t_map *map, char *argv)
{
	int		i;
	char	*line;

	check_extension(argv);
	init_map(map, argv);
	map->fd = open(argv, O_RDONLY);
	if (map->fd < 0)
	{
		ft_printf("Error\n Couldn't open map file");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i <= (map->height - 1))
	{
		map->carte[i] = ft_calloc((map->width + 1), sizeof(char));
		line = get_next_line(map->fd, 0);
		ft_strlcpy(map->carte[i], line, (map->width + 1));
		free(line);
		i++;
	}
	line = get_next_line(map->fd, 1);
	check_characters(map);
	start_flood_fill(map);
	close(map->fd);
}
