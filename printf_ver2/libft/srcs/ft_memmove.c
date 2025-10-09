#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)src;
	i = 0;
	if (p1 < p2)
	{
		while (i < n)
		{
			p1[i] = p2[i];
			i++;
		}
	}
	else
	{
		while (0 < n--)
			p1[n] = p2[n];
	}
	return (p1);
}

// int main(void)
//{
//	char str1[] = "abcdefg";
//	char str2[] = "abcdefg";

//	ft_memmove(&str1[6],&str1[0],1);
//	printf("%s\n",str1);
//	memmove(&str2[6],&str2[0],1);
//	printf("%s\n",str2);
//}