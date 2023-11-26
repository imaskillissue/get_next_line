/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarpawi <ekarpawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:48:08 by ekarpawi          #+#    #+#             */
/*   Updated: 2023/11/11 18:55:44 by ekarpawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*secure_free(char **target)
{
	if (target)
	{
		free(*target);
		*target = NULL;
	}
	return (NULL);
}

char	*format_line(int pos, char **buffer)
{
	char	*rtn;
	char	*tmp;

	tmp = NULL;
	if (pos <= 0)
	{
		if (**buffer == '\0')
			return (secure_free(buffer));
		rtn = *buffer;
		*buffer = NULL;
		return (rtn);
	}
	tmp = ft_sub_str(*buffer, pos, BUFFER_SIZE);
	rtn = *buffer;
	rtn[pos] = 0;
	*buffer = tmp;
	return (rtn);
}

char	*read_line(int fd, char **buffer, char *read_return)
{
	int		bytes_read;
	char	*tmp;
	char	*rtn;

	rtn = ft_strchr(*buffer, '\n');
	tmp = NULL;
	bytes_read = 0;
	while (rtn == NULL)
	{
		bytes_read = read(fd, read_return, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (format_line(bytes_read, buffer));
		read_return[bytes_read] = 0;
		tmp = ft_str_join(*buffer, read_return);
		secure_free(buffer);
		if (!tmp)
			return (NULL);
		*buffer = tmp;
		rtn = ft_strchr(*buffer, '\n');
	}
	return (format_line(rtn - *buffer + 1, buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffers[255];
	char		*line;
	char		*rtn;

	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (secure_free(&buffers[fd]));
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	if (!buffers[fd])
		buffers[fd] = ft_strdup("");
	if (!buffers[fd])
		return (secure_free(&line));
	rtn = read_line(fd, &buffers[fd], line);
	secure_free(&line);
	return (rtn);
}
