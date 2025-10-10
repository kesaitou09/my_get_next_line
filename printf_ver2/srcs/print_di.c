#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

int print_di(t_info *inf, va_list *args)
{
	int		is_minus;
	char	*num_arr;
	size_t	prec_zero;

	prec_zero = 0;
	num_arr = sitoa_hub(inf, args, "0123456789");
	if (!num_arr)
		return (ERROR);
	if (!inf ->precision && !ft_strcmp(num_arr, "0"))
		num_arr[0] = '\0';
	else
	{
		if ((int)ft_strlen(num_arr) < inf ->precision)
			prec_zero = inf ->precision - ft_strlen(num_arr);		
	}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}


int s_print_process(char *num_arr, t_info *inf, size_t zero, int is_minus)
{
	size_t num_len;
	size_t pad;

	num_len = ft_strlen(num_arr);
	calc_pad(&pad, inf, num_len + zero + is_minus);
	if (!(inf->flags & F_MINUS))
	{
		if (inf->flags & F_ZERO && inf->precision == -1)
		{
			if (put_nzero(inf, pad) == ERROR)
				return (ERROR);
		}
		else if (put_nspace(inf, pad) == ERROR)
			return (ERROR);
	}
	if (put_nzero(inf,zero) == ERROR)
		return (ERROR);
	if (put_nstr(num_arr, num_len, inf) == ERROR)
		return (ERROR);
	if (inf->flags & F_MINUS && put_nspace(inf, pad) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
