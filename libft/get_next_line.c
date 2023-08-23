/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:46:09 by zbouayya          #+#    #+#             */
/*   Updated: 2023/03/02 22:08:06 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

char	*fd_reader(int fd, char *buffer, char *hold)
{
	int	x;

	x = 1;
	while (x > 0 && !ft_strchr_line(hold, '\n'))
	{
		x = read(fd, buffer, BUFFER_SIZE);
		if (x < 0)
		{
			free(buffer);
			free(hold);
			return (NULL);
		}
		buffer[x] = '\0';
		hold = ft_strjoin_line(hold, buffer);
	}
	free(buffer);
	if (hold[0] == '\0')
		return (free(hold), NULL);
	return (hold);
}

char	*ft_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_substr_line(str, 0, i + 1);
	return (line);
}

char	*ft_rmline(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!str)
		return (free(str), NULL);
	while (str[i] && str[i] != '\n')
		i++;
	tmp = ft_substr_line(str, i + 1, ft_strlen_line(str) - i);
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	hold = fd_reader(fd, buffer, hold);
	line = ft_line(hold);
	hold = ft_rmline(hold);
	return (line);
}
