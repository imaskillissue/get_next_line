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

char	*get_next_line(int fd)
{
	static char	*rtn;
	char		*buffer;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rtn = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!rtn || !buffer)
		return (NULL);
	i = BUFFER_SIZE;
	while (i == BUFFER_SIZE)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1 || (i == 0 && !ft_strlen(rtn)))
		{
			free(rtn);
			free(buffer);
			return (NULL);
		}
		rtn = ft_str_join(rtn, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (ft_sub_str(rtn, 0, (int)(ft_strchr(rtn, '\n') - rtn + 1)));
}
