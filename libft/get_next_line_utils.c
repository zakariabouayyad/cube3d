/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouayya <zbouayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:46:00 by zbouayya          #+#    #+#             */
/*   Updated: 2023/03/02 22:08:56 by zbouayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

size_t	ft_strlen_line(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr_line(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (len >= ft_strlen_line(s))
		len = ft_strlen_line(s);
	sub = (char *)malloc(sizeof(*s) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = '\0';
	return (sub);
}

char	*ft_strjoin_line(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_substr_line(s2, 0, ft_strlen_line(s2)));
	if (!s2)
		return (ft_substr_line(s1, 0, ft_strlen_line(s1)));
	s3 = (char *)malloc(ft_strlen_line(s1) + ft_strlen_line(s2) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	// free(s1);
	return (s3);
}

char	*ft_strchr_line(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			return ((char *)(&str[i]));
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)(&str[i]));
	}
	return (0);
}
