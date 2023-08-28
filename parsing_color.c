#include "cube3d.h"

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
			return (false);
		i++;
	}
	return (true);
}

void	get_rgb(char **str, t_color *color)
{
	color->red = ft_atoi(str[0]);
	color->green = ft_atoi(str[1]);
	color->blue = ft_atoi(str[2]);
}

bool	color_num_check(char **str)
{
	int i;
	//cheking if the number of the color is greater than 255
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

void get_color(char *line, t_data *data, t_flags flag)
{
	int i;

	i = 0;

	if (!isspace(line[i]))
	{
		printf("Error1\n");
		exit(1);
	}
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (check_types_ncommas(line + i) == false)
	{
		printf("Error2\n");
		exit(1);
	}
	char **str = ft_split(line + i, ',');
	if (color_num_check(str) == false)
	{
		printf("Error\n");
		exit(1);
	}
	if (flag == CEILING)
		get_rgb(str, &data->map.ceiling_color);
	if (flag == FLOR)
		get_rgb(str, &data->map.flor_color);
}

void	check_color(char **map, t_data *data)
{
	int i;

	i = 0;
	while (map[i] && i < 6)// first six lines check texture and color
	{
		if (ft_strncmp(map[i], "F", 1) == 0)
			get_color(map[i] + 1, data, FLOR);
		else if (ft_strncmp(map[i], "C", 1) == 0)
			get_color(map[i] + 1, data, CEILING);
		// free_split(map);
		i++;
	}
}