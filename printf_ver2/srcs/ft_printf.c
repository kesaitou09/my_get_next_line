#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"




void	init_info(t_info *inf)
{
	inf ->flags = 0;
	inf ->width = -1;
	inf ->precision = -1;
	ft_bzero(inf ->length,3);
	inf ->specifier = 0;
	inf ->total_len = 0;
}

int ft_printf(const char *format , ...)
{
	va_list args;
	t_info inf;

	va_start(args,format);
	parse_hub(&format,&inf);
	print_hub(args,&inf);

	
	
	

	
	return (inf.total_len);
}