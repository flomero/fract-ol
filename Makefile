CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast

CFILES := \
	ft_fractol.c \
	maths/ft_complex_operations.c \
	maths/ft_math_utils.c \
	parsing/ft_parse_input.c \
	parsing/ft_init_fractol.c \
	errors/ft_print_errors.c \
	input_handlers/ft_key_handler.c \
	input_handlers/ft_mouse_handler.c \
	input_handlers/ft_scroll_handler.c \
	rendering/ft_mlx_handler.c \
	rendering/ft_colors.c \
	rendering/ft_colormodes.c \
	fractals/ft_mandelbrot.c \
	fractals/ft_julia.c \
	fractals/ft_burningship.c \
	overlay/ft_overlay.c \
	overlay/ft_overlay_dynamic.c \

CFILES := $(addprefix src/, $(CFILES))

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

INC_DIR := includes
HEADER := ft_fractol.h ft_typedefs.h ft_defines.h
HEADER := $(addprefix $(INC_DIR)/, $(HEADER))

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJDIR) $(OFILES)
	@echo "$(YELLOW)Compiling fractol...$(NC)"
	@$(CC) $(CFLAGS) -o $@ $(OFILES) $(LIBFT_FLAGS) $(MLX42_FLAGS)


$(OBJDIR)/%.o: %.c $(HEADER)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I. -I$(INC_DIR) -c $< -o $@

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

norm:
	norminette src includes

.PHONY: all clean fclean re norm


# colors:
RED = \033[0;31m
YELLOW = \033[0;33m
NC = \033[0m
