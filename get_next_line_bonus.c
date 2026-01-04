/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaddy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:56:29 by aaddy             #+#    #+#             */
/*   Updated: 2025/11/17 15:32:24 by aaddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *buffer, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buf);
	free(buffer);
	return (tmp);
}

char	*read_file(int fd, char *buffer)
{
	char	*buf;
	char	*tmp;
	int		bytes;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (free(buffer), NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buf), free(buffer), NULL);
		buf[bytes] = '\0';
		tmp = ft_join(buffer, buf);
		buffer = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buf);
	return (buffer);
}

char	*extract_line(char *buffer)
{
	int		i;
	char	*line;
	int		j;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	return (line);
}

char	*next_line(char *buffer)
{
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i + j])
		j++;
	tmp = ft_calloc(j + 1, sizeof(char));
	if (!tmp)
		return (free(buffer), NULL);
	j = 0;
	while (buffer[i])
	{
		tmp[j] = buffer[i];
		j++;
		i++;
	}
	free(buffer);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd] || *buffer[fd] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = extract_line(buffer[fd]);
	buffer[fd] = next_line(buffer[fd]);
	return (line);
}
