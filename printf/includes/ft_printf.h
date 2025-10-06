#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

#define ERROR -1
typedef struct s_fmt
{
	int flag_minus;
	int flag_plus;
	int flag_space;
	int flag_zero;
	int flag_hash;
	int width;
	int precision;
	int prec_set;
	char spec;
	int len_l;
	int len_cap_l;
} t_fmt;

typedef struct s_uox_ctx
{
	unsigned long long u;
	const char *px;
	int plen;
	int dlen;
	int zeros;
	int ws;
	int w;
	int t;
} t_uox_ctx;

typedef struct s_fctx
{
	long double val;
	int neg;
	int prec;
	int force_dot;
	unsigned long long ip;
	unsigned long long frac;
	unsigned long long scale;
	int ilen;
	int sign;
	int zeros;
	int ws;
	int w;
	int t;
} t_fctx;

/* public */
int ft_printf(const char *fmt, ...);

/* parse */
const char *fp_parse(const char *s, t_fmt *f);

/* io utils */
int ft_putchar(char c);
int ft_putstr(char *s);
int fp_putnstr(const char *s, int n);
int fp_putnchar(char c, int n);
size_t fp_strlen(const char *s);

/* number core */
int put_number_base(unsigned int u, char *base);
int put_number_base_ull(unsigned long long u, char *base);
int fp_count_digits_ull(unsigned long long u, int base);

/* spec handlers */
int fp_print_char(t_fmt *f, int c);
int fp_print_str(t_fmt *f, const char *s);
int fp_print_ptr(t_fmt *f, void *p);
int fp_print_di(t_fmt *f, int v);
int fp_print_u(t_fmt *f, unsigned int v);
int fp_print_o(t_fmt *f, unsigned int v);
int fp_print_x(t_fmt *f, unsigned int v, int up);

/* tiny helpers */
int fp_max(int a, int b);
int fp_is_digit(char c);

/* DI helpers */
int fp_di_sign_char(t_fmt *f, int neg);
void fp_di_calc_pad(t_fmt *f, int sign, int dlen, int *zeros, int *ws);
int fp_di_emit_left(t_fmt *f, int ws, int sign, int zeros);
int fp_di_emit_tail(t_fmt *f, int ws);
int fp_di_abs_and_len(t_fmt *f, int v, unsigned long long *u, int *neg);

/* U/O/X helpers */
void fp_u_calc_pad(t_fmt *f, int plen, int dlen, int *zeros, int *ws);
int fp_u_emit(t_fmt *f, const char *px, int plen, int zeros, int ws);

/* %f プロトタイプとヘルパを追加 */
int fp_print_f(t_fmt *f, va_list *ap); /* NEW */

/* float helpers（NEW） */
int fp_pow10_ull(int p, unsigned long long *out);
int fp_f_sign_char(t_fmt *f, int neg);
void fp_f_calc_pad(t_fmt *f, int sign, int ilen, int prec,
				   int force_dot, int *zeros, int *ws);
int fp_f_emit_frac(int prec, int force_dot, unsigned long long frac);
#endif
