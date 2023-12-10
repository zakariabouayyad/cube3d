/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:38:13 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/15 09:59:23 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	initialize_wall_tex(t_data *data)
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
	data->door.img = my_xpm_to_img(data->mlx, "./bonus/texture/test1.xpm",
			&data->door.width, &data->door.height);
	data->door.addr = mlx_get_data_addr(data->door.img,
			&data->door.bits_per_pixel, &data->door.line_length,
			&data->door.endian);
}

void	initialize_gunshot(t_data *data)
{
	data->gun1.img = my_xpm_to_img(data->mlx, "./bonus/texture/g01.xpm",
			&data->gun1.width, &data->gun1.height);
	data->gun2.img = my_xpm_to_img(data->mlx, "./bonus/texture/g02.xpm",
			&data->gun2.width, &data->gun2.height);
	data->gun3.img = my_xpm_to_img(data->mlx, "./bonus/texture/g03.xpm",
			&data->gun3.width, &data->gun3.height);
	data->gun4.img = my_xpm_to_img(data->mlx, "./bonus/texture/g04.xpm",
			&data->gun4.width, &data->gun4.height);
	data->gun5.img = my_xpm_to_img(data->mlx, "./bonus/texture/g05.xpm",
			&data->gun5.width, &data->gun5.height);
	data->gun6.img = my_xpm_to_img(data->mlx, "./bonus/texture/g06.xpm",
			&data->gun6.width, &data->gun6.height);
	data->gun7.img = my_xpm_to_img(data->mlx, "./bonus/texture/g07.xpm",
			&data->gun7.width, &data->gun7.height);
	data->gun8.img = my_xpm_to_img(data->mlx, "./bonus/texture/g08.xpm",
			&data->gun8.width, &data->gun8.height);
}

void	initialize_ammo(t_data *data)
{
	data->n_0.img = my_xpm_to_img(data->mlx, "./bonus/texture/0.xpm",
			&data->n_0.width, &data->n_0.height);
	data->n_1.img = my_xpm_to_img(data->mlx, "./bonus/texture/1.xpm",
			&data->n_1.width, &data->n_1.height);
	data->n_2.img = my_xpm_to_img(data->mlx, "./bonus/texture/2.xpm",
			&data->n_2.width, &data->n_2.height);
	data->n_3.img = my_xpm_to_img(data->mlx, "./bonus/texture/3.xpm",
			&data->n_3.width, &data->n_3.height);
	data->n_4.img = my_xpm_to_img(data->mlx, "./bonus/texture/4.xpm",
			&data->n_4.width, &data->n_4.height);
	data->n_5.img = my_xpm_to_img(data->mlx, "./bonus/texture/5.xpm",
			&data->n_5.width, &data->n_5.height);
	data->n_6.img = my_xpm_to_img(data->mlx, "./bonus/texture/6.xpm",
			&data->n_6.width, &data->n_6.height);
	data->n_7.img = my_xpm_to_img(data->mlx, "./bonus/texture/7.xpm",
			&data->n_7.width, &data->n_7.height);
	data->n_8.img = my_xpm_to_img(data->mlx, "./bonus/texture/8.xpm",
			&data->n_8.width, &data->n_8.height);
	data->n_9.img = my_xpm_to_img(data->mlx, "./bonus/texture/9.xpm",
			&data->n_9.width, &data->n_9.height);
	data->n_10.img = my_xpm_to_img(data->mlx, "./bonus/texture/10.xpm",
			&data->n_10.width, &data->n_10.height);
	data->bullet.img = my_xpm_to_img(data->mlx, "./bonus/texture/b.xpm",
			&data->bullet.width, &data->bullet.height);
}

void	initialize_reload(t_data *data)
{
	data->r_01.img = my_xpm_to_img(data->mlx, "./bonus/texture/r01.xpm",
			&data->r_01.width, &data->r_01.height);
	data->r_02.img = my_xpm_to_img(data->mlx, "./bonus/texture/r02.xpm",
			&data->r_02.width, &data->r_02.height);
	data->r_03.img = my_xpm_to_img(data->mlx, "./bonus/texture/r03.xpm",
			&data->r_03.width, &data->r_03.height);
	data->r_04.img = my_xpm_to_img(data->mlx, "./bonus/texture/r04.xpm",
			&data->r_04.width, &data->r_04.height);
	data->r_05.img = my_xpm_to_img(data->mlx, "./bonus/texture/r05.xpm",
			&data->r_05.width, &data->r_05.height);
	data->r_06.img = my_xpm_to_img(data->mlx, "./bonus/texture/r06.xpm",
			&data->r_06.width, &data->r_06.height);
	data->r_07.img = my_xpm_to_img(data->mlx, "./bonus/texture/r07.xpm",
			&data->r_07.width, &data->r_07.height);
	data->r_08.img = my_xpm_to_img(data->mlx, "./bonus/texture/r08.xpm",
			&data->r_08.width, &data->r_08.height);
	data->r_09.img = my_xpm_to_img(data->mlx, "./bonus/texture/r09.xpm",
			&data->r_09.width, &data->r_09.height);
	data->r_10.img = my_xpm_to_img(data->mlx, "./bonus/texture/r10.xpm",
			&data->r_10.width, &data->r_10.height);
	data->r_11.img = my_xpm_to_img(data->mlx, "./bonus/texture/r11.xpm",
			&data->r_11.width, &data->r_11.height);
	data->r_12.img = my_xpm_to_img(data->mlx, "./bonus/texture/r12.xpm",
			&data->r_12.width, &data->r_12.height);
}

void	init_texture(t_data *data)
{
	initialize_wall_tex(data);
	initialize_gunshot(data);
	initialize_ammo(data);
	initialize_reload(data);
	data->r_13.img = my_xpm_to_img(data->mlx, "./bonus/texture/r13.xpm",
			&data->r_13.width, &data->r_13.height);
	data->r_14.img = my_xpm_to_img(data->mlx, "./bonus/texture/r14.xpm",
			&data->r_14.width, &data->r_14.height);
	data->ammo = 0;
	data->ammo_out = true;
	data->fov = 60 * (M_PI / 180);
	data->frame = 0;
}
