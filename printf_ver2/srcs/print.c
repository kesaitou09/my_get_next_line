#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"



int		print_hub(va_list *args,t_info *inf)
{
	if (inf ->specifier == 'c' || inf ->specifier == '%')
		return (print_cper(args, inf));
	else if(inf ->specifier == 's')
		return (print_s(args, inf));
	else if (inf ->specifier == 'd' || inf ->specifier == 'i')
		return (print_di(inf, args));
	else if (inf ->specifier == 'o')
		return (print_o(inf, args));
	else if (inf ->specifier == 'u')
		return (print_u(inf, args));
	else if (inf ->specifier == 'x')
		return (print_x(inf, args));
	else if (inf ->specifier == 'X')
		return (print_X(inf, args));
	
	//else if (inf ->specifier == 'p')
	//	return (print_p());
	
	return (SUCCESS);
}

