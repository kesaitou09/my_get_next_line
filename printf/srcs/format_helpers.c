#include "../includes/ft_printf.h"

int	fp_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	fp_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
