#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*arr;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	arr = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
// int main(void)
//{
//	printf("%s\n",ft_strdup(""));
//	printf("%s\n",strdup(""));
// }