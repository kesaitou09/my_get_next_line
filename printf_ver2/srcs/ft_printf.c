#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

void init_info(t_info *inf)
{
	inf->flags = 0;
	inf->width = -1;
	inf->precision = -1;
	ft_bzero(inf->length, 3);
	inf->specifier = 0;
}

int ft_printf(const char *format, ...)
{
	va_list	args;
	t_info	inf;

	inf.total_len = 0;
	va_start(args, format);
	init_info(&inf);
	if (parse((char **)&format, &inf, &args) ==ERROR)
		return (va_end(args), ERROR);	
	va_end(args);
	return (inf.total_len);
}
