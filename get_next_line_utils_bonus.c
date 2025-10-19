/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:35:14 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/19 11:35:17 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)(s));
		}
		s++;
	}
	if ((char)c == '\0')
		return ((char *)(s));
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*p1 = *p2;
		p1++;
		p2++;
		i++;
	}
	return (dest);
}

char	*ft_strndup(char *s, size_t n)
{
	char	*arr;
	size_t	len;

	len = 0;
	while (len < n && s[len])
		len++;
	if (len > SIZE_MAX - 1)
		return (NULL);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	ft_memcpy(arr, s, len);
	arr[len] = '\0';
	return (arr);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *va_buf, char *tmp)
{
	char	*arr;
	size_t	va_buf_len;
	size_t	tmp_len;

	va_buf_len = ft_strlen(va_buf);
	tmp_len = ft_strlen(tmp);
	arr = malloc(sizeof(char) * (va_buf_len + tmp_len + 1));
	if (!arr)
		return (NULL);
	ft_memcpy(arr, va_buf, va_buf_len);
	ft_memcpy(arr + va_buf_len, tmp, tmp_len);
	arr[va_buf_len + tmp_len] = '\0';
	return (arr);
}
