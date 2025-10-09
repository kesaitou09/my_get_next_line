#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"



int		print_hub(va_list *args,t_info *inf)
{
	if (inf ->specifier == 'c' || inf ->specifier == '%')
		return (print_cper(args, inf));
	else if(inf ->specifier == 's')
		return (print_s(args, inf));
	else if (inf ->specifier == 'p')
		return (print_p());
	else if (inf ->specifier == 'd' || inf ->specifier == 'i')
		return (print_di());
	else if (inf ->specifier == 'o')
		return (print_o());
	else if (inf ->specifier == 'u')
		return (print_u());
	else if (inf ->specifier == 'x')
		return (print_x());
	else if (inf ->specifier == 'X')
		return (print_X());
	else if (inf ->specifier == 'f')
		return (print_f());
	return (ERROR);
}

