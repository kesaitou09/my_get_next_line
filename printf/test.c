#include "ft_printf.h"



int main(void)
{
	//	ft_ft_printf("%d\n", 5);
	//	ft_ft_printf("%s\n", "これもできるかも");
	//	ft_ft_printf("%d%d%d", 5, 334, 334);

	//ft_printf("|%05d\n", 42);
	//ft_printf("%-3d\n", 42);
	//ft_printf("|%05d\n", 42);
	//ft_printf("|%05d\n", 42);



	
	
	
	
	
	
	
	//フラグのテストケース
	ft_printf("自作 :フラグのテスト\n|%0d|\n", 42);
	ft_printf("|%-5d|\n", 42);
	ft_printf("|%-5d|\n", 42);
	ft_printf("|%05d|\n", 42);
	ft_printf("|%05d|\n", 42);
	ft_printf("|% d|\n", 42);
	ft_printf("|% d|\n", -42);
	ft_printf("|%#o|\n", 42);
	ft_printf("|%#x|\n", 42);
	ft_printf("|%#.0f|\n", 42.0);
	ft_printf("|%+05d|\n", -100);
	ft_printf("|%-8x|\n", 42);
	//ft_printf("|%#d|\n", 42);
	//ft_printf("|%#u|\n", 42);
	ft_printf("|%#.0f|\n", 42.0);
	ft_printf("|%#.5f|\n", 42.0);

	ft_printf("本家 :フラグのテスト\n|%0d|\n", 42);
	ft_printf("|%-5d|\n", 42);
	ft_printf("|%-5d|\n", 42);
	ft_printf("|%05d|\n", 42);
	ft_printf("|%05d|\n", 42);
	ft_printf("|% d|\n", 42);
	ft_printf("|% d|\n", -42);
	ft_printf("|%#o|\n", 42);
	ft_printf("|%#x|\n", 42);
	ft_printf("|%#.0f|\n", 42.0);
	ft_printf("|%+05d|\n", -100);
	ft_printf("|%-8x|\n", 42);
	//ft_printf("|%#d|\n", 42);
	//ft_printf("|%#u|\n", 42);
	ft_printf("|%#.0f|\n", 42.0);
	ft_printf("|%#.5f|\n", 42.0);


	//精度のテストケース
	ft_printf("\n\n自作 :精度のテストケース\n|%.5d|\n", 42);       // 00042
	ft_printf("|%.3d|\n", 12345);
	ft_printf("|%.0d|\n", 0);
	ft_printf("|%.3d|\n", 20);
	ft_printf("|%.3s|\n", "abcdef");
	ft_printf("|%.10s|\n", "hello");
	ft_printf("|%.0s|\n", "world");
	ft_printf("|%.*d|\n", -4, 42);	//*で引数を取る形で負の値が入力された場合、0と見做される。
	//ft_printf("|%.*2$f|\n", 0, 3, 123.456); macでは使えないけど対応必須

	ft_printf("\n\n本家 :精度のテストケース\n|%.5d|\n", 42);       // 00042
	ft_printf("|%.3d|\n", 12345);
	ft_printf("|%.0d|\n", 0);
	ft_printf("|%.3d|\n", 20);
	ft_printf("|%.3s|\n", "abcdef");
	ft_printf("|%.10s|\n", "hello");
	ft_printf("|%.0s|\n", "world");
	ft_printf("|%.*d|\n", -4, 42);



	//最小フィールド幅
	ft_printf("\n\n\n最小フィールドテスト\n|%*d|", 100, 42);

	


	//精度のテストケース
	ft_printf("\n\n\n精度のテスト\n|%.5d|\n", 42);
	ft_printf("|%.3f|\n", 3.14159);
	ft_printf("|%.3s|\n", "abcdef");


	ft_printf("\n\n\n長さ修飾子のテスト\n\n\n");
	char c = -12;
    short s = 32000;
    long l = 123456789L;
    long long ll = 1234567890123LL;
    size_t sz = 42;
    long double ld = 3.141592653589793238L;

    ft_printf("char with hh: %hhd\n", c);           // 120
    ft_printf("short with h: %hd\n", s);            // 32000
    ft_printf("long with l: %ld\n", l);             // 123456789
    ft_printf("long long with ll: %lld\n", ll);     // 1234567890123
    ft_printf("size_t with z: %zu\n", sz);          // 42
    ft_printf("long double with L: %Lf\n", ld);     // 3.141593













}
