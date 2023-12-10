/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:09:45 by zbouayya          #+#    #+#             */
/*   Updated: 2023/11/11 21:58:11 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (!s)
	{
		return (NULL);
	}
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)(&s[i]));
		}
		i--;
	}
	return (NULL);
}
