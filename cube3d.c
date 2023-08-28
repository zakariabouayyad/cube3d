/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:43:18 by zbouayya          #+#    #+#             */
/*   Updated: 2023/08/28 07:59:24 by zbouayya         ###   ########.fr       */
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

int main(int argc, char *argv[])
{
	t_data data;

	data.av = argv;
	/* i need to initialize every thing with null */
	data.maps = NULL;
	parsing(argc, &data);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		exit(EXIT_FAILURE);
	data.mlx_win = mlx_new_window(data.mlx, WINDOW_HEIGHT, WINDOW_WIDTH, "cube3d");
	if (data.mlx_win == NULL)
		exit(EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	make_map(&data);
	mlx_loop(data.mlx);

	// int i = 0;
	// while (data.map.map[i])
	// {
	// 	printf("%s\n", data.map.map[i]);
	// 	i++;
	// }
}