# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 14:29:25 by pnopjira          #+#    #+#              #
#    Updated: 2023/09/07 17:44:01 by pnopjira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

NAME	=	minishell

INC		=	minishell.h

LIBMI	=	libminishell.a

SRC			=	main.c
INIT_SRC	= $(wildcard initiation/*.c)
# UTILS_SRC	= $(wildcard utiles/*.c)
# PIPEX_SRC	= $(wildcard pipeline/*.c)
# PARSER_SRC= $(wildcard parser/*.c)
# SIGN_SRC	= $(wildcard signals/*.c)
# READ_SRC	= $(wildcard readline/*.c)
# COMM_SRC	= $(wildcard bin/*.c)
# EXP_SRC	= $(wildcard expansion/*.c)
# RED_SRC	= $(wildcard redirection/*.c)
# PAR_SRC	= $(wildcard parentheses/*.c)

OBJ		=	$(SRC:%.c=%.o) $(INIT_SRC:%.c=%.o)
#			$(PARSER_SRC:%.c=%.o)
#			$(PIPEX_SRC:%.c=%.o)
#			$(UTILS_SRC:%.c=%.o)
#			$(COMM_SRC:%.c=%.o)
#			$(EXP_SRC:%.c=%.o)
#			$(SIGN_SRC:%.c=%.o)
#			$(PAR_SRC:%.c=%.o)
#			$(RED_SRC:%.c=%.o)
#			${READ_SRC:%.c=%.o}

%o: %c $(INC)
#	@cc $(FLAGS) -I/usr/local/opt/readline/include -I./ -L./ -lminishell -lreadline -c $< -o $@
#	@cc $(FLAGS) -I/usr/local/Cellar/readline/8.2.1/include -c $< -o $@

LIBFT_DIR = libft
LIBFT_LINK = $(LIBFT_DIR)/libft.a

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_LINK) $(LIBMI)
	ar rcs $(LIBMI) *.o initiation/*.o
# utiles/*.o pipeline/*.o parser/*.o\
	 signals/*.o readline/*.o bin/*.o expansion/*.o parentheses/*.o redirection/*.o
	@echo " "
	@echo " Make libminishell.a "
	@echo " "

	cc $(FLAGS) $(OBJ) $(INC) -I./ -L./ -lminishell -L /usr/local/opt/readline/lib -lreadline -o $(NAME)
#	@$(CC) $(FLAGS) $(OBJ) -I./ -L./ -lminishell -L /usr/local/opt/readline/lib -L /usr/local/opt/readline/include -lreadline  -o $(NAME)
#	-L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include -L./ -lminishell -L /usr/local/opt/readline/lib

	@echo "\033[0;34m   _   _      _ _         ___   __        __         _     _ "
	@echo "\033[0;34m  | | | | ___| | | ___   |_ _|__\ \      / /__  _ __| | __| |"
	@echo "\033[0;34m  | |_| |/ _ \ | |/ _ \   | |/ __\ \ /\ / / _ \| '__| |/ _  |"
	@echo "\033[0;33m  |  _  |  __/ | | (_) |  | |\__ \  V  V / (_) | |  | | (_| |"
	@echo "\033[0;33m  |_| |_|\___|_|_|\___/  |___|___/ \_/\_/ \___/|_|  |_|\__,_|"

all: $(NAME)

bonus:
	@echo "Hello Bonus"

clean:
	make clean -C $(LIBFT_DIR)
	@rm -f *.o
	@rm -rf initiation/*.o utiles/*.o pipeline/*.o parser/*.o signals/*.o\
	 readline/*.o bin/*.o expansion/*.o parentheses/*.o redirection/*.o
	@echo " "
	@echo "* clean compleate "
	@echo " "

fclean: clean
	make fclean -C $(LIBFT_DIR)
	@rm -f $(LIBMI)
	@rm -f $(NAME)
	@echo " "
	@echo "* fclean compleate"
	@echo " "

re: fclean all

.PHONY: clean fclean all re
