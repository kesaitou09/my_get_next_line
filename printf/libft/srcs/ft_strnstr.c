#include "libft.h"

// ヌル文字になるまで ＆＆サイズの回数だけ 探索文字列が出現するかを調べる。第二引数の終端まで一致してる場合のみその部分文字列の先頭を返す。
// 第二引数のn文字目までが存在するかどうかではない。

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;

	i = 0;
	if (!big || !little)
		return (NULL);
	if (!*little)
		return ((char *)(big));
	little_len = ft_strlen(little);
	while (*big && i < len && little_len <= len - i)
	{
		if (!ft_strncmp(big, little, little_len))
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}

// int	main(void)
//{
//	printf("libc %s\n", strnstr("abcdefhfiaefj", NULL, 30));
//	printf("my %s\n", ft_strnstr("abcdefhfiaefj", NULL, 30));
//		printf("%s\n",strnstr("abcdefhijk","de",3));
//		printf("%s\n",strnstr("abcdefhijk","de",3));
//		printf("%s\n",strnstr("abcdefhijk","de",3));
//		printf("%s\n",strnstr("abcdefhijk","de",3));
// }