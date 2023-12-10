/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_game_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:58:13 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/11 22:52:09 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	get_char(t_data *data, double x, double y)
{
	if (x < 0 || x >= data->map_width
		|| y < 0 || y >= data->map_height)
		return ('2');
	x = floor(x / TILE_SIZE);
	y = floor(y / TILE_SIZE);
	return (data->map.map2[(int)y][(int)x]);
}
