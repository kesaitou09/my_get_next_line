#include "../includes/ft_printf.h"

static int str_left_pad(t_fmt *f, int ws)
{
	int w;

	w = 0;
	if (!f->flag_minus && ws > 0)
	{
		w = fp_putnchar(' ', ws);
		if (w == ERROR)
			return (ERROR);
	}
	return (w);
}

static int str_right_pad(t_fmt *f, int ws)
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

int fp_print_str(t_fmt *f, const char *s)
{
	int len;
	int use;
	int ws;
	int w;

	if (!s)
		s = "(null)";
	len = (int)fp_strlen(s);
	use = len;
	if (f->prec_set && f->precision < use)
		use = f->precision;
	ws = 0;
	if (f->width > use)
		ws = f->width - use;
	w = str_left_pad(f, ws);
	if (w == ERROR)
		return (ERROR);
	if (fp_putnstr(s, use) == ERROR)
		return (ERROR);
	ws = str_right_pad(f, ws);
	if (ws == ERROR)
		return (ERROR);
	return (w + use + ws);
}
