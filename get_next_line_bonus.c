/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:21:40 by rnaamaou          #+#    #+#             */
/*   Updated: 2021/12/28 16:22:00 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_get_line(int fd, char **line)
{
	int		bytes;
	char	*buff;

	if (*line == NULL)
		*line = ft_strdup("");
	buff = (char *)malloc (BUFFER_SIZE + 1);
	if (!buff)
		return ;
	bytes = 1;
	while (bytes && !ft_strchr(*line, '\n'))
	{
		bytes = read (fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buff);
			free (*line);
			*line = NULL;
			return ;
		}
		buff [bytes] = '\0';
		*line = ft_strjoin (*line, buff);
	}
	free (buff);
	return ;
}

static char	*ft_split_line(char **line)
{
	char	*buff;
	char	*tmp;
	int		i;

	i = 0;
	if (!ft_strchr(*line, '\n'))
	{
		tmp = ft_strdup (*line);
		free (*line);
		*line = NULL;
		return (tmp);
	}
	tmp = ft_substr(*line, 0, ft_strchr (*line, '\n') - *line + 1);
	buff = ft_strdup (ft_strchr (*line, '\n') + 1);
	free (*line);
	*line = buff;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*rest[1024];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_get_line(fd, &rest[fd]);
	if (rest[fd] && rest[fd][0] != 0)
		line = ft_split_line(&rest[fd]);
	if (rest[fd] && rest[fd][0] == 0)
	{
		free (rest[fd]);
		rest[fd] = NULL;
	}
	return (line);
}
