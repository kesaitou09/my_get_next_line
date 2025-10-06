#include "../includes/ft_printf.h"

static void f_fetch_val_and_prec(t_fmt *f, va_list *ap, t_fctx *c)
{
	if (f->len_cap_l)
		c->val = va_arg(*ap, long double);
	else
		c->val = (long double)va_arg(*ap, double);
	c->neg = (c->val < 0.0L);
	if (c->neg)
		c->val = -c->val;
	if (!f->prec_set)
		c->prec = 6;
	else
		c->prec = f->precision;
	c->force_dot = (c->prec == 0 && f->flag_hash);
}

static int f_build_parts(t_fctx *c)
{
	unsigned long long all;
	long double sc;

	if (fp_pow10_ull(c->prec, &c->scale) == ERROR)
		c->scale = 1;
	sc = (long double)c->scale;
	all = (unsigned long long)(c->val * sc + 0.5L);
	c->ip = all / c->scale;
	c->frac = all % c->scale;
	c->ilen = fp_count_digits_ull(c->ip, 10);
	return (0);
}

static void f_calc_pad_sign(t_fmt *f, t_fctx *c)
{
	c->sign = fp_f_sign_char(f, c->neg);
	fp_f_calc_pad(f, c->sign, c->ilen, c->prec, c->force_dot,
				  &c->zeros, &c->ws);
}

static int f_emit_left_and_int(t_fmt *f, t_fctx *c)
{
	c->w = fp_di_emit_left(f, c->ws, c->sign, c->zeros);
	if (c->w == ERROR)
		return (ERROR);
	if (put_number_base_ull(c->ip, "0123456789") == ERROR)
		return (ERROR);
	return (0);
}

int fp_print_f(t_fmt *f, va_list *ap)
{
	t_fctx c;

	f_fetch_val_and_prec(f, ap, &c);
	if (f_build_parts(&c) == ERROR)
		return (ERROR);
	f_calc_pad_sign(f, &c);
	if (f_emit_left_and_int(f, &c) == ERROR)
		return (ERROR);
	c.t = fp_f_emit_frac(c.prec, c.force_dot, c.frac);
	if (c.t == ERROR)
		return (ERROR);
	c.ws = fp_di_emit_tail(f, c.ws);
	if (c.ws == ERROR)
		return (ERROR);
	return (c.w + c.ilen + c.t + c.ws);
}