#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

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
