#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*p1 = *p2;
		p1++;
		p2++;
		i++;
	}
	return (p1);
}

// int	main(void)
//{
//	int x = 4299;
//	int y = 0;
//	ft_memcpy(&x, &x, 4);
//	printf("%d\n", x);
//	memcpy(&x, &x, 4);
//	printf("%d\n", x);
//	//ft_memcpy(&y, &x, 4);

//}