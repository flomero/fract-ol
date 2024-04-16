CC = cc
CFLAGS = -Wall -Wextra -Werror

CFILES := \
	ft_fractol.c \
	ft_complex_operations.c \
	ft_parse_input.c \
	ft_print_errors.c \
	ft_key_handler.c

OBJDIR := obj
OFILES := $(addprefix $(OBJDIR)/, $(CFILES:.c=.o))

NAME := fractol

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_FLAGS := -L$(LIBFT_DIR) -lft

MLX42_DIR := ./MLX42
MLX42 =	$(MLX42_DIR)/build/libmlx42.a
MLX42_FLAGS =
ifeq ($(shell uname),Darwin)
	MLX42_FLAGS = -L$(MLX42_DIR)/build -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw
else ifeq ($(shell uname),Linux)
	MLX42_FLAGS = -L$(MLX42_DIR)/build -lmlx42 -Iinclude -ldl -lglfw -pthread -lm
endif


HEADER := ft_fractol.h

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJDIR) $(OFILES)
	@echo "$(YELLOW)Compiling fractol...$(NC)"
	@$(CC) $(CFLAGS) -o $@ $(OFILES) $(LIBFT_FLAGS) $(MLX42_FLAGS)


$(OBJDIR)/%.o: %.c $(HEADER)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJDIR):
	@echo "$(YELLOW)Creating obj directory...$(NC)"
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(NC)"
	if [ ! -d $(LIBFT_DIR) ]; then mkdir -p $(LIBFT_DIR); fi
	@git submodule update --remote --init -q
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX42):
	@echo "$(YELLOW)Compiling mlx42...$(NC)"
	if [ ! -d $(MLX42_DIR)/build ]; then mkdir -p $(MLX42_DIR)/build; fi
	@git submodule update --remote --init -q
	@cd $(MLX42_DIR)/build && cmake .. && make -j4

clean:
	@echo "$(RED)Removing object files...$(NC)"
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX42_DIR)/build clean

fclean: clean
	@echo "$(RED)Removing binary files...$(NC)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re


# colors:
RED = \033[0;31m
YELLOW = \033[0;33m
NC = \033[0m
