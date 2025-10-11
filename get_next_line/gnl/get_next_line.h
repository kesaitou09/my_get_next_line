#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char *ft_strchr(char *s, int c);
void *ft_memcpy(void *dest, const void *src, size_t n);
size_t ft_strlen(const char *s);
char *ft_strjoin(char *va_buf, char *tmp);
char *ft_strndup(char *s, size_t n);
char *get_line(char **va_buf);
char *get_next_line(int fd);
char *read_file(int fd, char *va_buf);

#endif