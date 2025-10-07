# ************************************
# *           Libft - Makefile        *
# ************************************

# ---- Project ----
NAME        := libft.a

# ---- Tools ----
CC          := cc
AR          := ar rcs
RANLIB      := ranlib
RM          := rm -f
MKDIR_P     := mkdir -p

# ---- Flags ----
CFLAGS      := -Wall -Wextra -Werror -g
CPPFLAGS    := -Iincludes

# ---- Dirs ----
OBJ_DIR     := obj
LIBFT_DIR   := libft
PRINTF_DIR  := ft_printf
ARENA_DIR   := arena_allocator
FILE_DIR    := fileft
VEC_DIR     := vector

# ---- Sources (explicit, no wildcard) ----
LIBFT_SRCS  := \
	$(LIBFT_DIR)/freestrs.c \
	$(LIBFT_DIR)/freestrss.c \
	$(LIBFT_DIR)/ft_abs_f.c \
	$(LIBFT_DIR)/ft_abs.c \
	$(LIBFT_DIR)/ft_atoi_hex.c \
	$(LIBFT_DIR)/ft_atoi.c \
	$(LIBFT_DIR)/ft_bzero.c \
	$(LIBFT_DIR)/ft_calloc.c \
	$(LIBFT_DIR)/ft_cos.c \
	$(LIBFT_DIR)/ft_count_char.c \
	$(LIBFT_DIR)/ft_free.c \
	$(LIBFT_DIR)/ft_hexlen_l.c \
	$(LIBFT_DIR)/ft_hexlen.c \
	$(LIBFT_DIR)/ft_icmp.c \
	$(LIBFT_DIR)/ft_isalnum.c \
	$(LIBFT_DIR)/ft_isalpha.c \
	$(LIBFT_DIR)/ft_isascii.c \
	$(LIBFT_DIR)/ft_isdigit.c \
	$(LIBFT_DIR)/ft_isincharset.c \
	$(LIBFT_DIR)/ft_islower.c \
	$(LIBFT_DIR)/ft_isprint.c \
	$(LIBFT_DIR)/ft_isupper.c \
	$(LIBFT_DIR)/ft_itoa.c \
	$(LIBFT_DIR)/ft_lstadd_back.c \
	$(LIBFT_DIR)/ft_lstadd_front.c \
	$(LIBFT_DIR)/ft_lstclear.c \
	$(LIBFT_DIR)/ft_lstdelone.c \
	$(LIBFT_DIR)/ft_lstiter.c \
	$(LIBFT_DIR)/ft_lstlast.c \
	$(LIBFT_DIR)/ft_lstmap.c \
	$(LIBFT_DIR)/ft_lstnew_chr.c \
	$(LIBFT_DIR)/ft_lstnew_i.c \
	$(LIBFT_DIR)/ft_lstnew_long.c \
	$(LIBFT_DIR)/ft_lstnew.c \
	$(LIBFT_DIR)/ft_lstsize.c \
	$(LIBFT_DIR)/ft_malloc.c \
	$(LIBFT_DIR)/ft_max.c \
	$(LIBFT_DIR)/ft_memchr.c \
	$(LIBFT_DIR)/ft_memcmp.c \
	$(LIBFT_DIR)/ft_memcpy.c \
	$(LIBFT_DIR)/ft_memmove.c \
	$(LIBFT_DIR)/ft_memset.c \
	$(LIBFT_DIR)/ft_nbrlen_u.c \
	$(LIBFT_DIR)/ft_nbrlen.c \
	$(LIBFT_DIR)/ft_putchar.c \
	$(LIBFT_DIR)/ft_puterror.c \
	$(LIBFT_DIR)/ft_putnbr_hex_ulong.c \
	$(LIBFT_DIR)/ft_putnbr_hex.c \
	$(LIBFT_DIR)/ft_putnbr_unsigned.c \
	$(LIBFT_DIR)/ft_putnbr.c \
	$(LIBFT_DIR)/ft_putstr.c \
	$(LIBFT_DIR)/ft_realloc.c \
	$(LIBFT_DIR)/ft_revstr.c \
	$(LIBFT_DIR)/ft_sgn_f.c \
	$(LIBFT_DIR)/ft_sgn.c \
	$(LIBFT_DIR)/ft_sign_f.c \
	$(LIBFT_DIR)/ft_sin.c \
	$(LIBFT_DIR)/ft_sizeof.c \
	$(LIBFT_DIR)/ft_split_charset.c \
	$(LIBFT_DIR)/ft_split.c \
	$(LIBFT_DIR)/ft_strappend.c \
	$(LIBFT_DIR)/ft_strchr.c \
	$(LIBFT_DIR)/ft_strdup.c \
	$(LIBFT_DIR)/ft_strisdigit.c \
	$(LIBFT_DIR)/ft_striteri.c \
	$(LIBFT_DIR)/ft_strjoin.c \
	$(LIBFT_DIR)/ft_strlcat.c \
	$(LIBFT_DIR)/ft_strlcpy.c \
	$(LIBFT_DIR)/ft_strlen.c \
	$(LIBFT_DIR)/ft_strmapi.c \
	$(LIBFT_DIR)/ft_strncmp.c \
	$(LIBFT_DIR)/ft_strnstr.c \
	$(LIBFT_DIR)/ft_strrchr.c \
	$(LIBFT_DIR)/ft_strslen.c \
	$(LIBFT_DIR)/ft_strsslen.c \
	$(LIBFT_DIR)/ft_strtrim.c \
	$(LIBFT_DIR)/ft_substr.c \
	$(LIBFT_DIR)/ft_swap_p.c \
	$(LIBFT_DIR)/ft_swap.c \
	$(LIBFT_DIR)/ft_tolower.c \
	$(LIBFT_DIR)/ft_toupper.c \
	$(LIBFT_DIR)/read_to_charset.c

