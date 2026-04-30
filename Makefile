NAME		= fdf
BONUS_NAME	= fdf_bonus

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -I./include -I./minilibx-linux -I./libft

SRC_DIR		= srcs
BONUS_DIR	= bonus
OBJ_DIR		= objs
BONUS_OBJ_DIR = objs_bonus
MLX_DIR		= minilibx-linux
LIBFT_DIR	= libft

SRCS		=	$(SRC_DIR)/fdf.c \
				$(SRC_DIR)/events.c \
				$(SRC_DIR)/map.c \
				$(SRC_DIR)/map_utils.c \
				$(SRC_DIR)/parse.c \
				$(SRC_DIR)/points.c \
				$(SRC_DIR)/draw.c \
				$(SRC_DIR)/utils.c \
				$(SRC_DIR)/error.c

BONUS_SRCS	=	$(BONUS_DIR)/fdf_bonus.c \
				$(BONUS_DIR)/hooks_bonus.c \
				$(BONUS_DIR)/events_bonus.c \
				$(BONUS_DIR)/map_bonus.c \
				$(BONUS_DIR)/map_utils_bonus.c \
				$(BONUS_DIR)/parse_bonus.c \
				$(BONUS_DIR)/points_bonus.c \
				$(BONUS_DIR)/draw_bonus.c \
				$(BONUS_DIR)/color_bonus.c \
				$(BONUS_DIR)/rotation_bonus.c \
				$(BONUS_DIR)/translation_scaling_bonus.c \
				$(BONUS_DIR)/matrix_bonus.c \
				$(BONUS_DIR)/utils_bonus.c \
				$(BONUS_DIR)/error_bonus.c

# Object files
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS	= $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

# MinilibX
MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# Libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft

# Colors for pretty output
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
BLUE		= \033[0;34m
RESET		= \033[0m

# Rules
all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(MLX) $(LIBFT) $(BONUS_OBJS)
	@echo "$(YELLOW)Linking $(BONUS_NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(BONUS_NAME)
	@echo "$(YELLOW)✓ $(BONUS_NAME) created successfully!$(RESET)"

# Compile srcs
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile bonus
$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile MinilibX
$(MLX):
	@echo "$(GREEN)Building MinilibX...$(RESET)"
	@make -s -C $(MLX_DIR)
	@echo "$(GREEN)✓ MinilibX built$(RESET)"

# Compile libft
$(LIBFT):
	@echo "$(GREEN)Building libft...$(RESET)"
	@make -s -C $(LIBFT_DIR)
	@echo "$(GREEN)✓ libft built$(RESET)"

# Delete objs
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@make -s -C $(MLX_DIR) clean
	@make -s -C $(LIBFT_DIR) clean
	@echo "$(RED)✓ Object files cleaned$(RESET)"

fclean: clean
	@echo "$(RED)Removing executables...$(RESET)"
	@rm -f $(NAME) $(BONUS_NAME)
	@make -s -C $(LIBFT_DIR) fclean
	@echo "$(RED)✓ Executables removed$(RESET)"

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus