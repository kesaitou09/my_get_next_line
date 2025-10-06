#include <unistd.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

// int	main(void)
//{
//	printf("%c\n", ft_tolower('A'));
//	printf("%c\n", tolower('A'));
// }