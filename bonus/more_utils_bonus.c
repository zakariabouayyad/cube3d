/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:35:51 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/12 10:10:14 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	my_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' 
		|| c == '\r' || c == '\f' || c == '\v');
}

void	*my_xpm_to_img(void *mlx_ptr, char *filename, int *width, int *height)
{
	void	*xpm;

	xpm = mlx_xpm_file_to_image(mlx_ptr, filename, width, height);
	if (xpm == NULL)
		print_error("Error\n");
	return (xpm);
}
