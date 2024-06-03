/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:26:34 by rmarcano          #+#    #+#             */
/*   Updated: 2024/06/03 12:45:17 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	map->carte = ft_calloc(((map->height) + 1), sizeof(char *));
	if (!map->carte)
	{
		ft_printf("Error: failure on map memory allocation");
		exit(EXIT_FAILURE);
	}
	map->width = ft_width(argv);
}

void	save_map(t_map *map, char *argv)
{
	int		i;
	char	*line;

	init_map(map, argv);
	map->fd = open(argv, O_RDONLY);
	if (map->fd < 0)
	{
		ft_printf("Error: couldn't open map file");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i <= (map->height - 1))
	{
		map->carte[i] = ft_calloc((map->width + 1), sizeof(char));
		line = get_next_line(map->fd);
		ft_strlcpy(map->carte[i], line, (map->width + 1));
		free(line);
		i++;
	}
	close(map->fd);
}
