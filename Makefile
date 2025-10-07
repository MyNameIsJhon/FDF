# ************************************
# *            FdF - Makefile         *
# ************************************

NAME        := fdf

CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g
INCLUDES    := -Iincludes -Imlx -Ilibft/includes

SRC_DIR     := srcs
OBJ_DIR     := obj
LIBFT_DIR   := libft
MLX_DIR     := mlx

LIBFT_A     := $(LIBFT_DIR)/libft.a
MLX_A       := $(MLX_DIR)/libmlx.a
LDFLAGS     := -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lz

SRCS        := \
	$(SRC_DIR)/controls.c \
	$(SRC_DIR)/drawing.c \
	$(SRC_DIR)/exit.c \
	$(SRC_DIR)/fdf.c \
	$(SRC_DIR)/filling.c \
	$(SRC_DIR)/gradient.c \
	$(SRC_DIR)/map_dimensions.c \
	$(SRC_DIR)/map_display.c \
	$(SRC_DIR)/map_reader.c \
	$(SRC_DIR)/menu_display.c \
	$(SRC_DIR)/tests.c 


OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

RM          := rm -f
MKDIR_P     := mkdir -p

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT_A) $(MLX_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c includes/fdf.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	$(MKDIR_P) $(OBJ_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
