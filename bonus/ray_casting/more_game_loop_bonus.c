/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_game_loop_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:58:13 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/11 22:46:18 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_player(t_data *data)
{
	draw_circle2(data->minimap,
		(MINIMAP_WIDTH / 2),
		(MINIMAP_WIDTH / 2),
		data->player.radius / 2);
	dda_line(data,
		(MINIMAP_WIDTH / 2),
		(MINIMAP_WIDTH / 2));
}

char	get_char(t_data *data, double x, double y)
{
	if (x < 0 || x >= data->map_width
		|| y < 0 || y >= data->map_height)
		return ('2');
	x = floor(x / TILE_SIZE);
	y = floor(y / TILE_SIZE);
	return (data->map.map2[(int)y][(int)x]);
}

int	get_element_color(t_data *data, double pos_x, double pos_y)
{
	int		color;
	char	element;

	element = get_char(data, pos_x, pos_y);
	if (element == '1')
		color = 0x3D3C3A;
	else if (element == 'D')
		color = 0x625D5D;
	else if (element == '0' || element == data->player.starting_pos)
		color = 0x8C8C8C;
	else
		color = 0x000000;
	return (color);
}

void	make_minimap(t_data *data)
{
	double	x_start;
	double	y_start;
	int		x;
	int		y;

	x = 0;
	x_start = data->player.x - (MINIMAP_WIDTH / 2);
	y_start = data->player.y - (MINIMAP_WIDTH / 2);
	while (x < MINIMAP_WIDTH)
	{
		y = 0;
		while (y < MINIMAP_WIDTH)
		{
			put_pixel(data->minimap, x, y, 
				get_element_color(data, x_start + x, y_start + y));
			y++;
		}
		x++;
	}
	draw_player(data);
}

void	render_sprites(t_data *data)
{
	if (data->frame == FRAME)
	{
		data->frame = 0;
		data->animate = 0;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->game.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->minimap.img, 0, 0);
	if (data->ammo <= 10 && data->animate == 1)
	{
		first_person(data);
	}
	else if (data->animate == 2)
	{
		reload_frames(data);
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gun8.img, 0, 0);
	}
	ammo_reload(data);
}
