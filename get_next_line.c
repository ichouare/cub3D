/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:13:14 by ichouare          #+#    #+#             */
/*   Updated: 2023/05/29 15:40:07 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	*ft_calloc(size_t number, size_t size)
{
	void			*arr;

	arr = NULL;
	arr = (void *)malloc(size * number);
	if (!arr)
		return (NULL);
	ft_bzero(arr, size * number);
	return (arr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p1;

	p1 = s;
	while (n--)
	{
		*p1 = '\0';
		p1++;
	}
}

static char	*heandler_next_line(char **svr, char *line)
{
	char	*tmp;
	int		index;

	index = 0;
	if (found_nl(*svr, '\0') == 0)
	{
		free(*svr);
		*svr = NULL;
		return (NULL);
	}
	if (ft_strchr(*svr, '\n'))
	{
		index = found_nl(*svr, '\n');
		line = ft_substr(*svr, 0, index + 1);
		tmp = *svr;
		*svr = ft_substr(*svr, index + 1, found_nl(*svr, '\0') + 1);
		free(tmp);
	}
	else
	{
		line = ft_substr(*svr, 0, found_nl(*svr, '\0') + 1);
		free(*svr);
		*svr = NULL;
	}
	return (line);
}

static char	*handler_line( char **svr, char **buffer, int fd)
{
	char			*tmp;
	ssize_t			sz;
	

	sz = 1;
	while (ft_strchr(*svr, '\n') == 0 && sz != 0)
	{
		sz = read(fd, *buffer, BUFFER_SIZE);
		if (sz <= -1)
		{
			free(*buffer);
			free(*svr);
			return (NULL);
		}
		tmp = *svr;
		*svr = ft_strjoin(*svr, *buffer);
		free(tmp);
		tmp = NULL;
		ft_bzero(*buffer, found_nl(*buffer, '\0') + 1);
	}
	return (*svr);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*svr;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!svr)
		svr = ft_substr(buffer, 0, found_nl(buffer, '\0'));
	svr = handler_line(&svr, &buffer, fd);
	if (!svr)
		return (NULL);
	free(buffer);
	return (heandler_next_line(&svr, line));
}

