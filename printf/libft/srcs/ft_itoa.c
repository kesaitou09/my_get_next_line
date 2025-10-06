#include "libft.h"

static int	count_len(int nbr);

char	*ft_itoa(int n)
{
	long long	num;
	char		*arr;
	int			len;

	num = n;
	len = count_len(num);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	arr[len] = '\0';
	if (num == 0)
		arr[0] = '0';
	if (num < 0)
	{
		arr[0] = '-';
		num = -num;
	}
	while (num)
	{
		arr[--len] = num % 10 + '0';
		num /= 10;
	}
	return (arr);
}

static int	count_len(int nbr)
{
	int			len;
	long long	n;

	len = 0;
	n = nbr;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

// int	main(void)
//{
//	printf("%s\n", ft_itoa(334));
// }