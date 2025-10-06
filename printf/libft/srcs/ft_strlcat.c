#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	if (!dst)
		return (ft_strlen(src));
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (size + src_len);
	j = 0;
	i = dst_len;
	while (src[j] && j < size - dst_len - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst_len + src_len);
}

// int	main(void)
//{
//	char	buf1[] = "aaa";
//	char	buf2[] = "jjkkkk";
//	char	buf3[] = "aaaaaaaaaa";

//	char	dst1[] = "dst1dayo";
//	char	dst2[] = "dst2dayo";
//	char	dst3[10];
//	char	dst4[10];
//	char	dst5[10];

//	printf("%zu,%s\n",strlcat(dst1,buf1,0),dst1);
//	printf("%zu,%s\n",ft_strlcat(dst1,buf1,0),dst1);

//}
