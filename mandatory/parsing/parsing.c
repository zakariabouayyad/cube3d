/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:30:58 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/15 15:45:01 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**n_read_six(int lines_read_count, int i, int fd)
{
	char	**six;
	char	*line;

	six = (char **)malloc(sizeof(char *) * (6 + 1));
	if (!six)
		print_error("Error\nmap\n");
	line = get_next_line(fd);
	while (line)
	{
		if (lines_read_count > 6)
			break ;
		if (line && (ft_strncmp(line, "\n", 1) != 0) && !is_all_white(line))
			lines_read_count++;
		if ((ft_strncmp(line, "\n", 1) != 0) 
			&& !is_all_white(line) && lines_read_count <= 6)
		{
			six[i] = ft_strdup(line);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	six[i] = NULL;
	return (six);
}

char	**read_six(char *file)
{
	int		fd;
	char	**six;
	int		lines_read_count;
	int		i;

	lines_read_count = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("Error\nopen\n");
	six = n_read_six(lines_read_count, i, fd);
	close(fd);
	return (six);
}

char	**remove_newline6(char **map)
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
	new_map = (char **)malloc(sizeof(char *) * 6 + 1);
	if (!new_map)
		print_error("Error\nmap\n");
	while (map[i])
	{
		new_map[i] = ft_substr(map[i], 0, ft_strlen(map[i]) - 1);
		free(map[i]);
		i++;
	}
	free(map);
	new_map[i] = NULL;
	return (new_map);
}

char	**n_read_map(t_data *data, int i, int fd, int read)
{
	char	**all_file;
	char	*line;

	all_file = (char **)malloc(sizeof(char *) * (data->map_lines + 1));
	if (!all_file)
		print_error("Error\nmalloc\n");
	line = get_next_line(fd);
	while (line)
	{
		if (!is_all_white(line))
			read++;
		if (read > 6 && (ft_strncmp(line, "\n", 1) == 0))
			print_error("Error\nnew line in map\n");
		if (read > 6 && !is_all_white(line))
		{
			all_file[i] = ft_strdup(line);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	all_file[i] = NULL;
	return (all_file);
}

char	**read_map(t_data *data, char *file)
{
	int		fd;
	char	**all_file;
	int		i;
	int		read;

	i = 0;
	read = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("Error\nopen\n");
	all_file = n_read_map(data, i, fd, read);
	close(fd);
	return (all_file);
}
