#include "cube3d.h"

void draw_square(void *mlx, void *win, int x, int y, int size, int color)
{
    int end_x = x + size;
    int end_y = y + size;
    // int end_x = data->j * TILE_SIZE + TILE_SIZE;
    // int end_y = data->i * TILE_SIZE + TILE_SIZE;

    while (y < end_y)
	{
        x = end_x - size;  // Reset x to the starting position for each row
        while (x < end_x)
		{
            mlx_pixel_put(mlx, win, x, y, color);
            x++;
        }
        y++;
    }
}

void draw_circle(void *mlx, void *win, int center_x, int center_y, int radius, int color)
{
    int y = center_y - radius;
    while (y <= center_y + radius)
	{
        int x = center_x - radius;
        while (x <= center_x + radius)
		{
            int dx = x - center_x;
            int dy = y - center_y;
            if (dx * dx + dy * dy <= radius * radius)
			{
                mlx_pixel_put(mlx, win, x, y, color);
            }
            x++;
        }
        y++;
    }
}

void draw_line(void *mlx, void *win, int x1, int y1, int x2, int y2, int color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        mlx_pixel_put(mlx, win, x1, y1, color);

        if (x1 == x2 && y1 == y2) {
            break;
        }

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void	make_map(t_data	*data)
{
	data->i = 0;
	while (data->map.map[data->i])
	{	
	// data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		data->j = 0;
		while (data->map.map[data->i][data->j])
		{
			if (data->map.map[data->i][data->j] == '0' || data->map.map[data->i][data->j] == 'N')
					draw_square(data->mlx, data->mlx_win, data->j * TILE_SIZE, data->i * TILE_SIZE, TILE_SIZE, 0xFFFFFF);
			if (data->map.map[data->i][data->j] == '1')
					draw_square(data->mlx, data->mlx_win, data->j * TILE_SIZE, data->i * TILE_SIZE, TILE_SIZE, 0x000000);
			data->j++;
		}
		data->i++;
	}
	draw_circle(data->mlx, data->mlx_win, data->map.player.x, data->map.player.y, data->map.player.radius, 0x00FF0000);
	draw_line(data->mlx, data->mlx_win,
					data->map.player.x,
					data->map.player.y,
					data->map.player.x + cos(data->map.player.facing_angle) * 40,
					data->map.player.y + sin(data->map.player.facing_angle) * 40,
					0x00FF0000);
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

int count_lines(char **lines)
{
    int count = 0;

    if (lines == NULL)
        return 0;

    while (lines[count] != NULL) {
        count++;
    }

    return count;
}

void	player_pos(t_map *map)
{
	int	i;
	int	j;

	i = 0;

	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				map->player.starting_pos = map->map[i][j];
				map->player.x = j * TILE_SIZE;
				map->player.y = i * TILE_SIZE;
			}
			j++;
		}
		i++;
	}
}

bool	check_first_last_line(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (map[j])
		j++;
	j = j - 1;
	while (map[0][i] == '1' || map[0][i] == ' ')
		i++;
	if (i == ft_strlen(map[0]))
	{
		i = 0;
		while (map[j][i] == '1' || map[j][i] == ' ')
			i++;
		if (i == ft_strlen(map[j]))
			return (true);
	}
	printf("map is not valid first or last\n");
	return (false);
}

void	check_map_close(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_first_last_line(map, data) == false)
	{
		printf("Error9\n");
		exit(1);
	}
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '0')// || map[j][i] == data->player_char)
			{
				if ((!map[j - 1][i] || map[j - 1][i] == ' ')
					|| (!map[j + 1][i] || map[j + 1][i] == ' ')
					|| (!map[j][i + 1] || map[j][i + 1] == ' ')
					|| (!map[j][i - 1] || map[j][i - 1] == ' '))
					{
						printf("map is not suround by one");
						exit(1);
					}
			}
			i++;
		}
		j++;
	}
}

void	count_rows_col(char **map, t_data *data)
{
	int i;
	int j;

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
	// data->map.row++;
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	write(2, "you left the game\n", ft_strlen("you left the game\n"));
	exit(EXIT_FAILURE);
	return (0);
}

