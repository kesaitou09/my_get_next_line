// main.c (修正版, %f テスト)
#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include "includes/ft_printf.h"

static void sep(const char *title) { printf("\n===== %s =====\n", title); }

int main(void)
{
	int r1, r2;

	sep("%f basic");
	r1 = ft_printf("[%f] [%f]\n", 123.25, -42.5);
	r2 = printf   ("[%f] [%f]\n", 123.25, -42.5);
	printf("ret ft=%d libc=%d\n", r1, r2);

	sep("precision");
	r1 = ft_printf("[%.0f] [%.1f] [%.6f]\n", 3.9, 3.05, 1.23456789);
	r2 = printf   ("[%.0f] [%.1f] [%.6f]\n", 3.9, 3.05, 1.23456789);
	printf("ret ft=%d libc=%d\n", r1, r2);

	sep("width");
	r1 = ft_printf("[%10.2f] [%-10.2f]\n", 12.34, 12.34);
	r2 = printf   ("[%10.2f] [%-10.2f]\n", 12.34, 12.34);
	printf("ret ft=%d libc=%d\n", r1, r2);

	sep("zero padding");
	r1 = ft_printf("[%010.2f] [%+010.2f]\n", 12.34, 7.0);
	r2 = printf   ("[%010.2f] [%+010.2f]\n", 12.34, 7.0);
	printf("ret ft=%d libc=%d\n", r1, r2);

	sep("sign flags (+ / space)");
	r1 = ft_printf("[%+f] [% f]\n", 7.0, 7.0);
	r2 = printf   ("[%+f] [% f]\n", 7.0, 7.0);
	printf("ret ft=%d libc=%d\n", r1, r2);

	sep("hash flag (#)");
	r1 = ft_printf("[%#.0f] [%#.0f]\n", 42.0, 0.0);
	r2 = printf   ("[%#.0f] [%#.0f]\n", 42.0, 0.0);
	printf("ret ft=%d libc=%d\n", r1, r2);

	sep("rounding carry");
	r1 = ft_printf("[%.2f] [%.2f]\n", 9.999, 1.999);
	r2 = printf   ("[%.2f] [%.2f]\n", 9.999, 1.999);
	printf("ret ft=%d libc=%d\n", r1, r2);

	sep("large + width/prec/left");
	r1 = ft_printf("[%12.3f] [%-12.3f]\n", 123456.75, 123456.75);
	r2 = printf   ("[%12.3f] [%-12.3f]\n", 123456.75, 123456.75);
	printf("ret ft=%d libc=%d\n", r1, r2);

	sep("length l (double)");
	r1 = ft_printf("[%lf] [%+020.6lf]\n", 1.5, -1234.5);
	r2 = printf   ("[%lf] [%+020.6lf]\n", 1.5, -1234.5);
	printf("ret ft=%d libc=%d\n", r1, r2);

	sep("length L (long double)");
	{
		long double p = 3.1415926535897932384626L;
		long double n = -42.75L;
		r1 = ft_printf("[%.15Lf] [%020.6Lf] [%+10.0Lf] [%#.0Lf]\n", p, p, n, 42.0L);
		r2 = printf   ("[%.15Lf] [%020.6Lf] [%+10.0Lf] [%#.0Lf]\n", p, p, n, 42.0L);
		printf("ret ft=%d libc=%d\n", r1, r2);
	}

	sep("mixed");
	r1 = ft_printf("A:%+08.3f B:%-#10.0f C:% 10.2f D:%#.0f\n", -123.456, 0.0, 7.5, 99.0);
	r2 = printf   ("A:%+08.3f B:%-#10.0f C:% 10.2f D:%#.0f\n", -123.456, 0.0, 7.5, 99.0);
	printf("ret ft=%d libc=%d\n", r1, r2);

	return 0;
}
