#include "get_next_line.h"

char *read_file(int fd, char *va_buf)
{
	char *tmp;
	int rc;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	rc = 1;
	while (!ft_strchr(va_buf, '\n') && rc > 0)
	{
		rc = read(fd, tmp, BUFFER_SIZE);
		if (rc == -1)
			return (free(tmp), NULL);
		tmp[rc] = '\0';
		va_buf = ft_strjoin(va_buf, tmp);
		if (!va_buf)
			return (NULL);
	}
	free(tmp);
	return (va_buf);
}
char *get_line(char **va_buf)
{
	char *line;
	char *rest;
	size_t len;

	len = 0;
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
	*va_buf = rest;
	return (line);
}

char *get_next_line(int fd)
{
	static char *va_buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	va_buf = read_file(fd, va_buf);
	if (!va_buf || !*va_buf)
		return (free(va_buf), va_buf = NULL, NULL);
	return (get_line(&va_buf));
}

// int main(void)
//{
//	int fd;

//	fd = open("file.txt", O_RDONLY);
//	printf("%s",get_next_line(fd));
//	printf("%s",get_next_line(fd));
//	printf("%s",get_next_line(fd));
//	printf("%s",get_next_line(fd));
//	printf("%s",get_next_line(fd));
//	printf("%s",get_next_line(fd));

//	close(fd);

//}