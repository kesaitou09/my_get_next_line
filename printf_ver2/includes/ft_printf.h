#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

#define SUCCESS 1
#define ERROR -1

typedef struct s_info
{
	unsigned char flags;
	size_t width;
	int precision;
	char length[3];
	char specifier;
	int total_len;
} t_info;

typedef enum e_flag
{
	F_MINUS = 1 << 0,
	F_PLUS = 1 << 1,
	F_SPACE = 1 << 2,
	F_ZERO = 1 << 3,
	F_HASH = 1 << 4,
} t_flag;

int parse_hub(char **format, t_info *inf);
int print_hub(va_list *args, t_info *inf);
int print_s(va_list *args, t_info *inf);
int print_cper(va_list *args, t_info *inf);

int put_nstr(const char *str, size_t n, t_info *inf);
void calc_maxlen(size_t *max_len, t_info *inf, const char *str);
void calc_pad(size_t *pad, t_info *inf, size_t max_len);

int put_nspace(int n, t_info *inf);
int ft_putchar(char c, t_info *inf);
int ft_putstr(char *str, t_info *inf);
int	put_nzero(t_info *inf, size_t n);
int is_flag(char c);
int ft_atoi_alpha(const char **nptr);
int	ft_strcmp(const char *s1, const char *s2);


#endif
