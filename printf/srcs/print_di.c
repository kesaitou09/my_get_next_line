#include "../includes/ft_printf.h"



int fp_print_di(t_fmt *f, int v)
{
	unsigned long long u;
	int neg;
	int dlen;
	int sign;
	int zeros;
	int ws;
	int w;
	int t;

	dlen = fp_di_abs_and_len(f, v, &u, &neg);
	sign = fp_di_sign_char(f, neg);
	fp_di_calc_pad(f, sign, dlen, &zeros, &ws);
	w = fp_di_emit_left(f, ws, sign, zeros);
	if (w == ERROR)
		return (ERROR);
	if (dlen > 0 && put_number_base_ull(u, "0123456789") == ERROR)
		return (ERROR);
	t = fp_di_emit_tail(f, ws);
	if (t == ERROR)
		return (ERROR);
	return (w + dlen + t);
}
