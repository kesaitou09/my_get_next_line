#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*arr;
	size_t	i;

	if (!s || !f)
		return (NULL);
	arr = ft_strdup(s);
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		arr[i] = (f)(i, s[i]);
		i++;
	}
	return (arr);
}
