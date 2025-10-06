#include "../includes/ft_printf.h"

static int fp_dispatch(t_fmt *f, va_list *ap)
{
	if (f->spec == 'c')
		return (fp_print_char(f, va_arg(*ap, int)));
	if (f->spec == '%')
		return (fp_print_char(f, '%'));
	if (f->spec == 's')
		return (fp_print_str(f, va_arg(*ap, char *)));
	if (f->spec == 'p')
		return (fp_print_ptr(f, va_arg(*ap, void *)));
	if (f->spec == 'd' || f->spec == 'i')
		return (fp_print_di(f, va_arg(*ap, int)));
	if (f->spec == 'u')
		return (fp_print_u(f, va_arg(*ap, unsigned int)));
	if (f->spec == 'o')
		return (fp_print_o(f, va_arg(*ap, unsigned int)));
	if (f->spec == 'x')
		return (fp_print_x(f, va_arg(*ap, unsigned int), 0));
	if (f->spec == 'X')
		return (fp_print_x(f, va_arg(*ap, unsigned int), 1));
	if (f->spec == 'f')
		return (fp_print_f(f, ap));
	return (0);
}

int ft_printf(const char *fmt, ...)
{
	va_list ap;
	int tot;
	int r;
	t_fmt f;

	va_start(ap, fmt);
	tot = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			if (ft_putchar(*fmt++) == ERROR)
				return (va_end(ap), ERROR);
			tot++;
			continue;
		}
		fmt = fp_parse(fmt + 1, &f);
		if (!f.spec)
			continue;
		r = fp_dispatch(&f, &ap);
		if (r == ERROR)
			return (va_end(ap), ERROR);
		tot += r;
	}
	va_end(ap);
	return (tot);
}
