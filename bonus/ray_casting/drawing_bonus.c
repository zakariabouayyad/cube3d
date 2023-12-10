/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyassine <eyassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:27:34 by eyassine          #+#    #+#             */
/*   Updated: 2023/11/12 11:55:12 by eyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	put_pixel(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_circle2(t_img img, int center_x, int center_y, int radius)
{
	int	y;
	int	x;
	int	dx;
	int	dy;

	y = center_y - radius;
	while (y <= center_y + radius)
	{
		x = center_x - radius;
		while (x <= center_x + radius)
		{
			dx = x - center_x;
			dy = y - center_y;
			if (dx * dx + dy * dy <= radius * radius)
			{
				put_pixel(img, x, y, 0xE5E4E2);
			}
			x++;
		}
		y++;
	}
}

void	dda_line(t_data *data, double x, double y)
{
	double	yy;
	double	xx;
	double	delta_x;
	double	delta_y;
	int		i;

	yy = sin(data->player.rot_angle) * 10;
	xx = cos(data->player.rot_angle) * 10;
	delta_x = (x + xx) - x;
	delta_y = (y + yy) - y;
	delta_x /= 10;
	delta_y /= 10;
	i = 0;
	while (i <= 10)
	{
		put_pixel(data->minimap, x, y, 0xE5E4E2);
		x += delta_x;
		y += delta_y;
		i++;
	}
}
