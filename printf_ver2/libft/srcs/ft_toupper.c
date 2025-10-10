#include "../includes/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

// int	main(void)
//{
//	printf("%c\n", ft_toupper('\n'));
//	printf("%c\n", toupper('\n'));
// }