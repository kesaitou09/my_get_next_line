#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

int print_p(va_list *args, t_info *inf, char *base)
{
	char	*num_arr;
	size_t	prec_zero;

	prec_zero = 0;
	num_arr = ft_uptoa_base((uintptr_t)va_arg(*args, void *), base);
	if (!num_arr)
		return (ERROR);
	if (inf->precision == 0 && ft_strcmp(num_arr, "0") == 0)
		num_arr[0] = '\0';
	else if ((int)ft_strlen(num_arr) < inf->precision)
		prec_zero = inf->precision - (int)ft_strlen(num_arr);
	if (p_print_process(num_arr, inf, 2, prec_zero) == ERROR)
		return (free(num_arr), ERROR);
	return (free(num_arr), SUCCESS);
}

char *ft_uptoa_base(uintptr_t num, char *base)
{
	char *num_arr;
	size_t num_len;
	size_t base_len;

	base_len = ft_strlen(base);
	num_len = count_len_ptr(num, base_len);
	num_arr = malloc(sizeof(char) * (num_len + 1));
	if (!num_arr)
		return (NULL);
	num_arr[num_len] = '\0';
	while (num_len)
	{
		num_arr[--num_len] = base[num % base_len];
		num /= base_len;
	}
	return (num_arr);
}


int p_print_process(char *num_arr, t_info *inf, size_t hash, size_t zero)
{
	size_t num_len;
	size_t pad;

	num_len = ft_strlen(num_arr);
	calc_pad(&pad, inf, num_len + hash + zero);
	if (right_align(inf, pad) == ERROR)
		return (ERROR);	
	if (print_hash(inf, hash) == ERROR)
		return (ERROR);
	if (put_nzero(inf,zero) == ERROR)
		return (ERROR);
	if (put_nstr(num_arr, num_len, inf) == ERROR)
		return (ERROR);
	if (inf->flags & F_MINUS && put_nspace(inf, pad) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

size_t count_len_ptr(uintptr_t num, size_t base_len)
{
	size_t len;

	len = 0;
	if (!num)
		len++;
	while (num)
	{
		len++;
		num /= base_len;
	}
	return (len);
}
