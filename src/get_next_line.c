/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarpawi <ekarpawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:48:08 by ekarpawi          #+#    #+#             */
/*   Updated: 2023/11/11 18:30:40 by ekarpawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean(char **target)
{
	if (target)
	{
		free(*target);
		*target = NULL;
	}
}

char	*join_line(int nl_position, char **buffer)
{
	char	*res;
	char	*tmp;

	tmp = NULL;
	if (nl_position <= 0)
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		res = *buffer;
		*buffer = NULL;
		return (res);
	}
	tmp = ft_sub_str(*buffer, nl_position, BUFFER_SIZE);
	res = *buffer;
	res[nl_position] = 0;
	*buffer = tmp;
	return (res);
}

char	*read_line(int fd, char **buffer, char *read_return)
{
	ssize_t	bytes_read;
	char	*tmp;
	char	*nl;

	nl = ft_strchr(*buffer, '\n');
	tmp = NULL;
	bytes_read = 0;
	while (nl == NULL)
	{
		bytes_read = read(fd, read_return, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (join_line(bytes_read, buffer));
		read_return[bytes_read] = 0;
		tmp = ft_str_join(*buffer, read_return);
		clean(buffer);
		*buffer = tmp;
		nl = ft_strchr(*buffer, '\n');
	}
	return (join_line(nl - *buffer + 1, buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffers[255];
	char		*line;
	char		*rtn;

	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	if (!buffers[fd])
		buffers[fd] = ft_strdup("");
	rtn = read_line(fd, &buffers[fd], line);
	clean(&line);
	return (rtn);
}
