/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyassine <eyassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:27:21 by eyassine          #+#    #+#             */
/*   Updated: 2023/11/15 16:08:44 by eyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	init_player(t_data *data)
{
	data->player.radius = 7;
	data->player.rot_speed = 5.0 * (M_PI / 180);
	data->player.move_speed = 4.0;
	if (data->player.starting_pos == 'N')
		data->player.rot_angle = 3 * M_PI / 2;
	else if (data->player.starting_pos == 'S')
		data->player.rot_angle = M_PI / 2;
	else if (data->player.starting_pos == 'W')
		data->player.rot_angle = M_PI;
	else if (data->player.starting_pos == 'E')
		data->player.rot_angle = 0.0;
	data->player.walk = 0;
	data->player.walk_side = 0;
	data->player.turn = 0;
}

int	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		print_error("Error\nmlx\n");
	data->mlx_win = mlx_new_window(data->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "cub3D");
	if (!data->mlx_win)
		print_error("Error\nmlx\n");
	data->minimap.img = mlx_new_image(data->mlx, MINIMAP_WIDTH, MINIMAP_WIDTH);
	data->minimap.addr = mlx_get_data_addr(data->minimap.img,
			&data->minimap.bits_per_pixel, &data->minimap.line_length,
			&data->minimap.endian);
	data->game.img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->game.addr = mlx_get_data_addr(data->game.img,
			&data->game.bits_per_pixel, &data->game.line_length,
			&data->game.endian);
	init_player(data);
	data->rays = malloc(sizeof(t_ray) * NUM_RAYS);
	if (!data->rays)
		print_error("Error\nmlx\n");
	data->column = (t_column *)malloc(sizeof(t_column) * NUM_RAYS);
	if (!data->column)
		print_error("Error\nmlx\n");
	init_texture(data);
	return (data->door_open = 0, 1);
}
