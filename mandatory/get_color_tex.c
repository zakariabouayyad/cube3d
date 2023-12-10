/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_tex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:42:21 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/11 22:35:44 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	north_color(t_data *data, int i, int color)
{
	color = *((int *)((data->north.addr) 
				+ ((int)(data->column[i].offset_y % data->north.height) 
					* data->north.line_length + (int) \
					(data->column[i].offset_x % data->north.width)
					* (data->north.bits_per_pixel / 8))));
	return (color);
}

int	south_color(t_data *data, int i, int color)
{
	color = *((int *)((data->south.addr) 
				+ ((int)(data->column[i].offset_y % data->south.height)
					* data->south.line_length + (int) \
					(data->column[i].offset_x % data->south.width) 
					* (data->south.bits_per_pixel / 8))));
	return (color);
}

int	west_color(t_data *data, int i, int color)
{
	color = *((int *)((data->west.addr)
				+ ((int)(data->column[i].offset_y % data->west.height)
					* data->west.line_length
					+ (int)(data->column[i].offset_x % data->west.width)
					* (data->west.bits_per_pixel / 8))));
	return (color);
}

int	ft_get_color(int i, t_data *data)
{
	int	color;

	color = 0;
	if (data->rays[i].is_horz && data->rays[i].is_up)
		color = north_color(data, i, color);
	else if (data->rays[i].is_horz && data->rays[i].is_down)
		color = south_color(data, i, color);
	else if (data->rays[i].is_vert && data->rays[i].is_left)
		color = west_color(data, i, color);
	else if (data->rays[i].is_vert && data->rays[i].is_right)
	{
		color = *((int *)((data->east.addr)
					+ ((int)(data->column[i].offset_y % data->east.height)
						* data->east.line_length
						+ (int)(data->column[i].offset_x % data->east.width)
						* (data->east.bits_per_pixel / 8))));
	}
	return (color);
}
