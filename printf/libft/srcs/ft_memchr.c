#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		c1;
	const unsigned char	*p;

	c1 = (unsigned char)c;
	p = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*p == c1)
			return ((void *)(p));
		p++;
		i++;
	}
	return (NULL);
}

// int	main(void)
//{
//		char str2[] = "abcdefghi";
//		char str3[] = "abcdefghi";

//		printf("%s\n",(char *)ft_memchr(str2,'a',11));
//		printf("%s\n",(char *)memchr(str2,'a',11));

//	unsigned char s[] = "abcdefgh";
//	char *p1;
//	char *p2;
//	int c = -120;
//	int n = 8;
//	s[2] = -120; // 文字列sの'c'を-120に変更
//	p1 = memchr(s, c, n);
//	printf("memchr   = %s\n", p1);
//	p2 = ft_memchr(s, c, n);
//	printf("mymemchr = %s\n", p2);
//}