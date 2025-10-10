## =======================
## libftprintf.a Makefile
## =======================

## --- config ---
#NAME        := libftprintf.a
#CC          := cc
#CFLAGS      := -Wall -Wextra -Werror -Iincludes -I$(LIBFT_DIR)/includes
#AR          := ar
#ARFLAGS     := rcs
#RANLIB      := ranlib
#RM          := rm -f
#MKDIR_P     := mkdir -p

## --- paths ---
#LIBFT_DIR   := libft
#LIBFT       := $(LIBFT_DIR)/libft.a

#SRC_DIR     := srcs
#OBJ_DIR     := .obj

## 例: srcs/ に *.c がある想定
#SRCS        := $(wildcard $(SRC_DIR)/*.c)
#OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

## --- targets ---
#.PHONY: all clean fclean re

#all: $(NAME)

## libftprintf.a の中に libft.a も取り込みたいので、
## 1) 先に libft をビルド
## 2) libft.a を libftprintf.a にコピー
## 3) そこに自分の .o を追加して再アーカイブ
#$(NAME): $(OBJS) $(LIBFT)
#	@cp $(LIBFT) $(NAME)
#	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
#	@$(RANLIB) $(NAME)
#	@echo "Built $(NAME)"

## libft をサブディレクトリでビルド
#$(LIBFT):
#	@$(MAKE) -C $(LIBFT_DIR)

## オブジェクト生成
#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
#	$(CC) $(CFLAGS) -c $< -o $@

#$(OBJ_DIR):
#	@$(MKDIR_P) $(OBJ_DIR)

## 掃除
#clean:
#	$(RM) -r $(OBJ_DIR)
#	@$(MAKE) -C $(LIBFT_DIR) clean

#fclean: clean
#	$(RM) $(NAME)
#	@$(MAKE) -C $(LIBFT_DIR) fclean

#re: fclean all

# =======================
# libftprintf.a Makefile
# =======================

# ---- config ----
NAME        := libftprintf.a
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -Iincludes -I$(LIBFT_DIR)/includes
AR          := ar
ARFLAGS     := rcs
RANLIB      := ranlib
RM          := rm -f
MKDIR_P     := mkdir -p

# ---- paths ----
SRC_DIR     := srcs
OBJ_DIR     := .obj

LIBFT_DIR   := libft
LIBFT_A     := $(LIBFT_DIR)/libft.a

# ---- sources ----
# 例）mandatoryを *.c、bonusを *_bonus.c で管理している想定
SRCS_ALL    := $(wildcard $(SRC_DIR)/*.c)
SRCS_M      := $(filter-out %_bonus.c,$(SRCS_ALL))
SRCS_B      := $(filter %_bonus.c,$(SRCS_ALL))

OBJS_M      := $(SRCS_M:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_B      := $(SRCS_B:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# スタンプ（bonusビルド済み印）
BONUS_STAMP := .bonus_built

# ---- phony ----
.PHONY: all bonus clean fclean re

# デフォルト：mandatoryだけで libftprintf.a を作る
all: $(NAME)

# libftprintf.a（mandatory）
$(NAME): $(OBJS_M) $(LIBFT_A)
	@cp $(LIBFT_A) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS_M)
	@$(RANLIB) $(NAME)
	@$(RM) $(BONUS_STAMP)
	@echo "Built $(NAME) (mandatory only)"

# bonus：mandatory + bonus をまとめてアーカイブ
# スタンプを作って「実際に生成された」ことを make に示し、無限リリンクを避ける
bonus: $(OBJS_M) $(OBJS_B) $(LIBFT_A)
	@cp $(LIBFT_A) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS_M) $(OBJS_B)
	@$(RANLIB) $(NAME)
	@touch $(BONUS_STAMP)
	@echo "Built $(NAME) (with bonus)"

# libft を先にビルド
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

# コンパイル規則
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@$(MKDIR_P) $(OBJ_DIR)

# 掃除
clean:
	$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_STAMP)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all




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


#NAME      = libftprintf.a
#CC        = cc
#CFLAGS    = -Wall -Wextra -Werror
#INCS      = -I includes -I libft/includes
#AR        = ar
#ARFLAGS   = rcs
#LIBFTDIR  = libft
#LIBFT     = $(LIBFTDIR)/libft.a

#SRCS =  srcs/ft_printf.c \
#        srcs/libft_utils.c \
#        srcs/ouxx_helper.c \
#        srcs/parse.c \
#        srcs/print.c \
#        srcs/utils.c\
#        srcs/print_csper.c \
#		srcs/print_di.c\
#        srcs/print_ouxx.c \
#		srcs/print_p.c \

#OBJS = $(SRCS:.c=.o)

#all: $(NAME)

#$(LIBFT):
#	$(MAKE) -C $(LIBFTDIR) TMPDIR=/tmp

#$(NAME): $(OBJS) $(LIBFT)
#	$(AR) $(ARFLAGS) $@ $(OBJS)
#	ranlib $@

#%.o: %.c
#	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

#clean:
#	rm -f $(OBJS)
#	$(MAKE) -C $(LIBFTDIR) clean

#fclean: clean
#	rm -f $(NAME)
#	$(MAKE) -C $(LIBFTDIR) fclean

#re: fclean all

#.PHONY: all clean fclean re
