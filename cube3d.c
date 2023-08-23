/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:43:18 by zbouayya          #+#    #+#             */
/*   Updated: 2023/08/23 16:01:24 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


// void draw_square(void *mlx, void *win, int x, int y, int size, int color)
// {
//     int end_x = x + size;
//     int end_y = y + size;

//     while (y < end_y)
// 	{
//         x = end_x - size;  // Reset x to the starting position for each row
//         while (x < end_x)
// 		{
//             mlx_pixel_put(mlx, win, x, y, color);
//             x++;
//         }
//         y++;
//     }
// }

// void	make_map(t_data	*data)
// {
// 	data->i = 0;
// 	while (data->map[data->i])
// 	{	
// 	// data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
// 		data->j = 0;
// 		while (data->map[data->i][data->j])
// 		{
// 			if (data->map[data->i][data->j] == '0')
// 					draw_square(data->mlx, data->mlx_win, data->j * TILE_SIZE, data->i * TILE_SIZE, TILE_SIZE, 0xFFFFFF);
// 			if (data->map[data->i][data->j] == '1')
// 					draw_square(data->mlx, data->mlx_win, data->j * TILE_SIZE, data->i * TILE_SIZE, TILE_SIZE, 0x000000);
// 			// if (data->map[data->i][data->j] == 'C')
// 			// 	mlx_put_image_to_window(data->mlx, data->mlx_win, data-> \
// 			// 	mlx_babysus, data->j * data->img_w, data->i * data->img_h);
// 			// if (data->map[data->i][data->j] == 'E')
// 			// 	mlx_put_image_to_window(data->mlx, data->mlx_win, \
// 			// 	data->mlx_exit, data->j * data->img_w, data->i * data->img_h);
// 			// put_player(data);
// 			data->j++;
// 		}
// 		data->i++;
// 	}
// }

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

void	ft_read_map(t_data *data)
{
	while (1)
	{
		// free(data->str);
		data->str = get_next_line(data->fd);
		if (data->str == NULL)
			break ;
		// if (ft_strncmp(data->str, "\n", 1) == 0)
		// {
		// 	write(2, "Error :\nmap\n", ft_strlen("Error :\nmap\n"));
		// 	exit(EXIT_FAILURE);
		// }
		data->maps = ft_strjoin_line(data->maps, data->str);
	}
	if (!data->maps)
	{
		write(2, "Error :\nmap\n", ft_strlen("Error :\nmap\n"));
		exit(EXIT_FAILURE);
	}
	data->map = ft_split(data->maps, '\n');
	
}

int	ft_count_lines(char *argv[])
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		perror("Error ");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		str = get_next_line(fd);
		i++;
		if (str == NULL)
			break ;
		free(str);
	}
	close(fd);
	return (i - 1);
}

// void	check_texture(char **map, t_data *data)
// {
// 	while ()
// 	{
// 		if (ft_strcmp(map, "NO") == 0)
// 			data->map.north_texture = get_path(map, "NO ");
// 		else if (ft_strcmp(map, "SO") == 0)
// 			data->map.south_texture = get_path(map, "SO ");
// 		else if (ft_strcmp(map, "EA") == 0)
// 			data->map.east_texture = get_path(map, "EA ");
// 		else if (ft_strcmp(map, "WE") == 0)
// 			data->map.west_texture = get_path(map, "WE ");
// 		// free_split(map);
// 	}
// 	if (open(data->map.north_texture, O_RDONLY) < 0
// 		|| open(data->map.south_texture, O_RDONLY) < 0
// 		|| open(data->map.east_texture, O_RDONLY) < 0
// 		|| open(data->map.west_texture, O_RDONLY) < 0)
// 	{
// 		write(2, "Error\n", ft_strlen("Error\n"));
// 		exit(EXIT_FAILURE);
// 	}
// }

bool	is_whitespace(const char *str)
{
	int	i;

	if (!str)
		return (false);
	i = 0;
	while (str[i])
	{
		// if (str[i] != 32 && str[i] >= 13 && str[i] <= 9)
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (false);
		
		i++;
	}
	return (true);
}

char **filter_whitespace_lines(char **lines, int num_lines)
{
	int filtered_count;
	filtered_count = 0;

    // Count non-empty lines
	for (int i = 0; i < num_lines; i++)
	{
		if (!is_whitespace(lines[i]))
			filtered_count++;
	}

	// printf("33333 %d\n", filtered_count);
	if (filtered_count == 0)
	{
		printf("nothing\n");	
		return (NULL);  // No non-empty lines
	}

    char **filtered_lines = (char **)malloc(filtered_count * sizeof(char *));
    if (filtered_lines == NULL)
	{
        perror("Memory allocation failed");
        exit(1);
    }
	// for (int i = 0; i < filtered_count; i++)
    // 	filtered_lines[i] = NULL;

    int filtered_index = 0;
    for (int i = 0; i < num_lines; i++)
	{
		// printf("the line %s\n", lines[i]);
		// printf("the line num %d\n", i);
        if (!is_whitespace(lines[i]))
		{
            filtered_lines[filtered_index] = ft_strdup(lines[i]);
            if (filtered_lines[filtered_index] == NULL)
			{
                perror("Memory allocation failed");
                exit(1);
            }
            filtered_index++;
        }
    }
	filtered_lines[filtered_index] = NULL;
    return (filtered_lines);
}

int count_lines(char **lines) {
    int count = 0;

    if (lines == NULL)
        return 0;

    while (lines[count] != NULL) {
        count++;
    }

    return count;
}

void	check_texture_color(t_data *data)
{
	char	*str;
	char	*line;
	char	**lines = NULL;
	
	line = NULL;
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
	int num_lines = count_lines(lines);
	printf("num of lines %d\n", num_lines);
	lines = filter_whitespace_lines(lines, num_lines);
	puts("out");
	int i = 0;

	while (lines[i])
	{
		// if (lines[i] == NULL)
		// 	printf("null \n");
			
		printf("%s\n", lines[i]);
		i++;
	}
	// check_texture(lines, data);
	// check_color(lines);
}

void	parsing(int ac, t_data *data)
{
	extention_and_permission(ac, data);
	ft_read_map(data);
	/*until here every thing is working as expected*/
	/*reseting the offset*/
	close(data->fd);
	data->fd = open(data->av[1], O_RDWR);
	if (data->fd < 0)
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		exit(EXIT_FAILURE);
	}
	/*done reseting*/
	check_texture_color(data);
}

int main(int argc, char *argv[])
{
	t_data data;

	data.av = argv;
	parsing(argc, &data);
	
	// data.mlx = mlx_init();
	// if (data.mlx == NULL)
	// 	exit(EXIT_FAILURE);
	// data.mlx_win = mlx_new_window(data.mlx, WINDOW_HEIGHT, WINDOW_WIDTH, "cube3d");
	// if (data.mlx_win == NULL)
	// 	exit(EXIT_FAILURE);
	// data.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	// make_map(&data);
	// mlx_loop(data.mlx);

	// int i = 0;
	// while (data.map[i])
	// {
	// 	printf("%s\n", data.map[i]);
	// 	i++;
	// }
}