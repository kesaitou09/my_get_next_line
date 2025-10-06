NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCS = -I includes
AR = ar
ARFLAGS = rcs

SRCS = \
	srcs/ft_printf.c \
    srcs/parse.c \
    srcs/utils.c \
    srcs/num_core.c \
    srcs/format_helpers.c \
    srcs/print_char.c \
    srcs/print_str.c \
    srcs/print_ptr.c \
    srcs/di_helpers.c \
    srcs/print_di.c \
    srcs/u_common.c \
    srcs/print_u.c \
    srcs/print_x.c \
    srcs/print_o.c \
    srcs/f_helpers.c \
    srcs/print_f.c \


OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re