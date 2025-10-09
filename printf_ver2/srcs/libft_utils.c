#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"


int ft_putchar(char c,t_info *inf)
{
    if (write(1, &c, 1) == ERROR)
        return (ERROR);
	inf ->total_len += 1;
    return (SUCCESS);
}

int ft_putstr(char *str,t_info *inf)
{
    while (*str)
    {
		if (ft_putchar(*str++, inf) == ERROR)
            return (ERROR);
    }
    return (SUCCESS);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	return (ft_strncmp(s1, s2, ft_strlen(s2)));
}