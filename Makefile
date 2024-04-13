CC = cc
CFLAGS = -Wall -Wextra -Werror

CFILES := \
	ft_fractol.c \
	ft_complex_operations.c \
	ft_parse_input.c \
	ft_print_errors.c

OBJDIR := obj
OFILES := $(addprefix $(OBJDIR)/, $(CFILES:.c=.o))

NAME := fractol

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_FLAGS := -L$(LIBFT_DIR) -lft

MLX42_DIR := ./MLX42
MLX42 =	$(MLX42_DIR)/build/libmlx42.a
# flage have to be changed for macos
MLX42_FLAGS = -L$(MLX42_DIR)/build -lmlx42 -Iinclude -ldl -lglfw -pthread -lm

HEADER := ft_fractol.h

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJDIR) $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(OFILES) $(LIBFT_FLAGS) $(MLX42_FLAGS)

$(OBJDIR)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX42):
	if [ ! -d $(MLX42_DIR)/build ]; then \
		mkdir -p $(MLX42_DIR)/build; fi
	cd $(MLX42_DIR)/build && cmake .. && make -j4

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
