#include "../includes/ft_printf.h"

static char char_pad(t_fmt *f)
{
	if (f->flag_zero && !f->flag_minus && f->spec == '%')
		return ('0');
	return (' ');
}

int fp_print_char(t_fmt *f, int c)
{
	int ws;
	int w;
	char pad;

	ws = 0;
	if (f->width > 1)
		ws = f->width - 1;
	pad = char_pad(f);
	w = 0;
	if (!f->flag_minus && ws > 0)
	{
		w = fp_putnchar(pad, ws);
		if (w == ERROR)
			return (ERROR);
	}
	if (ft_putchar((char)c) == ERROR)
		return (ERROR);
	if (f->flag_minus && ws > 0)
	{
		ws = fp_putnchar(' ', ws);
		if (ws == ERROR)
			return (ERROR);
		return (w + 1 + ws);
	}
	return (w + 1);
}
