# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvievill <rvievill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/03 18:09:10 by rvievill          #+#    #+#              #
#    Updated: 2017/04/17 15:28:36 by bngo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
NC		= \033[0m

CC		= gcc
NAME	= GameOfLife
CFLAGS	= -g -Wall -Werror -Wextra -fsanitize=address
CPATH	= sources/
OPATH	= objects/
HPATH	= libft/
INC		= $(addprefix -I, $(HPATH))
CFILES	= main.c \
		  error.c \
		  input_options.c \
		  seed_gen.c

OFILES	= $(CFILES:.c=.o)

HFILES	= includes/gol.h

OBJ		= $(addprefix $(OPATH), $(OFILES))

.PHONY: all clean fclean name re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ${HPATH} && make clean -C ${HPATH}
	@$(CC) $(CFLAGS) $(OBJ) ${HPATH}/libft.a -o $(NAME)
	@printf "${GREEN}Compilation finished, GameOfLife executable ready.${NC}\n"

$(OPATH)%.o: $(CPATH)%.c $(HFILES)
	@mkdir -p $(OPATH)
	@$(CC) -g -Wall -Werror -Wextra  $(INC) $< -c -o $@

clean:
	@make -C libft clean
	@rm -rf $(OBJ)
	@printf "${RED}GameOfLife object files deleted.${NC}\n"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@printf "${RED}GameOfLife executable deleted.${NC}\n"

re: fclean all
