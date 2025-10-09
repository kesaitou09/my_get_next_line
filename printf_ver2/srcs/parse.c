#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

static int ft_issep(char c);
int ft_atoi_alpha(const char **nptr);

void parse_flag(char **fmt, t_info *inf)
{
	while (is_flag(**fmt))
	{
		if (**fmt == '+')
			inf->flags |= F_PLUS;
		else if (**fmt == '-')
			inf->flags |= F_MINUS;
		else if (**fmt == ' ')
			inf->flags |= F_SPACE;
		else if (**fmt == '0')
			inf->flags |= F_ZERO;
		else if (**fmt == '#')
			inf->flags |= F_HASH;
		(**fmt)++;
	}
	if (inf->flags & F_PLUS)
		inf->flags &= ~F_SPACE;
	if (inf->flags & F_MINUS)
		inf->flags &= ~F_ZERO;
}
void parse_width(char **format, t_info *inf)
{
	if (**format == '0')
		return;
	inf->width = ft_atoi_alpha(format);
}

void parse_precision(char **format, t_info *inf)
{
	if (**format == '.')
	{
		(*format)++;
		inf->precision = ft_atoi_alpha(format);
	}
}

void parse_length(char **format, t_info *inf)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		ft_memcpy(inf->length, "hh", 3);
		(*format) += 2;
		return;
	}
	if (**format == 'l' && *(*format + 1) == 'l')
	{
		ft_memcpy(inf->length, "ll", 3);
		(*format) += 2;
		return;
	}
	if (**format == 'h')
		inf->length[0] = 'h';
	else if (**format == 'l')
		inf->length[0] = 'l';
	else if (**format == 'L')
		inf->length[0] = 'L';
	(*format)++;
}

void parse_specifi(char **format, t_info *inf)
{
	if (**format == 'c' || **format == 's' || **format == 'p' || **format == 'd' ||
		**format == 'i' || **format == 'u' || **format == 'x' || **format == 'X' ||
		**format == '%')
		inf->specifier = **format;
	else
		return ;
	(*format)++;
}

int parse_hub(char **format, t_info *inf)
{
	if (**format == '%')
	{
		(*format)++;
		parse_flag(format, inf);
		parse_width(format, inf);
		parse_precision(format, inf);
		parse_length(format, inf);
		parse_specifi(format, inf);
	}
	else if (ft_putchar(**format, inf) == ERROR)
		return (ERROR);return (SUCCESS);
}

int ft_atoi_alpha(const char **nptr)
{
	int result;

	result = 0;
	while (**nptr >= '0' && **nptr <= '9')
	{
		result = result * 10 + (**nptr - '0');
		(*nptr)++;
	}
	return (result);
}
