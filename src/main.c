/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:11:51 by rmarcano          #+#    #+#             */
/*   Updated: 2024/05/28 19:02:47 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void get_map(char *argv)
{
    int fd;
    char *line;
    char *temp;
    char **map;
    int heigth;
    int i;

    i = 0;
    heigth = 0;
    line = NULL;
    fd = open(argv, O_RDONLY);
    line = get_next_line(fd);
    temp = ft_strdup(line);
    while(line != NULL)
    {
        free(line);
        line = get_next_line(fd);
        temp = ft_strjoin(temp, line);
    }
    close(fd);
    fd = open(argv, O_RDONLY);
    map = malloc(heigth * sizeof(char *));
    while(map[i])
    {
        map[i] = get_next_line(fd);
        i++;   
    }
    while(map[i])
    {
        ft_printf("%s", map[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    if(argc != 2)
        exit(1);
    get_map(argv[1]);
    
    return (0);
}
