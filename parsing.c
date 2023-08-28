#include "cube3d.h"

void remove_extra_lines(char ***ptr)
{
    if (ptr == NULL || *ptr == NULL)
        return ;

    char **map = *ptr;

    // Count the number of lines
    int lineCount = 0;
    while (map[lineCount] != NULL)
        lineCount++;

    // Calculate the remaining number of lines after removing the first six
    int remainingLines = lineCount - 6;
    if (remainingLines <= 0)
	{
        // If there are no lines left after removing the first six
        *map = NULL;
        return;
    }

    // Allocate memory for the new array of lines
    char **newmap = (char **)malloc((remainingLines + 1) * sizeof(char *));
    if (!newmap)
	{
        perror("Memory allocation failed");
        exit(1);
    }

    // Copy the remaining lines to the new array
	int i = 0;
    while (i < remainingLines)
	{
        newmap[i] = map[i + 6];
		i++;
    }
    newmap[remainingLines] = NULL;

    // Free the old array and update the pointer
    free(map);
    *ptr = newmap;
}

void	ft_read_map(t_data *data)
{
	int lines_read_count;

	lines_read_count = 0;
	while (1)
	{
		// free(data->str);
		data->str = get_next_line(data->fd);
		if (data->str && (ft_strncmp(data->str, "\n", 1) != 0))
			lines_read_count++;
		if (data->str == NULL)
			break ;
		if ((ft_strncmp(data->str, "\n", 1) == 0) && lines_read_count > 6)
		{
			write(2, "Error :\nmap\n", ft_strlen("Error :\nmap\n"));
			exit(EXIT_FAILURE);
		}
		data->maps = ft_strjoin_line(data->maps, data->str);
	}
	if (!data->maps)
	{
		write(2, "Error :\nmap\n", ft_strlen("Error :\nmap\n"));
		exit(EXIT_FAILURE);
	}
	data->map.map = ft_split(data->maps, '\n');
	remove_extra_lines(&data->map.map);
	
}

void	check_texture_color(t_data *data)
{
	char	*str;
	char	*line;
	char	**lines;
	
	line = NULL;
	lines = NULL;
	while (1)
	{
		str = get_next_line(data->fd);
		if (str == NULL)
			break ;
		line = ft_strjoin_line(line, str);
	}
	if (!line)
	{
		write(2, "Error :\nmap\n", ft_strlen("Error :\nmap\n"));
		exit(EXIT_FAILURE);
	}
	lines = ft_split(line, '\n');
	lines = filter_whitespace_lines(lines);
	remove_whitespace_beginning(lines);
	check_texture(lines, data);
	check_color(lines, data);
}

void	extention_and_permission(int ac, t_data *data)
{
	if (ac <= 1)
	{
		write(2, "Error :\n", ft_strlen("Error :\n"));
		write(2, "Invalid arguments\n", ft_strlen("Invalid arguments\n"));
		exit(EXIT_FAILURE);
	}
	if (!ft_strrchr(data->av[1], '.') || (ft_strlen(data->av[1]) < 4 && \
	ft_strncmp(ft_strrchr(data->av[1], '.'), ".map\0", 5) != 0))
	{
		write(2, "Error :\n", ft_strlen("Error :\n"));
		write(2, "Invalid arguments\n", ft_strlen("Invalid arguments\n"));
		exit(EXIT_FAILURE);
	}
	data->fd = open(data->av[1], O_RDWR);
	if (data->fd < 0)
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		exit(EXIT_FAILURE);
	}
}

void	parsing(int ac, t_data *data)
{
	extention_and_permission(ac, data);
	check_texture_color(data);
	/*reseting the offset*/
	close(data->fd);
	data->fd = open(data->av[1], O_RDWR);
	if (data->fd < 0)
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		exit(EXIT_FAILURE);
	}
	/*done reseting*/
	ft_read_map(data);
}