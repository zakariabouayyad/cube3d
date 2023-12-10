/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_animation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:23:37 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/11 21:58:36 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	first_person(t_data *data)
{
	double	a;

	a = FRAME / 8;
	data->frame++;
	if (data->frame >= 0 && data->frame < a)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gun1.img, 0, 0);
	if (data->frame >= a && data->frame < a * 2)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gun2.img, 0, 0);
	if (data->frame >= a * 2 && data->frame < a * 3)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gun3.img, 0, 0);
	if (data->frame >= a * 3 && data->frame < a * 4)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gun4.img, 0, 0);
	if (data->frame >= a * 4 && data->frame < a * 5)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gun5.img, 0, 0);
	if (data->frame >= a * 5 && data->frame < a * 6)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gun6.img, 0, 0);
	if (data->frame >= a * 6 && data->frame < a * 7)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gun7.img, 0, 0);
	if (data->frame >= a * 7 && data->frame < a * 8)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gun8.img, 0, 0);
}

void	more_reload_frames(t_data *data, double a)
{
	if (data->frame >= a * 8 && data->frame < a * 9)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->r_09.img, 0, 0);
	if (data->frame >= a * 9 && data->frame < a * 10)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->r_10.img, 0, 0);
	if (data->frame >= a * 10 && data->frame < a * 11)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->r_11.img, 0, 0);
	if (data->frame >= a * 11 && data->frame < a * 12)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->r_12.img, 0, 0);
	if (data->frame >= a * 12 && data->frame < a * 13)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->r_13.img, 0, 0);
	if (data->frame >= a * 13 && data->frame < a * 14)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->r_14.img, 0, 0);
}

void	reload_frames(t_data *data)
{
	double	a;

	a = FRAME / 14;
	data->frame++;
	if (data->frame >= 0 && data->frame < a)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->r_01.img, 0, 0);
	if (data->frame >= a && data->frame < a * 2)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->r_02.img, 0, 0);
	if (data->frame >= a * 2 && data->frame < a * 3)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->r_03.img, 0, 0);
	if (data->frame >= a * 3 && data->frame < a * 4)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->r_04.img, 0, 0);
	if (data->frame >= a * 4 && data->frame < a * 5)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->r_05.img, 0, 0);
	if (data->frame >= a * 5 && data->frame < a * 6)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->r_06.img, 0, 0);
	if (data->frame >= a * 6 && data->frame < a * 7)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->r_07.img, 0, 0);
	if (data->frame >= a * 7 && data->frame < a * 8)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->r_08.img, 0, 0);
	more_reload_frames(data, a);
}

void	rest_ammo_frames(t_data *data)
{
	if (data->ammo == 6)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->n_4.img, 33, 207);
	else if (data->ammo == 7)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->n_3.img, 33, 207);
	else if (data->ammo == 8)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->n_2.img, 33, 207);
	else if (data->ammo == 9)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->n_1.img, 33, 207);
	else if (data->ammo == 10)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->n_0.img, 33, 207);
}

void	ammo_reload(t_data *data)
{
	if (data->ammo > 10)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->n_0.img, 33, 207);
	if (data->ammo == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->n_10.img, 33, 207);
	else if (data->ammo == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->n_9.img, 33, 207);
	else if (data->ammo == 2)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->n_8.img, 33, 207);
	else if (data->ammo == 3)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->n_7.img, 33, 207);
	else if (data->ammo == 4)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->n_6.img, 33, 207);
	else if (data->ammo == 5)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->n_5.img, 33, 207);
	else
		rest_ammo_frames(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->bullet.img, 0, 205);
}
