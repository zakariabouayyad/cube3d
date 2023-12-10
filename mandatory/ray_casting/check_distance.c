/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_distance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:27:30 by eyassine          #+#    #+#             */
/*   Updated: 2023/11/11 22:51:46 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	calculate_distance(double x, double y, double xf, double yf)
{
	return (sqrt((xf - x) * (xf - x) + (yf - y) * (yf - y)));
}

void	compare_distance(t_data *data, double hor_distance,
double ver_distance, int i)
{
	if (hor_distance < ver_distance)
	{
		if (data->rays[i].hitted_door_v)
			data->rays[i].hitted_door_v = 0;
		data->rays[i].is_horz = true;
		data->rays[i].final_x_hit = data->rays[i].hor_wall_x_hit;
		data->rays[i].final_y_hit = data->rays[i].hor_wall_y_hit;
		data->rays[i].distance = hor_distance;
	}
	else
	{
		if (data->rays[i].hitted_door_h)
			data->rays[i].hitted_door_h = 0;
		data->rays[i].is_vert = true;
		data->rays[i].final_x_hit = data->rays[i].ver_wall_x_hit;
		data->rays[i].final_y_hit = data->rays[i].ver_wall_y_hit;
		data->rays[i].distance = ver_distance;
	}
}

void	check_distance(t_data *data, int i)
{
	double	hor_distance;
	double	ver_distance;

	hor_distance = 0;
	ver_distance = 0;
	if (!data->rays[i].hitted_h)
		hor_distance = 9999.99;
	else
		hor_distance = calculate_distance(data->player.x, data->player.y,
				data->rays[i].hor_wall_x_hit, data->rays[i].hor_wall_y_hit);
	if (!data->rays[i].hitted_v)
		ver_distance = 9999.99;
	else
		ver_distance = calculate_distance(data->player.x, data->player.y,
				data->rays[i].ver_wall_x_hit, data->rays[i].ver_wall_y_hit);
	compare_distance(data, hor_distance, ver_distance, i);
}
