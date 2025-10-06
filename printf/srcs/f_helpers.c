#include "../includes/ft_printf.h"

int	fp_pow10_ull(int p, unsigned long long *out)
{
	unsigned long long	r;
	int					i;

	if (p < 0)
		p = 0;
	r = 1;
	i = 0;
	while (i < p)
	{
		r *= 10ULL;
		i++;
	}
	*out = r;
	return (0);
}

int	fp_f_sign_char(t_fmt *f, int neg)
{
	if (neg)
		return ('-');
	if (f->flag_plus)
		return ('+');
	if (f->flag_space)
		return (' ');
	return (0);
}

void	fp_f_calc_pad(t_fmt *f, int sign, int ilen, int prec,
			int force_dot, int *zeros, int *ws)
{
	int	body;

	body = ilen;
	if (prec > 0 || force_dot)
		body = ilen + 1 + prec;
	*zeros = 0;
	if (f->flag_zero && !f->flag_minus)
	{
		*zeros = f->width - (sign != 0) - body;
		if (*zeros < 0)
			*zeros = 0;
	}
	*ws = f->width - (sign != 0) - *zeros - body;
	if (*ws < 0)
		*ws = 0;
}

int	fp_f_emit_frac(int prec, int force_dot, unsigned long long frac)
{
	int	d;
	int	pad;

	if (prec == 0 && !force_dot)
		return (0);
	if (ft_putchar('.') == ERROR)
		return (ERROR);
	if (prec == 0)
		return (1);
	d = fp_count_digits_ull(frac, 10);
	pad = prec - d;
	if (pad > 0 && fp_putnchar('0', pad) == ERROR)
		return (ERROR);
	if (put_number_base_ull(frac, "0123456789") == ERROR)
		return (ERROR);
	return (1 + (pad > 0 ? pad : 0) + d);
}
