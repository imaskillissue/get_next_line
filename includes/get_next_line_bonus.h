/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarpawi <ekarpawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:48:00 by ekarpawi          #+#    #+#             */
/*   Updated: 2023/11/10 15:48:01 by ekarpawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);

char	*ft_str_join(char *s1, char *s2);

char	*ft_sub_str(char *str, int start, int end);

char	*ft_strchr(const char *str, int ch);

int		ft_strlen(const char *str);

char	*ft_strdup(const char *str);
