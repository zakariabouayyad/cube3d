/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyassine <eyassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:48:08 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/15 15:57:45 by eyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	is_facing_down(double angle)
{
	if (angle >= 0 && angle <= M_PI)
		return (true);
	return (false);
}

bool	is_facing_right(double angle)
{
	if (angle <= M_PI_2 || angle >= (3 * M_PI_2))
		return (true);
	return (false);
}

void	direction(t_data *data, int i)
{
	data->rays[i].is_down = false;
	data->rays[i].is_up = false;
	data->rays[i].is_left = false;
	data->rays[i].is_right = false;
	if (is_facing_down(data->rays[i].ray_angle))
		data->rays[i].is_down = true;
	else
		data->rays[i].is_up = true;
	if (is_facing_right(data->rays[i].ray_angle))
		data->rays[i].is_right = true;
	else
		data->rays[i].is_left = true;
}

double	fix_angle(double ray_angle)
{
	ray_angle = fmod(ray_angle, 2 * M_PI);
	if (ray_angle < 0)
		ray_angle = ray_angle + (2 * M_PI);
	return (ray_angle);
}
