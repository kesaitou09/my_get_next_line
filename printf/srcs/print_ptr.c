#include "../includes/ft_printf.h"

static void ptr_calc_pad(t_fmt *f, int dlen, int *zeros, int *ws)
{
	*zeros = 0;
	if (f->prec_set)
	{
		if (f->precision > dlen)
			*zeros = f->precision - dlen;
	}
	else if (f->flag_zero && !f->flag_minus)
	{
		if (f->width > 2 + dlen)
			*zeros = f->width - 2 - dlen;
	}
	*ws = f->width - 2 - *zeros - dlen;
	if (*ws < 0)
		*ws = 0;
}

static int ptr_emit(t_fmt *f, unsigned long long v, int zeros, int ws, int dlen)
{
	int w;

	w = 0;
	if (!f->flag_minus && ws > 0)
	{
		w = fp_putnchar(' ', ws);
		if (w == ERROR)
			return (ERROR);
	}
	if (fp_putnstr("0x", 2) == ERROR)
		return (ERROR);
	if (zeros > 0 && fp_putnchar('0', zeros) == ERROR)
		return (ERROR);
	if (dlen > 0 && put_number_base_ull(v, "0123456789abcdef") == ERROR)
		return (ERROR);
	if (f->flag_minus && ws > 0)
	{
		ws = fp_putnchar(' ', ws);
		if (ws == ERROR)
			return (ERROR);
		w += ws;
	}
	return (w + 2 + zeros + dlen);
}

int fp_print_ptr(t_fmt *f, void *p)
{
	unsigned long long v;
	int dlen;
	int zeros;
	int ws;

	v = (unsigned long long)(uintptr_t)p;
	if (f->prec_set && f->precision == 0 && v == 0)
		dlen = 0;
	else
		dlen = fp_count_digits_ull(v, 16);
	ptr_calc_pad(f, dlen, &zeros, &ws);
	return (ptr_emit(f, v, zeros, ws, dlen));
}
