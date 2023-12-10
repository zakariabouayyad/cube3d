/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyassine <eyassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:27:14 by eyassine          #+#    #+#             */
/*   Updated: 2023/11/15 16:06:53 by eyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	wall_hitt_coordinate(t_data *data, double x, double y, int i)
{
	if (!data->flag)
	{
		data->rays[i].hitted_h = 1;
		if (!data->rays[i].facing_up_down)
			++y;
		data->rays[i].hor_wall_x_hit = x;
		data->rays[i].hor_wall_y_hit = y;
	}
	else
	{
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
		if (data->map.map2[(int)y / TILE_SIZE][(int)x / TILE_SIZE] == '1')
		{
			wall_hitt_coordinate(data, x, y, i);
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
