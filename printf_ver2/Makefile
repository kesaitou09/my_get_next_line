NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCS = -I includes
AR = ar
ARFLAGS = rcs

LIBFTDIR = libft
SRCS = \
	


OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFTDIR)/libft.a


all : $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)
	
$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re