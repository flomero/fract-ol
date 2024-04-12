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
HEADER := ft_fractol.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJDIR) $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(OFILES) -L$(LIBFT_DIR) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJDIR)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
