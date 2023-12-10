/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:27:44 by eyassine          #+#    #+#             */
/*   Updated: 2023/11/12 15:36:15 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	more_keys(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(1);
	}
	return (0);
}

int	keys(int keycode, t_data *data)
{
	if (keycode == 13 || keycode == 126)
		data->player.walk = 1;
	if (keycode == 1 || keycode == 125)
		data->player.walk = -1;
	if (keycode == 0)
		data->player.walk_side = -1;
	if (keycode == 2)
		data->player.walk_side = 1;
	if (keycode == 123)
		data->player.turn = -1;
	if (keycode == 124)
		data->player.turn = 1;
	more_keys(keycode, data);
	return (0);
}

int	released(int keycode, t_data *data)
{
	if (keycode == 13 || keycode == 126)
		data->player.walk = 0;
	if (keycode == 1 || keycode == 125)
		data->player.walk = 0;
	if (keycode == 0)
		data->player.walk_side = 0;
	if (keycode == 2)
		data->player.walk_side = 0;
	if (keycode == 123)
		data->player.turn = 0;
	if (keycode == 124)
		data->player.turn = 0;
	return (0);
}
