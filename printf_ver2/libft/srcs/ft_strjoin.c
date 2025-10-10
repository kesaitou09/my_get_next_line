#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	arr = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!arr)
		return (NULL);
	ft_memcpy(arr, s1, s1_len);
	ft_memcpy(arr + s1_len, s2, s2_len);
	arr[s1_len + s2_len] = '\0';
	return (arr);
}

// int	main(void)
//{
//	printf("%s\n", ft_strjoin(NULL, "bbbb"));
// }
