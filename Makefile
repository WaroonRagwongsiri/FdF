# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/04 20:20:04 by waroonwork@       #+#    #+#              #
#    Updated: 2025/10/04 22:39:59 by waroonwork@      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	fdf

CC				:=	cc
CFLAG			:=	-Wall -Wextra -Werror -g3
LDFLAGS			:=	-ldl -lglfw -pthread -lm

# Path for file
INC_DIR			:=	includes/
SRCS_DIR		:=	srcs/
OBJS_DIR		:=	objs/

# Srcs file
SRCS_FILES		:=	main.c

SRCS			:=	$(SRCS_FILES:%.c=$(SRCS_DIR)%.c)
OBJS			:=	$(SRCS_FILES:%.c=$(OBJS_DIR)%.o)

# Libft
LIBFT_DIR		:=	libft/
LIBFT_INC_DIR	:=	$(LIBFT_DIR)/includes
LIBFT			:=	libft.a

# MLX42
MLX42_DIR		:=	MLX42/
MLX42_INC_DIR	:=	$(MLX42_DIR)/include/MLX42/
MLX42			:=	libmlx42.a

# Main Rule
all				:	$(NAME) Makefile

$(NAME)			:	$(OBJS) $(LIBFT) $(MLX42) Makefile
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42) $(LDFLAGS) -o $@

$(OBJS_DIR)%.o	: $(SRCS_DIR)%.c | $(MLX42) $(OBJS_DIR)
	$(CC) $(CFLAG) -c $< -o $@ \
	-I $(INC_DIR) -I $(MLX42_INC_DIR) -I $(LIBFT_INC_DIR)

$(OBJS_DIR)		:
	@mkdir -p $@

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
	rm -rf $(OBJS_DIR)
	rm -rf $(LIBFT) $(MLX42)
	rm -rf $(MLX42_DIR)
	@make -C libft fclean

fclean			:	clean
	rm -f $(NAME)

re				:	fclean all

bonus			:	all

.PHONY			:	all clean fclean re bonus