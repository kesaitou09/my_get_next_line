#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	if ((char)c == '\0')
		return ((char *)(p));
	while (s < p)
	{
		if (*(p - 1) == (char)c)
		{
			return ((char *)(p - 1));
		}
		p--;
	}
	return (NULL);
}

// int main(void)
//{
//	printf("%s\n",strrchr("abbaaaaabbaifififohf ",'a'));
//	printf("%s\n",ft_strrchr("abbaaaaabbaifififohf ",'a'));
//	printf("%s\n",strrchr("abbaaaaabbaifififohf",'a'));
// }