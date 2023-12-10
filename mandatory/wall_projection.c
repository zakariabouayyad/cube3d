/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:23:34 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/11 22:29:48 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vert_x_offset(t_data *data, int i)
{
	if (data->rays[i].is_left)
	{
		data->column[i].offset_x = (data->rays[i].final_y_hit / TILE_SIZE
				- (int)(data->rays[i].final_y_hit) / TILE_SIZE)
			* data->west.width;
	}
	else if (data->rays[i].is_right)
	{
		data->column[i].offset_x = (data->rays[i].final_y_hit / TILE_SIZE
				- (int)(data->rays[i].final_y_hit) / TILE_SIZE)
			* data->east.width;
	}
}

void	get_x_offset(t_data *data, int i)
{
	if (data->rays[i].is_horz && data->rays[i].is_up)
	{
		data->column[i].offset_x = (data->rays[i].final_x_hit / TILE_SIZE 
				- (int)(data->rays[i].final_x_hit) / TILE_SIZE)
			* data->north.width;
	}
	else if (data->rays[i].is_horz && data->rays[i].is_down)
	{
		data->column[i].offset_x = (data->rays[i].final_x_hit / TILE_SIZE
				- (int)(data->rays[i].final_x_hit) / TILE_SIZE)
			* data->south.width;
	}
	else if (data->rays[i].is_vert)
		vert_x_offset(data, i);
}

void	get_wall_top_n_bottom(t_data *data, int i)
{
	data->column[i].ray_distance_fixed = data->rays[i].distance 
		* cos(data->rays[i].ray_angle - data->player.rot_angle);
	data->column[i].projection_plane = (WINDOW_WIDTH / 2) 
		/ tan(data->fov / 2);
	if (data->column[i].ray_distance_fixed == 0)
		data->column[i].ray_distance_fixed = data->rays[i].distance;
	data->column[i].w_strip_height = (TILE_SIZE 
			/ data->column[i].ray_distance_fixed) 
		* data->column[i].projection_plane;
	data->column[i].wall_top = (WINDOW_HEIGHT / 2) 
		- (data->column[i].w_strip_height / 2);
	if (data->column[i].wall_top < 0)
		data->column[i].wall_top = 0;
	data->column[i].wall_bottom = (WINDOW_HEIGHT / 2) 
		+ (data->column[i].w_strip_height / 2);
	if (data->column[i].wall_bottom > WINDOW_HEIGHT)
		data->column[i].wall_bottom = WINDOW_HEIGHT;
}

void	project_walls(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < NUM_RAYS)
	{
		get_wall_top_n_bottom(data, i);
		y = -1;
		while (++y < data->column[i].wall_top)
			put_pixel(data->game, (i * W_STRIP_WIDTH), y, data->ceiling_color);
		get_x_offset(data, i);
		y = data->column[i].wall_top;
		while (y < data->column[i].wall_bottom)
		{
			get_y_offset(data, i, y);
			put_pixel(data->game, (i * W_STRIP_WIDTH), 
				y, ft_get_color(i, data));
			y++;
		}
		y = data->column[i].wall_bottom - 1;
		while (++y < WINDOW_HEIGHT)
			put_pixel(data->game, (i * W_STRIP_WIDTH), y, data->flor_color);
		i++;
	}
}