PRINTF_SRCS := \
	$(PRINTF_DIR)/ft_printf.c \
	$(PRINTF_DIR)/handler_base10.c \
	$(PRINTF_DIR)/handler_chr.c \
	$(PRINTF_DIR)/handler_lower_hex.c \
	$(PRINTF_DIR)/handler_percent.c \
	$(PRINTF_DIR)/handler_pointer.c \
	$(PRINTF_DIR)/handler_string.c \
	$(PRINTF_DIR)/handler_unsigned.c \
	$(PRINTF_DIR)/handler_upper_hex.c \
	$(PRINTF_DIR)/p_builtins.c

FILE_SRCS   := \
	$(FILE_DIR)/ft_countline_fd.c \
	$(FILE_DIR)/ft_putchar_fd.c \
	$(FILE_DIR)/ft_putendl_fd.c \
	$(FILE_DIR)/ft_putnbr_fd.c \
	$(FILE_DIR)/ft_putstr_fd.c \
	$(FILE_DIR)/get_file.c \
	$(FILE_DIR)/get_next_line.c

ARENA_SRCS  := \
	$(ARENA_DIR)/arena_allocator.c

VECTOR_SRCS := \
	$(VEC_DIR)/vector.c

SRCS        := $(LIBFT_SRCS) $(PRINTF_SRCS) $(FILE_SRCS) $(ARENA_SRCS) $(VECTOR_SRCS)

# ---- Objects ----
LIBFT_OBJS  := $(LIBFT_SRCS:$(LIBFT_DIR)/%.c=$(OBJ_DIR)/$(LIBFT_DIR)/%.o)
PRINTF_OBJS := $(PRINTF_SRCS:$(PRINTF_DIR)/%.c=$(OBJ_DIR)/$(PRINTF_DIR)/%.o)
FILE_OBJS   := $(FILE_SRCS:$(FILE_DIR)/%.c=$(OBJ_DIR)/$(FILE_DIR)/%.o)
ARENA_OBJS  := $(ARENA_SRCS:$(ARENA_DIR)/%.c=$(OBJ_DIR)/$(ARENA_DIR)/%.o)
VECTOR_OBJS := $(VECTOR_SRCS:$(VEC_DIR)/%.c=$(OBJ_DIR)/$(VEC_DIR)/%.o)

OBJS        := $(LIBFT_OBJS) $(PRINTF_OBJS) $(FILE_OBJS) $(ARENA_OBJS) $(VECTOR_OBJS)

# ---- Phony ----
.PHONY: all clean fclean re

# ---- Build ----
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

# ---- Compile rules (one per subtree) ----
$(OBJ_DIR)/$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c | $(OBJ_DIR)/$(LIBFT_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/$(PRINTF_DIR)/%.o: $(PRINTF_DIR)/%.c | $(OBJ_DIR)/$(PRINTF_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/$(FILE_DIR)/%.o: $(FILE_DIR)/%.c | $(OBJ_DIR)/$(FILE_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/$(ARENA_DIR)/%.o: $(ARENA_DIR)/%.c | $(OBJ_DIR)/$(ARENA_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/$(VEC_DIR)/%.o: $(VEC_DIR)/%.c | $(OBJ_DIR)/$(VEC_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# ---- Obj dirs ----
$(OBJ_DIR):
	$(MKDIR_P) $(OBJ_DIR)

$(OBJ_DIR)/$(LIBFT_DIR): | $(OBJ_DIR)
	$(MKDIR_P) $(OBJ_DIR)/$(LIBFT_DIR)

$(OBJ_DIR)/$(PRINTF_DIR): | $(OBJ_DIR)
	$(MKDIR_P) $(OBJ_DIR)/$(PRINTF_DIR)

$(OBJ_DIR)/$(FILE_DIR): | $(OBJ_DIR)
	$(MKDIR_P) $(OBJ_DIR)/$(FILE_DIR)

$(OBJ_DIR)/$(ARENA_DIR): | $(OBJ_DIR)
	$(MKDIR_P) $(OBJ_DIR)/$(ARENA_DIR)

$(OBJ_DIR)/$(VEC_DIR): | $(OBJ_DIR)
	$(MKDIR_P) $(OBJ_DIR)/$(VEC_DIR)

# ---- Clean ----
clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
