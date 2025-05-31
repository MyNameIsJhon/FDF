# === CONFIG ===

NAME        := fdf
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g -fsanitize=undefined
RM          := rm -f
MKDIR_P     := mkdir -p

# === PATHS ===

LIBFT_DIR   := libft
MLX_DIR     := mlx
OBJ_DIR     := obj
SRC_DIR     := srcs

SRC         := $(wildcard $(SRC_DIR)/*.c)
OBJ         := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o)

INCLUDES    := -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR)/includes

BOLD        := \033[1m
GREEN       := \033[0;32m
YELLOW      := \033[0;33m
CYAN        := \033[0;36m
RESET       := \033[0m

.PHONY: all prebuild clean fclean re

all: prebuild $(NAME)

prebuild:
	@echo "$(CYAN)[🔁] Compilation préalable de LIBFT et MLX...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@echo "$(GREEN)[✅] Libft et MinilibX compilés.$(RESET)"

$(NAME): $(OBJ)
	@echo "$(CYAN)[🔗] Linking de l'exécutable $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) \
		-L$(LIBFT_DIR) -lft \
		-L$(MLX_DIR) -lmlx \
		-framework OpenGL -framework AppKit \
		-o $@
	@echo "$(GREEN)[✅] Build complete: $(NAME)$(RESET)"

$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR_P) $(dir $@)
	@echo "$(YELLOW)[⚙️] Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# === CLEANUP ===
clean:
	@echo "$(CYAN)[🧹] Nettoyage des objets fdf...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@echo "$(CYAN)[🧹] Clean Libft et MinilibX...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@echo "$(CYAN)[💥] Suppression de l'exécutable $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(CYAN)[💥] fclean Libft et MinilibX...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean	# MLX n'a généralement pas de fclean, juste clean.

re: fclean all
