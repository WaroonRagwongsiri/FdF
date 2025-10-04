# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/04 20:20:04 by waroonwork@       #+#    #+#              #
#    Updated: 2025/10/04 21:52:54 by waroonwork@      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	fdf

CC				:=	cc
CFLAG			:=	-Wall -Wextra -Werror -g3

INC_DIR			:=	includes/
SRCS_DIR		:=	srcs/
OBJS_DIR		:=	objs/

SRCS_FILES		:=	main.c

SRCS			:=	$(SRCS_FILES:%.c=$(SRCS_DIR)%.c)
OBJS			:=	$(SRCS_FILES:%.c=$(OBJS_DIR)%.o)

LIBFT_DIR		:=	libft
LIBFT			:=	libft.a

MLX42_DIR		:=	MLX42/
MLX42			:=	libmlx42.a

# Main Rule
all				:	$(NAME) Makefile

$(NAME)			:	$(OBJS) $(LIBFT) Makefile
	$(CC) $(CFLAG) -I$(INC_DIR) $(OBJS) $(LIBFT) -o $@

$(LIBFT)		:
	@make -C libft
	@cp libft/libft.a .

$(OBJS_DIR)%.o	: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAG) -I$(INC_DIR) -c $< -o $@

$(OBJS_DIR)		:
	@mkdir -p $@

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
	rm -rf $(MLX42_DIR)
	rm $(LIBFT) $(MLX42)
	@make -C libft clean

fclean			:	clean
	rm -f $(NAME)
	@make -C libft fclean

re				:	fclean all

bonus			:	all

.PHONY			:	all clean fclean re bonus