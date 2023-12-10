/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:41:11 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/15 15:42:52 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_types_ncommas(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (false);
	i = 0;
	while (line[i])
	{
		if (line[i] != ',' && !isdigit(line[i]))
		{
			return (false);
		}
		i++;
	}
	return (true);
}

int	rgb_to_hex(t_color color)
{
	int	color_nbr;

	color_nbr = 0;
	color_nbr |= (color.red & 0xFF) << 16;
	color_nbr |= (color.green & 0xFF) << 8;
	color_nbr |= (color.blue & 0xFF);
	return (color_nbr);
}

void	get_rgb(char **str, t_color *color)
{
	if (!str[0] || !str[1] || !str[2])
		print_error("Error\ncolor\n");
	color->red = ft_atoi(str[0]);
	color->green = ft_atoi(str[1]);
	color->blue = ft_atoi(str[2]);
}

bool	color_num_check(char **str)
{
	int	i;

	i = 0;
	if (str[0] == NULL)
		return (false);
	while (str[i])
	{
		if (ft_strlen(str[i]) < 1 || ft_strlen(str[i]) > 3)
			return (false);
		if (ft_atoi(str[i]) > 255)
			return (false);
		i++;
	}
	return (true);
}

void	get_color(char *line, t_data *data, t_flags direction)
{
	int		i;
	char	**str;

	i = 0;
	if (!my_isspace(line[i]))
		print_error("Error\ncolor\n");
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (check_types_ncommas(line + i) == false)
		print_error("Error\ncolor\n");
	str = ft_split(line + i, ',');
	if (color_num_check(str) == false)
		print_error("Error\ncolor\n");
	if (direction == FLOR)
		get_rgb(str, &data->map.flor_color);
	else if (direction == CEILING)
		get_rgb(str, &data->map.ceiling_color);
	free_double(str);
	data->ceiling_color = rgb_to_hex(data->map.ceiling_color);
	data->flor_color = rgb_to_hex(data->map.flor_color);
}
