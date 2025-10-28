# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/04 20:20:04 by waroonwork@       #+#    #+#              #
#    Updated: 2025/10/28 20:06:11 by waragwon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	fdf

CC				:=	cc
CFLAG			:=	-Wall -Wextra -Werror -g3
LDFLAGS			:=	-ldl -lglfw -pthread -lm

# Path for file
INC_DIR			:=	includes/
SRCS_DIR		:=	srcs/

# Srcs file
SRCS_FILES		:=	main.c \
					utils/exit_error.c utils/valid_file.c utils/free_map.c \
					utils/malloc_grid.c utils/max_min.c utils/clear_gnl.c \
					utils/logs.c utils/str_to_upper.c \
					gnl/get_next_line.c gnl/get_next_line_utils.c \
					parser/parse_dim.c parser/parse_map.c \
					fdf/init_fdf.c \
					maps/fill_map.c maps/map_utils.c maps/color.c \
					maps/draw.c maps/draw_menu.c maps/rotate.c \
					maps/corlor_inter.c \
					hook/hook_utils.c hook/hook.c \

SRCS			:=	$(SRCS_FILES:%.c=$(SRCS_DIR)%.c)
OBJS			:=	$(SRCS:%.c=%.o)

# Libft
LIBFT_DIR		:=	libft/
LIBFT_INC_DIR	:=	$(LIBFT_DIR)/includes
LIBFT			:=	libft.a

# MLX42
MLX42_DIR		:=	MLX42/
MLX42_INC_DIR	:=	$(MLX42_DIR)/include/
MLX42			:=	libmlx42.a

# Main Rule
all				:	$(NAME) Makefile

$(NAME)			:	$(OBJS) $(LIBFT) $(MLX42) Makefile
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42) $(LDFLAGS) -o $@

%.o				:	%.c | $(MLX42)
	$(CC) $(CFLAG) -c $< -o $@ \
	-I $(INC_DIR) -I $(MLX42_INC_DIR) -I $(LIBFT_INC_DIR)

# Libft
libft			:	$(LIBFT)

$(LIBFT)		:
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)libft.a .

# MLX42 for this project
mlx				:	$(MLX42)

$(MLX42)		:	$(MLX42_DIR)
	@cd $(MLX42_DIR) && cmake -B build
	@cd $(MLX42_DIR) && cmake --build build -j4
	@cp $(MLX42_DIR)/build/$(MLX42) .

$(MLX42_DIR)	:
	@git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR)

# Other required rules
clean			:
	rm -f $(OBJS)
	@make -C libft fclean

fclean			:	clean
	rm -f $(NAME)
	rm -rf $(LIBFT) $(MLX42)
	rm -rf $(MLX42_DIR)

re				:	fclean all

bonus			:	all

.PHONY			:	all clean fclean re bonus libft mlx