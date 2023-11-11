/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarpawi <ekarpawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:48:08 by ekarpawi          #+#    #+#             */
/*   Updated: 2023/11/10 15:48:09 by ekarpawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_buffer(int fd, char **rtn, char **buffer)
{
	int	i;

	i = BUFFER_SIZE;
	while (i == BUFFER_SIZE)
	{
		i = read(fd, *buffer, BUFFER_SIZE);
		if (i == -1 || (i == 0 && !ft_strlen(*rtn)))
		{
			free(*rtn);
			free(*buffer);
			return (NULL);
		}
		if (i == 0)
			break ;
		*rtn = ft_str_join(*rtn, *buffer);
		if (ft_strchr(*buffer, '\n'))
			break ;
	}
	return (*rtn);
}

static char *remove_past(char **rtn)
{
	char	*new_rtn;
	int		i;
	int		j;

	i = 0;
	if (*rtn == NULL)
		return (NULL);
	while ((*rtn)[i] != '\n')
		i++;
	new_rtn = ft_calloc(ft_strlen(*rtn) - i + 1, sizeof(char));
	if (!new_rtn)
		return (NULL);
	j = 0;
	while ((*rtn)[++i])
		new_rtn[j++] = (*rtn)[i];
	return (new_rtn);
}

char	*get_next_line(int fd)
{
	static char		*rtn;
	char			*buffer;
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (rtn == NULL)
		rtn = ft_calloc(1, sizeof(char));
	else
		rtn = remove_past(&rtn);
	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!rtn || !buffer)
		return (NULL);
	rtn = read_and_buffer(fd, &rtn, &buffer);
	if (!rtn)
		return (NULL);
	free(buffer);
	if (!ft_strchr(rtn, '\n') || rtn[0] == '\n')
		return (rtn);
	i = 0;
	while (rtn[i++] != '\n')
		;
	return (ft_sub_str(rtn, 0, i));
}
