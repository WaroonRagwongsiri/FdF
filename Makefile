# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/04 20:20:04 by waroonwork@       #+#    #+#              #
#    Updated: 2025/10/04 20:31:42 by waroonwork@      ###   ########.fr        #
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

all				:	$(NAME) Makefile

$(NAME)			:	$(OBJS) Makefile
	@make -C libft
	@cp libft/libft.a .
	$(CC) $(CFLAG) -I$(INC_DIR) $(OBJS) libft.a -o $@

$(OBJS_DIR)%.o	: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAG) -I$(INC_DIR) -c $< -o $@

$(OBJS_DIR)		:
	@mkdir -p $@

clean			:
	rm -rf $(OBJS_DIR)
	@make -C libft clean

fclean			:	clean
	rm -f $(NAME) libft.a
	@make -C libft fclean

re				:	fclean all

bonus			:	all

.PHONY			:	all clean fclean re bonus