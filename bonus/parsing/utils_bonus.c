/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:55:51 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/15 14:56:36 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	free_double(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

bool	is_all_white(const char *str)
{
	if (!str)
		return (false);
	while (*str)
	{
		if (!my_isspace((unsigned char)*str))
			return (false);
		str++;
	}
	return (true);
}

void	player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map2[i])
	{
		j = 0;
		while (data->map.map2[i][j])
		{
			if (data->map.map2[i][j] == 'N' || data->map.map2[i][j] == 'S'
				|| data->map.map2[i][j] == 'E' || data->map.map2[i][j] == 'W')
			{
				data->player.starting_pos = data->map.map2[i][j];
				data->player.x = j * TILE_SIZE + (TILE_SIZE / 2);
				data->player.y = i * TILE_SIZE + (TILE_SIZE / 2);
			}
			j++;
		}
		i++;
	}
}

void	check_chars(char **map)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	j = 0;
	player_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' 
				|| map[i][j] == 'W' || map[i][j] == 'E')
				player_count++;
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N'
			&& map[i][j] != 'S' && map[i][j] != 'W' && map[i][j] != 'E'
			&& map[i][j] != 'D' && map[i][j] != ' ' && map[i][j] != '\t')
				print_error("Error\nmap\n");
			j++;
		}
		i++;
	}
	if (player_count != 1)
		print_error("Error\nmap\n");
}

void	map_size(char *map, t_data *data)
{
	int		fd;
	char	*line;

	data->map_lines = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		print_error("Error\nopen\n");
	line = get_next_line(fd);
	while (line)
	{
		if (!is_all_white(line))
			data->map_lines++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (data->map_lines <= 6)
		print_error("Error\nmap\n");
	data->map_lines -= 6;
}
