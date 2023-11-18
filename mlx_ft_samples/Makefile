# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 11:19:47 by pnopjira          #+#    #+#              #
#    Updated: 2023/11/16 10:06:25 by pnopjira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= sample
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -g -fsanitize=address -fsanitize=undefined 
M		:= make

SRC		:= sample.c

OBJS	:=	$(SRC:.c=.o)\

MLX		:= ./mlx/libmlx.a
INC		:= sample.h

%.o: %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@

all: sub-make $(NAME)

sub-make:
	$(M) -C mlx

$(NAME): $(OBJS) $(LIBFT) $(SRC) sub-make
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I mlx -L mlx -lmlx -framework OpenGL -framework AppKit

clean:
	@$(M) clean -C mlx
	@rm -rf *.o
	@echo "clean up all object!"
fclean:
	@$(M) fclean -C mlx
	@rm -rf *.o
	@echo "clean up all object!"
	@rm -rf $(NAME)
	@echo "fclean already"

re: fclean all
