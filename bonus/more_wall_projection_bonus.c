/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_wall_projection_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:17:49 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/11 21:58:36 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	north_y_offset(t_data *data, int i, int y)
{
	if (data->rays[i].hitted_door_h)
	{
		data->column[i].distance_from_top = y 
			+ (data->column[i].w_strip_height / 2) - (WINDOW_HEIGHT / 2);
		data->column[i].offset_y = (data->column[i].distance_from_top)
			* ((double)data->door.height / data->column[i].w_strip_height);
	}
	else
	{
		data->column[i].distance_from_top = y 
			+ (data->column[i].w_strip_height / 2) - (WINDOW_HEIGHT / 2);
		data->column[i].offset_y = (data->column[i].distance_from_top)
			* ((double)data->north.height / data->column[i].w_strip_height);
	}
}

void	south_y_offset(t_data *data, int i, int y)
{
	if (data->rays[i].hitted_door_h)
	{
		data->column[i].distance_from_top = y 
			+ (data->column[i].w_strip_height / 2) - (WINDOW_HEIGHT / 2);
		data->column[i].offset_y = (data->column[i].distance_from_top)
			* ((double)data->door.height / data->column[i].w_strip_height);
	}
	else
	{
		data->column[i].distance_from_top = y
			+ (data->column[i].w_strip_height / 2) - (WINDOW_HEIGHT / 2);
		data->column[i].offset_y = (data->column[i].distance_from_top)
			* ((double)data->south.height / data->column[i].w_strip_height);
	}
}

void	west_y_offset(t_data *data, int i, int y)
{
	if (data->rays[i].hitted_door_v)
	{
		data->column[i].distance_from_top = y 
			+ (data->column[i].w_strip_height / 2) - (WINDOW_HEIGHT / 2);
		data->column[i].offset_y = (data->column[i].distance_from_top)
			* ((double)data->door.height / data->column[i].w_strip_height);
	}
	else
	{
		data->column[i].distance_from_top = y
			+ (data->column[i].w_strip_height / 2) - (WINDOW_HEIGHT / 2);
		data->column[i].offset_y = (data->column[i].distance_from_top)
			* ((double)data->west.height / data->column[i].w_strip_height);
	}
}

void	get_y_offset(t_data *data, int i, int y)
{
	if (data->rays[i].is_horz && data->rays[i].is_up)
		north_y_offset(data, i, y);
	else if (data->rays[i].is_horz && data->rays[i].is_down)
		south_y_offset(data, i, y);
	else if (data->rays[i].is_vert && data->rays[i].is_left)
		west_y_offset(data, i, y);
	else if (data->rays[i].is_vert && data->rays[i].is_right)
	{
		if (data->rays[i].hitted_door_v)
		{
			data->column[i].distance_from_top = y 
				+ (data->column[i].w_strip_height / 2) - (WINDOW_HEIGHT / 2);
			data->column[i].offset_y = (data->column[i].distance_from_top)
				* ((double)data->door.height / data->column[i].w_strip_height);
		}
		else
		{
			data->column[i].distance_from_top = y
				+ (data->column[i].w_strip_height / 2) - (WINDOW_HEIGHT / 2);
			data->column[i].offset_y = (data->column[i].distance_from_top)
				* ((double)data->east.height / data->column[i].w_strip_height);
		}
	}
}
