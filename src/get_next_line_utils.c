/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarpawi <ekarpawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:48:22 by ekarpawi          #+#    #+#             */
/*   Updated: 2023/11/10 15:48:23 by ekarpawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*rtn;
	size_t	i;

	rtn = malloc(count * size);
	if (!rtn)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		rtn[i] = 0;
		i++;
	}
	return (rtn);
}

char	*ft_str_join(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		result[j++] = s1[i++];
	i = 0;
	while (s2[i])
		result[j++] = s2[i++];
	result[j] = '\0';
	free(s1);
	return (result);
}

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == (char)ch)
		return ((char *)(str + i));
	return (NULL);
}

char	*ft_sub_str(char *str, int start, int end)
{
	char	*rtn;
	int		i;

	if (!str)
		return (NULL);
	rtn = ft_calloc(end - start + 1, sizeof(char));
	if (!rtn)
		return (NULL);
	i = 0;
	while (start < end)
		rtn[i++] = str[start++];
	return (rtn);
}