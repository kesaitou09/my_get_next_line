#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

int print_o(t_info *inf, va_list *args)
{
	size_t	hash_zero;
	size_t	prec_zero;
	char	*num_arr;

	hash_zero = 0;
	prec_zero = 0;
	num_arr = utoa_hub(inf, args, "01234567");
	if (!num_arr)
		return (ERROR);
	if (inf ->precision == 0 && ft_strcmp(num_arr, "0") == 0 && (!(inf ->flags & F_HASH)))
		num_arr[0] = '\0';
	if ((inf ->flags & F_HASH) && num_arr[0] != '0')
		hash_zero = 1;
	if (ft_strlen(num_arr) < inf->precision)
		prec_zero = inf ->precision - ft_strlen(num_arr);
	if (print_process(num_arr, inf ,hash_zero, prec_zero) == ERROR)
		return (free(num_arr), ERROR);
	return (free(num_arr), SUCCESS);
}

int print_process(char *num_arr, t_info *inf, size_t hash, size_t zero)
{
	size_t max_len;
	size_t pad;

	calc_maxlen(&max_len, inf, num_arr);
	calc_pad(&pad, inf, max_len + hash + zero);
	if (!(inf ->flags & F_MINUS))
	{
		if (inf ->flags & F_ZERO && put_nzero(inf, pad) == ERROR)
			return (ERROR);
		else if (put_nspace(inf ,pad) == ERROR)
			return (ERROR);
		if (put_nzero(hash + zero, inf) == ERROR)
			return (ERROR);
	}
	if (put_nstr(num_arr, max_len, inf) == ERROR)
		return (ERROR);
		
		

	
}

char *utoa_hub(t_info *inf, va_list *args, const char *base)
{
	unsigned long long num;

	if (ft_strcmp(inf->length, "l") == 0)
		num = va_arg(*args, unsigned long);
	else if (ft_strcmp(inf->length, "ll") == 0)
		num = va_arg(*args, unsigned long long);
	else
	{
		num = va_arg(*args, unsigned int);
		if (ft_strcmp(inf->length, "h") == 0)
			return (ft_utoa_base((unsigned short)num, base));
		else if (ft_strcmp(inf->length, "hh") == 0)
			return (ft_utoa_base((unsigned char)num, base));
	}
	return (ft_utoa_base(num, base));
}

char *ft_utoa_base(unsigned long long num, const char *base)
{
	char *num_arr;
	size_t num_len;
	size_t base_len;

	base_len = ft_strlen(base);
	num_len = count_len(num, base_len);
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

size_t count_len(unsigned long long num, size_t base_len)
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

int	put_nzero(t_info *inf, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (ft_putchar('0', inf) == ERROR)
			return (ERROR);
		i++;		
	}
	return (SUCCESS);
}

int	Precision_processing(char *num_arr, t_info *inf)
{
	size_t num_len;

	num_len = ft_strlen(num_arr);
	if (num_len < inf ->precision)
	{
		if (put_nzero(inf, inf ->precision - num_len) == ERROR)
			return (ERROR);
	}

	
}