int	keys_pressed(int keycode, t_data *data)
{
	if (keycode == 13 || keycode == 126)
	{
		printf("front\n");
		data->map.player.walk_orientation = 1;
	}
	if (keycode == 1 || keycode == 125)
	{
		printf("back\n");
		data->map.player.walk_orientation = -1;	
	}
	if (keycode == 0 || keycode == 123)
	{
		printf("left\n");
		data->map.player.turn_orientation = -1;
	}
	if (keycode == 2 || keycode == 124)
	{
		printf("right\n");
		data->map.player.turn_orientation = 1;
	}
	if (keycode == 53)
		ft_close(data);
	return (0);
}

int	keys_released(int keycode, t_data *data)
{
	if (keycode == 13 || keycode == 126)
		data->map.player.walk_orientation = 0;
	if (keycode == 1 || keycode == 125)
		data->map.player.walk_orientation = 0;
	if (keycode == 0 || keycode == 123)
		data->map.player.turn_orientation = 0;
	if (keycode == 2 || keycode == 124)
		data->map.player.turn_orientation = 0;
	return (0);
}

void	reseting_map(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->window_width, data->window_height);
	// data.img.addr = mlx_get_data_addr(data.img.img,
	// 		&data.img.bits_per_pixel, &data.img.line_length,
	// 		&data.img.endian);
}

bool	not_wall(t_data *data, double x, double y)
{
	int i;
	int j;

	i = y / TILE_SIZE;
	j = x / TILE_SIZE;
	if (data->map.map[i][j] == '1')
		return (false);
	return (true);
}

void walk_function(t_data *data)
{
    double move_step = data->map.player.walk_orientation * data->map.player.move_speed;
    double new_x = data->map.player.x + cos(data->map.player.facing_angle) * move_step;
    double new_y = data->map.player.y + sin(data->map.player.facing_angle) * move_step;

	if (not_wall(data, new_x, new_y) == true)
	{
		data->map.player.x = new_x;
		data->map.player.y = new_y;
	}
}

int	my_loop_hook(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	// reseting_map(data);
	data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->map.player.facing_angle += data->map.player.turn_orientation * data->map.player.turn_speed;
	if (data->map.player.walk_orientation != 0)
		walk_function(data);
	make_map(data);
	return (0);
}

void	check_empty_lines(t_map *map)
{
	int i = 0;
	while (map->map[i])
	{
		if (is_whitespace(map->map[i]))
		{
			printf("Error\n");
			exit(1);
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
	t_data data;

	data.av = argv;
	/* i need to initialize every thing with null */
	data.maps = NULL;
	parsing(argc, &data);
	player_pos(&data.map);
	check_map_close(data.map.map, &data);
	check_empty_lines(&data.map);
	int i = 0;
	// while (data.map.map[i])
	// {
	// 	if (is_whitespace(data.map.map[i]))
	// 	{
	// 		printf("Error\n");
	// 		exit(1);
	// 	}
	// 	i++;
	// }
	/* check if this function is used at the end*/
	count_rows_col(data.map.map, &data);
	printf("row = %d\n", data.map.row);
	printf("col = %d\n", data.map.col);
	/* initialization */
	/*** end of parsing here ***/
	
	/*intializing the palyer 3abat*/

	// the x and y ar in the player_pos() function
	// data.map.player.x = data.map.player.x;
	// data.map.player.y = data.map.player.y;

	data.map.player.radius = 4;
	data.map.player.turn_orientation = 0; // -1 left and +1 right
	data.map.player.walk_orientation = 0; // -1 back and +1 front
	data.map.player.facing_angle = M_PI / 2;
	data.map.player.move_speed = 6.0;
	data.map.player.turn_speed = 30 * (M_PI / 180);
	

	/*intializing the palyer 3abat done*/
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WINDOW_HEIGHT, WINDOW_WIDTH, "cube3d");
	// data.img = mlx_new_image(data.mlx, data.window_width, data.window_height);
	
	mlx_hook(data.mlx_win, 2, 0, keys_pressed, &data);
	mlx_hook(data.mlx_win, 3, 0, keys_released, &data);
	mlx_loop_hook(data.mlx, my_loop_hook, &data);
	mlx_loop(data.mlx);

	i = 0;
	while (data.map.map[i])
	{
		printf("%s\n", data.map.map[i]);
		i++;
	}
}