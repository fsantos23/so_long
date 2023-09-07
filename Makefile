SRCS		=	$(SRCS_DIR)/so_long.c 							\
					$(SRCS_DIR)/check_map.c 				\
					$(SRCS_DIR)/collect.c 				\
					$(SRCS_DIR)/exit.c 				\
					$(SRCS_DIR)/flood_fill.c 				\
					$(SRCS_DIR)/free_me.c 				\
					$(SRCS_DIR)/images.c 				\
					$(SRCS_DIR)/move.c 				\
					$(SRCS_DIR)/read_map.c 				\
					$(SRCS_DIR)/sprites.c 				\
					$(SRCS_DIR)/start_game.c 				\

SRCS_DIR = srcs

OBJS		=	$(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR	=	objs

NAME		=	so_long

CC			=	gcc

LIBFT		=	libft/libft.a
GNL			=	get_next_line/get_next_line.a
PRINTF	=	ft_printf/libftprintf.a

CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address

RM			=	rm -rf

MLX 		=	mlx_linux/libmlx.a

MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11

MLX_DIR		= 	mlx_linux

INC			=	-Iincludes -I/usr/include -Imlx_linux

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"



all:		$(NAME)

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):	$(MLX) $(OBJS)
			@make -C libft
			@make -C ft_printf
			@make -C get_next_line
			$(CC) $(SRCS) $(LIBFT) $(PRINTF) $(GNL) $(MLXFLAGS) $(CFLAGS) $(INC) -o $(NAME)

$(MLX):
		@make -C $(MLX_DIR)

clean:
			@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
			$(RM) $(OBJS)

fclean:		clean
			@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
			$(RM) $(NAME)
			$(RM) *.out
			$(RM) $(OBJS_DIR)
			@make fclean -C libft/
			@make fclean -C ft_printf/
			@make fclean -C get_next_line/

re:			fclean all

.PHONY:		all clean fclean re