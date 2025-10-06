#include "../includes/ft_printf.h"

static const char *parse_length(const char *s, t_fmt *f);
const char *fp_parse(const char *s, t_fmt *f);
static const char *parse_flags(const char *s, t_fmt *f);
static const char *parse_num(const char *s, int *out);

/* 既存の fp_init_fmt に長さ修飾子初期化を追加 */
static void fp_init_fmt(t_fmt *f)
{
	f->flag_minus = 0;
	f->flag_plus = 0;
	f->flag_space = 0;
	f->flag_zero = 0;
	f->flag_hash = 0;
	f->width = 0;
	f->precision = 0;
	f->prec_set = 0;
	f->spec = 0;
	f->len_l = 0;
	f->len_cap_l = 0;
}

static const char *parse_length(const char *s, t_fmt *f)
{
	if (*s == 'L')
	{
		f->len_cap_l = 1;
		return (s + 1);
	}
	if (*s == 'l')
	{
		f->len_l = 1;
		return (s + 1);
	}
	return (s);
}

const char *fp_parse(const char *s, t_fmt *f)
{
	fp_init_fmt(f);
	s = parse_flags(s, f);
	s = parse_num(s, &f->width);
	if (*s == '.')
	{
		f->prec_set = 1;
		s = parse_num(s + 1, &f->precision);
	}
	s = parse_length(s, f);																															 /* NEW */
	if (*s == 'c' || *s == 's' || *s == 'p' || *s == 'd' || *s == 'i' || *s == 'u' || *s == 'o' || *s == 'x' || *s == 'X' || *s == 'f' || *s == '%') /* NEW: 'f' 追加 */
		f->spec = *s++;
	return (s);
}

static const char *parse_flags(const char *s, t_fmt *f)
{
	while (*s == '-' || *s == '+' || *s == ' ' || *s == '0' || *s == '#')
	{
		if (*s == '-')
			f->flag_minus = 1;
		else if (*s == '+')
			f->flag_plus = 1;
		else if (*s == ' ')
			f->flag_space = 1;
		else if (*s == '0')
			f->flag_zero = 1;
		else
			f->flag_hash = 1;
		s++;
	}
	return (s);
}

static const char *parse_num(const char *s, int *out)
{
	int v;

	v = 0;
	while (*s >= '0' && *s <= '9')
	{
		v = v * 10 + (*s - '0');
		s++;
	}
	*out = v;
	return (s);
}
