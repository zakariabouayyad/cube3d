/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hor_ver_cast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyassine <eyassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:26:08 by eyassine          #+#    #+#             */
/*   Updated: 2023/11/15 16:06:46 by eyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	hor_cast(t_data *data, int i)
{
	data->rays[i].y_intercept = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
	if (data->rays[i].facing_up_down)
		data->rays[i].y_intercept += TILE_SIZE;
	data->rays[i].x_intercept = data->player.x
		+ ((data->rays[i].y_intercept - data->player.y)
			/ tan(data->rays[i].ray_angle));
	data->rays[i].delta_y = TILE_SIZE;
	if (!data->rays[i].facing_up_down)
		data->rays[i].delta_y *= -1;
	data->rays[i].delta_x = TILE_SIZE / tan(data->rays[i].ray_angle);
	if (!data->rays[i].facing_right_left && data->rays[i].delta_x > 0)
		data->rays[i].delta_x *= -1;
	if (data->rays[i].facing_right_left && data->rays[i].delta_x < 0)
		data->rays[i].delta_x *= -1;
	check_if_wall(data, 0, i);
}

void	ver_cast(t_data *data, int i)
{
	data->rays[i].x_intercept = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
	if (data->rays[i].facing_right_left)
		data->rays[i].x_intercept += TILE_SIZE;
	data->rays[i].y_intercept = data->player.y 
		+ ((data->rays[i].x_intercept - data->player.x)
			* tan(data->rays[i].ray_angle));
	data->rays[i].delta_x = TILE_SIZE;
	if (!data->rays[i].facing_right_left)
		data->rays[i].delta_x *= -1;
	data->rays[i].delta_y = TILE_SIZE * tan(data->rays[i].ray_angle);
	if (!data->rays[i].facing_up_down && data->rays[i].delta_y > 0)
		data->rays[i].delta_y *= -1;
	if (data->rays[i].facing_up_down && data->rays[i].delta_y < 0)
		data->rays[i].delta_y *= -1;
	check_if_wall(data, 1, i);
}

void	one_ray(t_data *data, int i)
{
	if (data->rays[i].ray_angle > 0 && data->rays[i].ray_angle < M_PI)
		data->rays[i].facing_up_down = 1;
	else
		data->rays[i].facing_up_down = 0;
	if (data->rays[i].ray_angle < 0.5 * M_PI 
		|| data->rays[i].ray_angle > 1.5 * M_PI)
		data->rays[i].facing_right_left = 1;
	else
		data->rays[i].facing_right_left = 0;
	hor_cast(data, i);
	ver_cast(data, i);
}
