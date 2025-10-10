#include "../includes/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
//{
//	printf("%zu",ft_strlen(NULL));
//	printf("%zu",strlen(NULL));
// }