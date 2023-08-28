/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:43:18 by zbouayya          #+#    #+#             */
/*   Updated: 2023/08/28 15:15:44 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


void draw_square(void *mlx, void *win, int x, int y, int size, int color)
{
    int end_x = x + size;
    int end_y = y + size;

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

void	make_map(t_data	*data)
{
	data->i = 0;
	while (data->map.map[data->i])
	{	
	// data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		data->j = 0;
		while (data->map.map[data->i][data->j])
		{
			if (data->map.map[data->i][data->j] == '0')
					draw_square(data->mlx, data->mlx_win, data->j * TILE_SIZE, data->i * TILE_SIZE, TILE_SIZE, 0xFFFFFF);
			if (data->map.map[data->i][data->j] == '1')
					draw_square(data->mlx, data->mlx_win, data->j * TILE_SIZE, data->i * TILE_SIZE, TILE_SIZE, 0x000000);
			// if (data->map.map[data->i][data->j] == 'C')
			// 	mlx_put_image_to_window(data->mlx, data->mlx_win, data-> \
			// 	mlx_babysus, data->j * data->img_w, data->i * data->img_h);
			// if (data->map.map[data->i][data->j] == 'E')
			// 	mlx_put_image_to_window(data->mlx, data->mlx_win, \
			// 	data->mlx_exit, data->j * data->img_w, data->i * data->img_h);
			// put_player(data);
			data->j++;
		}
		data->i++;
	}
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
				map->player.x = i;
				map->player.y = j;
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
// bool	first_last(void)
// {
// 	int	i;
// 	int	e;

// 	i = -1;
// 	while (g_data.pars.map[0][++i])
// 	{
// 		if (g_data.pars.map[0][i] == '0'
// 			|| g_data.pars.map[0][i] == g_data.pars.pos)
// 			return (false);
// 	}
// 	e = map_len() - 1;
// 	i = -1;
// 	while (g_data.pars.map[e][++i])
// 	{
// 		if (g_data.pars.map[e][i] == '0'
// 			|| g_data.pars.map[e][i] == g_data.pars.pos)
// 			return (false);
// 	}
// 	return (true);
// }

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

int main(int argc, char *argv[])
{
	t_data data;

	data.av = argv;
	/* i need to initialize every thing with null */
	data.maps = NULL;
	parsing(argc, &data);
	player_pos(&data.map);
	check_map_close(data.map.map, &data);
	int i = 0;
	while (data.map.map[i])
	{
		if (is_whitespace(data.map.map[i]))
		{
			printf("Error\n");
			exit(1);
		}
		i++;
	}
	// data.mlx = mlx_init();
	// if (data.mlx == NULL)
	// 	exit(EXIT_FAILURE);
	// data.mlx_win = mlx_new_window(data.mlx, WINDOW_HEIGHT, WINDOW_WIDTH, "cube3d");
	// if (data.mlx_win == NULL)
	// 	exit(EXIT_FAILURE);
	// data.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	// make_map(&data);
	// mlx_loop(data.mlx);

	i = 0;
	while (data.map.map[i])
	{
		printf("%s\n", data.map.map[i]);
		i++;
	}
}