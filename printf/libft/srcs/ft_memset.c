#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	uc;

	i = 0;
	p = s;
	uc = c;
	while (i < n)
	{
		p[i] = uc;
		i++;
	}
	return (s);
}

// int main(void)
//{
//	char	z[5];
//	int		int_zero[5];

//	ft_memset(z,'z',4);
//	ft_memset(int_zero,0,4);

//	printf("%s\n",z);
//	printf("%d",int_zero[3]);
//}