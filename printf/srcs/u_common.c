#include "../includes/ft_printf.h"

void fp_u_calc_pad(t_fmt *f, int plen, int dlen, int *zeros, int *ws)
{
	if (f->prec_set)
		f->flag_zero = 0;
	*zeros = 0;
	if (f->prec_set && f->precision > dlen)
		*zeros = f->precision - dlen;
	else if (f->flag_zero && !f->flag_minus)
	{
		*zeros = f->width - plen - dlen;
		if (*zeros < 0)
			*zeros = 0;
	}
	*ws = f->width - plen - *zeros - dlen;
	if (*ws < 0)
		*ws = 0;
}

int fp_u_emit(t_fmt *f, const char *px, int plen, int zeros, int ws)
{
	int w;

	w = 0;
	if (!f->flag_minus && ws > 0)
	{
		w = fp_putnchar(' ', ws);
		if (w == ERROR)
			return (ERROR);
	}
	if (plen && fp_putnstr(px, plen) == ERROR)
		return (ERROR);
	if (zeros > 0 && fp_putnchar('0', zeros) == ERROR)
		return (ERROR);
	return (w + plen + zeros);
}
