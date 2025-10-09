//#include "../includes/ft_printf.h"
#include <stdio.h>


int main(void)
{
	//	printf("%d\n", 5);
	//	printf("%s\n", "これもできるかも");
	//	printf("%d%d%d", 5, 334, 334);
	
	//printf("幅のテスト\n");
	//printf("|%5d|\n", 42);
	//printf("|%3d|\n", 42);
	//printf("|%d|\n", 42);
	//printf("|%d|\n", 42);
	//printf("|%-21c|\n", 'a');
	//printf("|%21c|\n", 'a');
	//printf("|%0c|\n", 'a');
	//printf("|%-0c|\n", 'a');


	printf("精度\n|%#10o|\n", 6);
	printf("|%.5d|\n", 42);
	printf("|%.100d|\n", 42);
	printf("|%.0d|\n", 42);
	printf("|%.1d|\n", 42);
	printf("%f\n", 1.2345688888);   // 1.235
	printf("%10.3e\n", 12.3);    // "  1.230e+01" のように幅→空白埋め
	printf("%.2s\n", "abc"); 







	
	
	
	
	
	
	
	////フラグのテストケース
	//printf("自作 :フラグのテスト\n|%0d|\n", 42);
	//printf("|%-5d|\n", 42);
	//printf("|%-5d|\n", 42);
	//printf("|%05d|\n", 42);
	//printf("|%05d|\n", 42);
	//printf("|% d|\n", 42);
	//printf("|% d|\n", -42);
	//printf("|%#o|\n", 42);
	//printf("|%#x|\n", 42);
	//printf("|%#.0f|\n", 42.0);
	//printf("|%+05d|\n", -100);
	//printf("|%-8x|\n", 42);
	////printf("|%#d|\n", 42);
	////printf("|%#u|\n", 42);
	//printf("|%#.0f|\n", 42.0);
	//printf("|%#.5f|\n", 42.0);

	//printf("本家 :フラグのテスト\n|%0d|\n", 42);
	//printf("|%-5d|\n", 42);
	//printf("|%-5d|\n", 42);
	//printf("|%05d|\n", 42);
	//printf("|%05d|\n", 42);
	//printf("|% d|\n", 42);
	//printf("|% d|\n", -42);
	//printf("|%#o|\n", 42);
	//printf("|%#x|\n", 42);
	//printf("|%#.0f|\n", 42.0);
	//printf("|%+05d|\n", -100);
	//printf("|%-8x|\n", 42);
	////printf("|%#d|\n", 42);
	////printf("|%#u|\n", 42);
	//printf("|%#.0f|\n", 42.0);
	//printf("|%#.5f|\n", 42.0);


	////精度のテストケース
	//printf("\n\n自作 :精度のテストケース\n|%.5d|\n", 42);       // 00042
	//printf("|%.3d|\n", 12345);
	//printf("|%.0d|\n", 0);
	//printf("|%.3d|\n", 20);
	//printf("|%.3s|\n", "abcdef");
	//printf("|%.10s|\n", "hello");
	
	//printf("|%.0s|\n", "world");
	//printf("|%.*d|\n", -4, 42);	//*で引数を取る形で負の値が入力された場合、0と見做される。
	////printf("|%.*2$f|\n", 0, 3, 123.456); macでは使えないけど対応必須

	//printf("\n\n本家 :精度のテストケース\n|%.5d|\n", 42);       // 00042
	//printf("|%.3d|\n", 12345);
	//printf("|%.0d|\n", 0);
	//printf("|%.3d|\n", 20);
	//printf("|%.3s|\n", "abcdef");
	//printf("|%.10s|\n", "hello");
	//printf("|%.0s|\n", "world");
	//printf("|%.*d|\n", -4, 42);



	////最小フィールド幅
	//printf("\n\n\n最小フィールドテスト\n|%*d|", 100, 42);

	


	////精度のテストケース
	//printf("\n\n\n精度のテスト\n|%.5d|\n", 42);
	//printf("|%.3f|\n", 3.14159);
	//printf("|%.3s|\n", "abcdef");


	//printf("\n\n\n長さ修飾子のテスト\n\n\n");
	//char c = -12;
    //short s = 32000;
    //long l = 123456789L;
    //long long ll = 1234567890123LL;
    //size_t sz = 42;
    //long double ld = 3.141592653589793238L;

    //printf("char with hh: %hhd\n", c);           // 120
    //printf("short with h: %hd\n", s);            // 32000
    //printf("long with l: %ld\n", l);             // 123456789
    //printf("long long with ll: %lld\n", ll);     // 1234567890123
    //printf("size_t with z: %zu\n", sz);          // 42
    //printf("long double with L: %Lf\n", ld);     // 3.141593













}
