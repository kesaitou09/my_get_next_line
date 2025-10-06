#include "../includes/ft_printf.h"

static void x_prefix(t_fmt *f, int up, t_uox_ctx *c)
{
	c->px = 0;
	c->plen = 0;
	if (c->u != 0 && f->flag_hash)
	{
		if (up)
			c->px = "0X";
		else
			c->px = "0x";
		c->plen = 2;
	}
}

static char *x_digits(int up)
{
	if (up)
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

int fp_print_x(t_fmt *f, unsigned int v, int up)
{
	t_uox_ctx c;

	c.u = (unsigned long long)v;
	x_prefix(f, up, &c);
	if (f->prec_set && f->precision == 0 && c.u == 0)
		c.dlen = 0;
	else
		c.dlen = fp_count_digits_ull(c.u, 16);
	fp_u_calc_pad(f, c.plen, c.dlen, &c.zeros, &c.ws);
	c.w = fp_u_emit(f, c.px, c.plen, c.zeros, c.ws);
	if (c.w == ERROR)
		return (ERROR);
	if (c.dlen > 0 && put_number_base_ull(c.u, x_digits(up)) == ERROR)
		return (ERROR);
	if (f->flag_minus && c.ws > 0)
	{
		c.t = fp_putnchar(' ', c.ws);
		if (c.t == ERROR)
			return (ERROR);
		return (c.w + c.dlen + c.t);
	}
	return (c.w + c.dlen);
}
