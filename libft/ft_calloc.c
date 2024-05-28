/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:48:23 by rmarcano          #+#    #+#             */
/*   Updated: 2024/05/07 15:08:17 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*arr;
	size_t		i;

	arr = malloc(count * size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}
