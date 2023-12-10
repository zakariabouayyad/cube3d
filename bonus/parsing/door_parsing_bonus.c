/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_parsing_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:53:02 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/15 14:50:01 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	doors_coord(t_data *data)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	data->doors = malloc(sizeof(t_doors) * data->doors_nbr);
	if (!data->doors)
		print_error("Error\nDoor\n");
	while (data->map.map2[i])
	{
		j = 0;
		while (data->map.map2[i][j])
		{
			if (data->map.map2[i][j] == 'D') 
			{
				data->doors[x].x = j * TILE_SIZE;
				data->doors[x].y = i * TILE_SIZE;
				x++;
			}
			j++;
		}
		i++;
	}
}

void	doors_parsing(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->doors_nbr = 0;
	while (data->map.map2[i])
	{
		j = 0;
		while (data->map.map2[i][j])
		{
			if (data->map.map2[i][j] == 'D')
				data->doors_nbr++;
			if (data->map.map2[i][j] == 'D') 
			{
				if ((data->map.map2[i + 1][j] != '1' 
					|| data->map.map2[i - 1][j] != '1')
					&& (data->map.map2[i][j + 1] != '1' 
					|| data->map.map2[i][j - 1] != '1'))
					print_error("Error\nDoor\n");
			}
			j++;
		}
		i++;
	}
}
