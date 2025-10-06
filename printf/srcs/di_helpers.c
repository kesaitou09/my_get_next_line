#include "../includes/ft_printf.h"

int fp_di_sign_char(t_fmt *f, int neg)
{
	if (neg)
		return ('-');
	if (f->flag_plus)
		return ('+');
	if (f->flag_space)
		return (' ');
	return (0);
}

void fp_di_calc_pad(t_fmt *f, int sign, int dlen, int *zeros, int *ws)
{
	if (f->prec_set)
		f->flag_zero = 0;
	*zeros = 0;
	if (f->prec_set && f->precision > dlen)
		*zeros = f->precision - dlen;
	else if (f->flag_zero && !f->flag_minus)
	{
		*zeros = f->width - (sign != 0) - dlen;
		if (*zeros < 0)
			*zeros = 0;
	}
	*ws = f->width - (sign != 0) - *zeros - dlen;
	if (*ws < 0)
		*ws = 0;
}

int fp_di_emit_left(t_fmt *f, int ws, int sign, int zeros)
{
	int w;

	w = 0;
	if (!f->flag_minus && ws > 0)
	{
		w = fp_putnchar(' ', ws);
		if (w == ERROR)
			return (ERROR);
	}
	if (sign && ft_putchar((char)sign) == ERROR)
		return (ERROR);
	if (zeros > 0 && fp_putnchar('0', zeros) == ERROR)
		return (ERROR);
	return (w + (sign != 0) + zeros);
}

int fp_di_emit_tail(t_fmt *f, int ws)
{
	if (f->flag_minus && ws > 0)
	{
		ws = fp_putnchar(' ', ws);
		if (ws == ERROR)
			return (ERROR);
		return (ws);
	}
	return (0);
}

int fp_di_abs_and_len(t_fmt *f, int v, unsigned long long *u, int *neg)
{
	int dlen;

	*neg = (v < 0);
	if (*neg)
		*u = (unsigned long long)(-(long long)v);
	else
		*u = (unsigned long long)v;
	if (f->prec_set && f->precision == 0 && *u == 0)
		dlen = 0;
	else
		dlen = fp_count_digits_ull(*u, 10);
	return (dlen);
}
