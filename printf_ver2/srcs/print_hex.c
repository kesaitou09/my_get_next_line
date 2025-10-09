#include "../includes/ft_printf.h"

int ft_print_hex(uintptr_t p)
{
    unsigned char hex[] = "0123456789abcdef";
    int count = 0;

    if (p >= 16)
        count += ft_print_hex(p / 16);
    ft_putchar(hex[p % 16]);
    return count + 1;
}

int print_ptr(void *ptr)
{
    uintptr_t p = (uintptr_t)ptr;
    int count = 0;

    int res = ft_putstr("0x");
    if (res == ERROR)
        return (ERROR);
    count += res;
	res = ft_print_hex(p);
    if (res == ERROR)
        return (ERROR);
    count += res;
    return (count);
}

//int main(void)
//{
//	int a = 4;
//	char *aa = "aaaaa";

//	print_memory(aa);
//	printf("\n%p\n",aa);
//	print_memory(&a);
//	printf("\n%p\n",&a);
//}











