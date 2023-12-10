/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:49:42 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/15 15:43:55 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_texture_path(char *line, t_data *data, t_flags direction)
{
	int	i;

	i = 0;
	if (!my_isspace(line[i]))
		print_error("Error\ntexture\n");
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (direction == NORTH)
		data->map.north_texture = line + i;
	else if (direction == SOUTH)
		data->map.south_texture = line + i;
	else if (direction == EAST)
		data->map.east_texture = line + i;
	else if (direction == WEST)
		data->map.west_texture = line + i;
}

int	loop_tex_color(t_data *data, char **lines, int i, int count)
{
	int	j;

	j = 0;
	while (lines[i][j] == ' ' || lines[i][j] == '\t')
		j++;
	if (ft_strncmp(lines[i] + j, "NO", 2) == 0)
		(get_texture_path(lines[i] + j + 2, data, NORTH), count++);
	else if (ft_strncmp(lines[i] + j, "SO", 2) == 0)
		(get_texture_path(lines[i] + j + 2, data, SOUTH), count++);
	else if (ft_strncmp(lines[i] + j, "EA", 2) == 0)
		(get_texture_path(lines[i] + j + 2, data, EAST), count++);
	else if (ft_strncmp(lines[i] + j, "WE", 2) == 0)
		(get_texture_path(lines[i] + j + 2, data, WEST), count++);
	else if (ft_strncmp(lines[i] + j, "F ", 2) == 0)
		(get_color(lines[i] + j + 2, data, FLOR), count++, free(lines[i]));
	else if (ft_strncmp(lines[i] + j, "C ", 2) == 0)
		(get_color(lines[i] + j + 2, data, CEILING), 
			count++, free(lines[i]));
	return (count);
}

void	parse_tex_col(t_data *data, char **lines)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (!lines)
		print_error("Error\nmap\n");
	while (lines[++i])
		count = loop_tex_color(data, lines, i, count);
	if (count != 6)
	{
		if (count == 0)
			free_double(lines);
		print_error("Error\ntexture\n");
	}
	if (open(data->map.north_texture, O_RDONLY) < 0
		|| open(data->map.south_texture, O_RDONLY) < 0
		|| open(data->map.east_texture, O_RDONLY) < 0
		|| open(data->map.west_texture, O_RDONLY) < 0)
	{
		print_error("Error\ntexture\n");
	}
	free(lines);
}
