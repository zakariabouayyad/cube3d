/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_parsing_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:01:22 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/15 14:52:40 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	get_max_line_length(char **map, t_data *data)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) >= max)
			max = ft_strlen(map[i]);
		i++;
	}
	data->max_line = max - 1;
}

char	*not_max_length(char *line, t_data *data)
{
	char	*fixd_line;
	int		i;

	i = 0;
	fixd_line = malloc(sizeof(char) * data->max_line + 1);
	if (!fixd_line)
		return (NULL);
	while (i <= data->max_line)
	{
		if (!line[i] || line[i] == '\n')
		{
			while (i <= data->max_line)
			{
				fixd_line[i] = ' ';
				i++;
			}
			fixd_line[i] = '\0';
			return (fixd_line);
		}
		fixd_line[i] = line[i];
		i++;
	}
	fixd_line[i] = '\0';
	return (fixd_line);
}

char	**fix_map(char **map, t_data *data)
{
	char	**all_file;
	int		i;

	get_max_line_length(map, data);
	if (data->map_lines <= 6)
		print_error("Error\nmap\n");
	all_file = (char **)malloc(sizeof(char *) * (data->map_lines + 1));
	if (!all_file)
		print_error("Error\nmap\n");
	i = 0;
	while (map[i])
	{
		all_file[i] = not_max_length(map[i], data);
		i++;
	}
	all_file[i] = NULL;
	return (all_file);
}

bool	check_first_last_line(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map || !*map)
		return (false);
	while (map[j])
		j++;
	j = j - 1;
	while ((map[0][i] && map[0][i] == '1') || (map[0][i] && map[0][i] == ' '))
		i++;
	if (i == (int)ft_strlen(map[0]))
	{
		i = 0;
		while ((map[j][i] && map[j][i] == '1') 
			|| (map[j][i] && map[j][i] == ' '))
			i++;
		if (i == (int)ft_strlen(map[j]))
			return (true);
	}
	printf("Error\nmap is not valid first or last\n");
	return (false);
}

void	check_map_close(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_first_last_line(map) == false)
		print_error("Error\nmap\n");
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '0' || map[j][i] == 'D' || map[j][i] == 'N'
				|| map[j][i] == 'W' || map[j][i] == 'E' || map[j][i] == 'S')
			{
				if ((!map[j - 1][i] || map[j - 1][i] == ' ')
					|| (!map[j + 1][i] || map[j + 1][i] == ' ')
					|| (!map[j][i + 1] || map[j][i + 1] == ' ')
					|| (!map[j][i - 1] || map[j][i - 1] == ' '))
					print_error("Error\nmap\n");
			}
			i++;
		}
		j++;
	}
}
