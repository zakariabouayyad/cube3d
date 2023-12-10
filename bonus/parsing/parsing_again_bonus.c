/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_again_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:29:21 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/15 14:52:50 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_check_name_map(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[len - 4] == '.' && map_name[len - 3] == 'c' && \
		map_name[len - 2] == 'u' && map_name[len - 1] == 'b')
		return (0);
	return (1);
}

void	get_width_height(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->map.col = 0;
	while (map[i])
		i++;
	data->map.row = i;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (j > data->map.col)
				data->map.col = j;
			j++;
		}
		i++;
	}
	data->map.col++;
	data->map_width = data->map.col * TILE_SIZE;
	data->map_height = data->map.row * TILE_SIZE;
}

char	**remove_newline(char **map)
{
	int		i;
	int		lines;
	char	**new_map;

	if (!map)
		print_error("Error\nmap\n");
	i = 0;
	lines = 0;
	while (map[i])
		i++;
	lines = i;
	i = 0;
	new_map = (char **)malloc(sizeof(char *) * lines + 1);
	if (!new_map)
		print_error("Error\nmap\n");
	while (map[i])
	{
		if (!map[i + 1])
			new_map[i] = ft_substr(map[i], 0, ft_strlen(map[i]));
		else
			new_map[i] = ft_substr(map[i], 0, ft_strlen(map[i]) - 1);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
