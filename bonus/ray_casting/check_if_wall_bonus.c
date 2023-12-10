/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_wall_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:27:14 by eyassine          #+#    #+#             */
/*   Updated: 2023/11/11 21:58:11 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_door(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	x /= TILE_SIZE;
	y /= TILE_SIZE;
	while (i < data->doors_nbr)
	{
		if (x * TILE_SIZE == data->doors[i].x
			&& y * TILE_SIZE == data->doors[i].y 
			&& data->doors[i].distance < 70)
			return (0);
		i++;
	}
	return (1);
}

void	wall_hitt_coordinate(t_data *data, double x, double y, int i)
{
	if (!data->flag)
	{
		if (data->map.map2[(int)y / TILE_SIZE][(int)x / TILE_SIZE] == 'D')
			data->rays[i].hitted_door_h = 1;
		data->rays[i].hitted_h = 1;
		if (!data->rays[i].facing_up_down)
			++y;
		data->rays[i].hor_wall_x_hit = x;
		data->rays[i].hor_wall_y_hit = y;
	}
	else
	{
		if (data->map.map2[(int)y / TILE_SIZE][(int)x / TILE_SIZE] == 'D')
			data->rays[i].hitted_door_v = 1;
		data->rays[i].hitted_v = 1;
		if (!data->rays[i].facing_right_left)
			++x;
		data->rays[i].ver_wall_x_hit = x;
		data->rays[i].ver_wall_y_hit = y;
	}
}

void	get_hit_coord(t_data *data, double x, double y, int i)
{
	while (x >= 0 && x < data->map_width
		&& y >= 0 && y < data->map_height)
	{
		if (data->map.map2[(int)y / TILE_SIZE][(int)x / TILE_SIZE] == '1'
		|| ((data->map.map2[(int)y / TILE_SIZE][(int)x / TILE_SIZE] == 'D'
		&& !data->door_open)))
		{
			if (check_door(data, x, y))
			{
				wall_hitt_coordinate(data, x, y, i);
				data->door_open = 0;
			}
			else
			{
				data->door_open = 1;
				continue ;
			}
			return ;
		}
		x += data->rays[i].delta_x;
		y += data->rays[i].delta_y;
	}
}

void	check_if_wall(t_data *data, int flag, int i)
{
	double	y;
	double	x;

	y = data->rays[i].y_intercept;
	x = data->rays[i].x_intercept;
	data->flag = flag;
	if (!data->rays[i].facing_up_down && !data->flag)
		y--;
	if (!data->rays[i].facing_right_left && data->flag)
		x--;
	get_hit_coord(data, x, y, i);
}
