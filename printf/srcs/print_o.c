#include "../includes/ft_printf.h"


static void	o_hash_rule(t_fmt *f, t_uox_ctx *c)
{
	c->px = 0;
	c->plen = 0;
	if (f->prec_set && f->precision == 0 && c->u == 0 && f->flag_hash)
		c->dlen = 1;
	else if (f->prec_set && f->precision == 0 && c->u == 0)
		c->dlen = 0;
	else
		c->dlen = fp_count_digits_ull(c->u, 8);
	if (f->flag_hash && c->u != 0
		&& (!f->prec_set || f->precision <= c->dlen))
	{
		c->px = "0";
		c->plen = 1;
	}
}

int	fp_print_o(t_fmt *f, unsigned int v)
{
	t_uox_ctx	c;

	c.u = (unsigned long long)v;
	o_hash_rule(f, &c);
	fp_u_calc_pad(f, c.plen, c.dlen, &c.zeros, &c.ws);
	c.w = fp_u_emit(f, c.px, c.plen, c.zeros, c.ws);
	if (c.w == ERROR)
		return (ERROR);
	if (c.dlen > 0 && put_number_base_ull(c.u, "01234567") == ERROR)
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
