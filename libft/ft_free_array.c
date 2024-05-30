/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:52:33 by rmarcano          #+#    #+#             */
/*   Updated: 2024/05/30 16:52:36 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char ***array)
{
	int	i;

	if (*array)
	{
		i = 0;
		while ((*array)[i])
		{
			free((*array)[i]);
			i++;
		}
		free(*array);
		*array = NULL;
	}
}
