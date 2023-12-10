/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyassine <eyassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:27:37 by eyassine          #+#    #+#             */
/*   Updated: 2023/11/15 15:57:30 by eyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_ray(t_data *data, int i)
{
	data->rays[i].column = 0;
	data->rays[i].delta_x = 0;
	data->rays[i].delta_y = 0;
	data->rays[i].distance = 0;
	data->rays[i].facing_right_left = -1;
	data->rays[i].facing_up_down = -1;
	data->rays[i].hor_wall_x_hit = 0;
	data->rays[i].hor_wall_y_hit = 0;
	data->rays[i].x_intercept = 0;
	data->rays[i].y_intercept = 0;
	data->rays[i].ver_wall_x_hit = 0;
	data->rays[i].ver_wall_y_hit = 0;
	data->rays[i].hitted_door = 0;
	data->rays[i].hitted_door_h = 0;
	data->rays[i].hitted_door_v = 0;
	data->rays[i].hitted_v = 0;
	data->rays[i].hitted_h = 0;
}

void	cast_rays(t_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		data->rays[i].is_horz = false;
		data->rays[i].is_vert = false;
		init_ray(data, i);
		if (i == 0)
			data->rays[i].ray_angle = data->player.rot_angle - (data->fov / 2);
		else
			data->rays[i].ray_angle = data->rays[i - 1].ray_angle
				+ (data->fov / NUM_RAYS);
		data->rays[i].ray_angle = fix_angle(data->rays[i].ray_angle);
		one_ray(data, i);
		check_distance(data, i);
		direction(data, i);
		i++;
	}
}

bool	check_for_wall(t_data *data, double x, double y, int radius)
{
	int	i;
	int	j;

	i = x - radius;
	while (i <= x + radius)
	{
		j = y - radius;
		while (j <= y + radius)
		{
			if (data->map.map2[(int)(j / TILE_SIZE)]
				[(int)(i / TILE_SIZE)] == '1')
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

void	walk_function(t_data *data)
{
	double	forward_x;
	double	forward_y;
	double	sideways_x;
	double	sideways_y;

	forward_x = cos(data->player.rot_angle) 
		* data->player.walk * data->player.move_speed;
	forward_y = sin(data->player.rot_angle) 
		* data->player.walk * data->player.move_speed;
	sideways_x = cos(data->player.rot_angle + (M_PI / 2))
		* data->player.walk_side * data->player.move_speed;
	sideways_y = sin(data->player.rot_angle + (M_PI / 2)) 
		* data->player.walk_side * data->player.move_speed;
	if (check_for_wall(data, 
			data->player.x + forward_x + sideways_x,
			data->player.y + forward_y + sideways_y,
			3) == false)
	{
		data->player.x = data->player.x + forward_x + sideways_x;
		data->player.y = data->player.y + forward_y + sideways_y;
	}
}

int	game_loop(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	data->player.rot_angle += data->player.turn * data->player.rot_speed;
	data->player.rot_angle = fix_angle(data->player.rot_angle);
	if (data->player.turn != 0 && data->mouse_in)
		data->player.turn = 0;
	data->mouse_in = 0;
	if (data->player.walk || data->player.walk_side || data->player.turn)
		walk_function(data);
	cast_rays(data);
	project_walls(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->game.img, 0, 0);
	return (0);
}
