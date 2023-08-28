#include "cube3d.h"

void get_texture_path(char *line, t_data *data, t_flags direction)
{
	int i;

	i = 0;
	if (!isspace(line[i]))
	{
		printf("Error\n");
		exit(1);
	}
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	// printf("inside = = %s\n", line + i);
	if (direction == NORTH)
		data->map.north_texture = line + i;
	else if (direction == SOUTH)
		data->map.south_texture = line + i;
	else if (direction == EAST)
		data->map.east_texture = line + i;
	else if (direction == WEST)
		data->map.west_texture = line + i;
}

void	check_texture(char **map, t_data *data)
{
	int i;

	i = 0;
	while (map[i] && i < 6)// first six lines check texture and color
	{
		// printf("6 = %s\n", map[i]);
		if (ft_strncmp(map[i], "NO", 2) == 0)
			get_texture_path(map[i] + 2, data, NORTH);
		else if (ft_strncmp(map[i], "SO", 2) == 0)
			get_texture_path(map[i] + 2, data, SOUTH);
		else if (ft_strncmp(map[i], "EA", 2) == 0)
			get_texture_path(map[i] + 2, data, EAST);
		else if (ft_strncmp(map[i], "WE", 2) == 0)
			get_texture_path(map[i] + 2, data, WEST);
		// free_split(map);
		i++;
	}
	// if (open(data->map.north_texture, O_RDONLY) < 0
	// 	|| open(data->map.south_texture, O_RDONLY) < 0
	// 	|| open(data->map.east_texture, O_RDONLY) < 0
	// 	|| open(data->map.west_texture, O_RDONLY) < 0)
	// {
	// 	write(2, "Error\n", ft_strlen("Error\n"));
	// 	exit(EXIT_FAILURE);
	// }
}