/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:35:22 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/19 15:33:38 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *va_buf)
{
	char	*tmp;
	char	*new_buf;
	int		rc;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	rc = 1;
	while (!ft_strchr(va_buf, '\n') && rc > 0)
	{
		rc = read(fd, tmp, BUFFER_SIZE);
		if (rc == -1)
			return (free(tmp), free(va_buf), NULL);
		tmp[rc] = '\0';
		new_buf = ft_strjoin(va_buf, tmp);
		if (!new_buf)
			return (free(va_buf), free(tmp), NULL);
		free(va_buf);
		va_buf = new_buf;
	}
	free(tmp);
	return (va_buf);
}

char	*get_line(char **va_buf)
{
	char	*line;
	char	*rest;
	char	*old;
	size_t	len;

	len = 0;
	if (*va_buf == NULL || **va_buf == '\0')
	{
		if (*va_buf)
		{
			free(*va_buf);
			*va_buf = NULL;
		}
		return (NULL);
	}
	while ((*va_buf)[len] != '\0' && (*va_buf)[len] != '\n')
		len++;
	if ((*va_buf)[len] == '\n')
		line = ft_strndup(*va_buf, len + 1);
	else
		line = ft_strndup(*va_buf, len);
	if (!line)
		return (NULL);
	if ((*va_buf)[len] == '\n')
		rest = ft_strndup((*va_buf) + len + 1, ft_strlen((*va_buf) + len + 1));
	else
		rest = NULL;
	old = *va_buf;
	*va_buf = rest;
	free(old);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*va_buf[30000000];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = read_file(fd, va_buf[fd]);
	if (!res)
	{
		va_buf[fd] = NULL;
		return (NULL);
	}
	va_buf[fd] = res;
	return (get_line(&va_buf[fd]));
}
