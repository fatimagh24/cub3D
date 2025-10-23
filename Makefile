NAME= cub3D
CC= cc 
CFLAGS= -Wall -Wextra -Werror
MLX_PATH = ../minilibx-linux
MLX_LIB = -L $(MLX_PATH) -lmlx -lXext -lX11


LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

src= game_cleanup.c parse_map.c error_checking.c\
	clean_map.c main.c open_win.c render.c\
	movement_utils1.c movement_utils2.c hooks.c initialize.c error_check_two.c\
	fill_map.c check_player_path.c raycasting.c raycast_utils.c\
	init_player.c\

SRC_DIR = srcs
OBJ_DIR = obj

INCLUDES = includes

SRC = $(addprefix $(SRC_DIR)/, $(src))
OBJ = $(addprefix $(OBJ_DIR)/, $(src:%.c=%.o))

all: $(NAME)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR) all


$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCLUDES) -lm $(OBJ) $(LIBFT) $(MLX_LIB) -o $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean: 
	rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) 

re: fclean all

.PHONY: all re clean fclean libft
