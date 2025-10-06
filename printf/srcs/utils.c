#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) < 0)
		return (ERROR);
	return (1);
}

int	ft_putstr(char *s)
{
	int	n;

	n = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (write(1, s++, 1) < 0)
			return (ERROR);
		n++;
	}
	return (n);
}

int	fp_putnstr(const char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (write(1, s + i, 1) < 0)
			return (ERROR);
		i++;
	}
	return (i);
}

int	fp_putnchar(char c, int n)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (i < n)
	{
		if (write(1, &c, 1) < 0)
			return (ERROR);
		i++;
		w++;
	}
	return (w);
}

size_t	fp_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
