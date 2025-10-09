#include "../includes/ft_printf.h"

int	put_nspace(int n, t_info *inf)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (ft_putchar(' ',inf) == ERROR) 
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
int	is_flag(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (1);
	if (c == ' ')
		return (1);
	if (c == '#')
		return (1);
	if (c == '0')
		return (1);
	return (0);
}

int put_nstr(const char *str, size_t n, t_info *inf)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (ft_putchar(*str++, inf) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

void calc_maxlen(size_t *max_len, t_info *inf, const char *str)
{
	size_t str_len;

	str_len = ft_strlen(str);
	if (inf->precision >= 0)
	{
		if (inf->precision < str_len)
			*max_len = inf->precision;
		else
			*max_len = str_len;
	}
	else
		*max_len = str_len;
}

void	calc_pad(size_t *pad, t_info *inf, size_t max_len)
{
	if (inf ->width >= max_len)
		*pad = inf ->width - max_len;
	else
		*pad = 0;
}

