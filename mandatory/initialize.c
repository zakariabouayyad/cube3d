/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:38:13 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/12 10:09:06 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*my_xpm_to_img(void *mlx_ptr, char *filename, int *width, int *height)
{
	void	*xpm;

	xpm = mlx_xpm_file_to_image(mlx_ptr, filename, width, height);
	if (xpm == NULL)
		print_error("Error\n");
	return (xpm);
}

void	init_texture(t_data *data)
{
	data->north.img = my_xpm_to_img(data->mlx, data->map.north_texture, 
			&data->north.width, &data->north.height);
	data->north.addr = mlx_get_data_addr(data->north.img,
			&data->north.bits_per_pixel, &data->north.line_length,
			&data->north.endian);
	data->south.img = my_xpm_to_img(data->mlx, data->map.south_texture,
			&data->south.width, &data->south.height);
	data->south.addr = mlx_get_data_addr(data->south.img,
			&data->south.bits_per_pixel, &data->south.line_length,
			&data->south.endian);
	data->west.img = my_xpm_to_img(data->mlx, data->map.west_texture,
			&data->west.width, &data->west.height);
	data->west.addr = mlx_get_data_addr(data->west.img,
			&data->west.bits_per_pixel, &data->west.line_length,
			&data->west.endian);
	data->east.img = my_xpm_to_img(data->mlx, data->map.east_texture,
			&data->east.width, &data->east.height);
	data->east.addr = mlx_get_data_addr(data->east.img,
			&data->east.bits_per_pixel, &data->east.line_length,
			&data->east.endian);
}
