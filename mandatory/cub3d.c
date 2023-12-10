/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyassine <eyassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:27:19 by eyassine          #+#    #+#             */
/*   Updated: 2023/11/15 15:52:45 by eyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *error_msg)
{
	int	i;

	i = 0;
	if (!error_msg)
		return ;
	while (error_msg[i])
		write(2, &error_msg[i++], 1);
	exit(EXIT_FAILURE);
}

int	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map2[i])
	{
		free(data->map.map2[i]);
		i++;
	}
	free(data->map.map2);
	write(2, "you left the game\n", ft_strlen("you left the game\n"));
	exit(EXIT_FAILURE);
}

void	parsing(t_data *data, char **av)
{
	char	**six;
	char	**tmp;

	six = read_six(av[1]);
	six = remove_newline6(six);
	parse_tex_col(data, six);
	map_size(av[1], data);
	data->map.map = read_map(data, av[1]);
	tmp = remove_newline(data->map.map);
	data->map.map2 = fix_map(tmp, data);
	check_map_close(data->map.map2);
	check_chars(data->map.map2);
	player_pos(data);
	get_width_height(data->map.map2, data);
	free_double(tmp);
}

int	main(int ac, char *av[])
{
	t_data	data;

	data.av = av;
	if (ac != 2 || ft_check_name_map(av[1]))
		return (print_error("Error\n"), 1);
	parsing(&data, av);
	if (!init_data(&data))
		return (1);
	mlx_hook(data.mlx_win, 17, 0, ft_free, &data);
	mlx_hook(data.mlx_win, 2, 0, keys, &data);
	mlx_hook(data.mlx_win, 3, 0, released, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
