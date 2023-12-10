/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:27:34 by eyassine          #+#    #+#             */
/*   Updated: 2023/11/11 22:51:24 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_pixel(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
