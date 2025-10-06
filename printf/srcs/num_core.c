#include "../includes/ft_printf.h"

int fp_count_digits_ull(unsigned long long u, int base)
{
	int n;

	if (u == 0)
		return (1);
	n = 0;
	while (u)
	{
		u /= (unsigned)base;
		n++;
	}
	return (n);
}

int put_number_base_ull(unsigned long long u, char *base)
{
	size_t bl;
	int r;

	bl = fp_strlen(base);
	if (u >= bl)
	{
		r = put_number_base_ull(u / bl, base);
		if (r == ERROR)
			return (ERROR);
	}
	if (ft_putchar(base[u % bl]) == ERROR)
		return (ERROR);
	return (1);
}

int put_number_base(unsigned int u, char *base)
{
	return (put_number_base_ull((unsigned long long)u, base));
}
