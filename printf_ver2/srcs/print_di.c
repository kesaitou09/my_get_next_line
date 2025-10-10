#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

int print_di(t_info *inf, va_list *args)
{
	int is_minus;
	char *num_arr;
	size_t prec_zero;

	is_minus = 0;
	prec_zero = 0;
	num_arr = stoa_hub(inf, args, "0123456789", &is_minus);
	if (!num_arr)
		return (ERROR);
	if (!inf->precision && !ft_strcmp(num_arr, "0"))
		num_arr[0] = '\0';
	else
	{
		if ((int)ft_strlen(num_arr) < inf->precision)
			prec_zero = inf->precision - (int)ft_strlen(num_arr);
	}
	if (s_print_process(num_arr, inf, prec_zero, is_minus) == ERROR)
		return (free(num_arr), ERROR);
	return (free(num_arr), SUCCESS);
}

int s_print_process(char *num_arr, t_info *inf, size_t zero, int is_minus)
{
	size_t num_len;
	size_t pad;
	size_t space;
	size_t sign;

	space = 0;
	sign = 0;
	num_len = ft_strlen(num_arr);
	if (inf->flags & F_SPACE && !(inf->flags & F_PLUS))
		space = 1;
	if (inf->flags & F_PLUS || is_minus)
		sign = 1;
	calc_pad(&pad, inf, num_len + zero + sign + space);
	if (right_align(inf, pad) == ERROR)
		return (ERROR);
	if (put_space_sign(inf, sign, is_minus, space) == ERROR)
		return (ERROR);
	if (put_nzero(inf, zero) == ERROR)
		return (ERROR);
	if (put_nstr(num_arr, num_len, inf) == ERROR)
		return (ERROR);
	if (inf->flags & F_MINUS && put_nspace(inf, pad) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

char *stoa_hub(t_info *inf, va_list *args, const char *base, int *is_minus)
{
	long long num;

	if (ft_strcmp(inf->length, "l") == 0)
		num = va_arg(*args, long);
	else if (ft_strcmp(inf->length, "ll") == 0)
		num = va_arg(*args, long long);
	else
	{
		num = va_arg(*args, int);
		if (num < 0)
		{
			num = -num;
			*is_minus = 1;
		}
		if (ft_strcmp(inf->length, "h") == 0)
			return (ft_utoa_base((signed short)num, base));
		else if (ft_strcmp(inf->length, "hh") == 0)
			return (ft_utoa_base((signed char)num, base));
	}
	if (num < 0)
	{
		num = -num;
		*is_minus = 1;
	}
	return (ft_utoa_base(num, base));
}

int right_align(t_info *inf, size_t pad)
{
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
	return (SUCCESS);
}
int put_space_sign(t_info *inf, size_t sign, int is_minus, size_t space)
{
	if (space)
	{
		if (ft_putchar(' ', inf) == ERROR)
			return (ERROR);
		return (SUCCESS);
	}
	if (sign)
	{
		if (inf->flags & F_PLUS && !is_minus)
		{
			if (ft_putchar('+', inf) == ERROR)
				return (ERROR);
		}
		else
		{
			if (ft_putchar('-', inf) == ERROR)
				return (ERROR);
		}
	}
	return (SUCCESS);
}
