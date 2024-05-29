/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:26:34 by rmarcano          #+#    #+#             */
/*   Updated: 2024/05/29 17:40:12 by rmarcano         ###   ########.fr       */
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

int	ft_heigth(char *argv)
{
    int fd;
    int count_y;
    char *line;

    count_y = 0;
    fd = open(argv, O_RDONLY);
    while((line = get_next_line(fd)) != NULL)
    { 
        count_y++;
        free(line);
    }
	close(fd);
	return(count_y);
}

int	ft_width(char *argv)
{
    int fd;
    int count_x;
	int x;
    char *line;

    count_x = 0;
    fd = open(argv, O_RDONLY);

	line = get_next_line(fd);
    if (line != NULL)
	{
        x = ft_strlen_notab(line);
        free(line);
    }

    while((line = get_next_line(fd)) != NULL)
    { 
        count_x = ft_strlen_notab(line);
        free(line);
		if (count_x != x)
		{
			perror("mal");
			exit(EXIT_FAILURE);
		}
    }
	close(fd);
	return(count_x);
}

void save_map(t_map *map, char *argv)
{
    int i;
    char *line;

    
    map->heigth = ft_heigth(argv);
	map->width = ft_width(argv);
    map->carte = ft_calloc(((map->heigth) + 1), sizeof(char *));
    map->fd = open(argv, O_RDONLY);
	i = 0;
    while(i <= (map->heigth - 1))
    {
        map->carte[i] = ft_calloc((map->width + 1), sizeof(char));
        line = get_next_line(map->fd);
		ft_strlcpy(map->carte[i], line, (map->width + 1));
        free(line);
        i++;
    }
	close(map->fd);
}
