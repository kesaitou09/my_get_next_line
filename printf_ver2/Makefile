#NAME = libftprintf.a

#CC = cc
#CFLAGS = -Wall -Werror -Wextra
#INCS = -I includes
#AR = ar
#ARFLAGS = rcs

#LIBFTDIR = libft
#LIBFT     = $(LIBFTDIR)/libft.a
#TMPDIR    = .libft_objs

#SRCS = 	srcs/ft_printf.c\
#		srcs/libft_utils.c\
#		srcs/ouxx_helper.c\
#		srcs/parse.c\
#		srcs/print_csper.c\
#		srcs/print_ouxx.c\
#		srcs/print.c\
#		srcs/utils.c\


#OBJS = $(SRCS:.c=.o)


#all : $(NAME)

#$(LIBFT):
#	$(MAKE) -C $(LIBFTDIR)
	
#$(NAME): $(OBJS) $(LIBFT)
#	@rm -rf $(TMPDIR)
#	@mkdir -p $(TMPDIR)
#	@cd $(TMPDIR) && $(AR) x ../$(LIBFT)
#	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(TMPDIR)/*.o
#	@rm -rf $(TMPDIR)
#	@ranlib $(NAME)

#%.o : %.c
#	$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	
#clean:
#	rm -f $(OBJS)
#	$(MAKE) -C $(LIBFTDIR) clean

#fclean: clean
#	rm -f $(NAME)
#	$(MAKE) -C $(LIBFTDIR) fclean

#re: fclean all

#.PHONY: all clean fclean re


NAME      = libftprintf.a
CC        = cc
CFLAGS    = -Wall -Wextra -Werror
INCS      = -I includes -I libft/includes
AR        = ar
ARFLAGS   = rcs
LIBFTDIR  = libft
LIBFT     = $(LIBFTDIR)/libft.a

SRCS =  srcs/ft_printf.c \
        srcs/libft_utils.c \
        srcs/ouxx_helper.c \
        srcs/parse.c \
        srcs/print_csper.c \
        srcs/print_ouxx.c \
        srcs/print.c \
        srcs/utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR) TMPDIR=/tmp

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $(ARFLAGS) $@ $(OBJS)
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
