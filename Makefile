# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 12:01:51 by liafigli          #+#    #+#              #
#    Updated: 2021/07/01 14:21:37 by liafigli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

AOUT	=	push_swap

NAME	=	push_swap.a

INCLUDE = 	includes/push_swap.h

FOLDER  = srcs

FILES	=	push_swap.c warnings.c commands.c swaps.c swaps2.c commands2.c
SRCS	= $(addprefix ${FOLDER}/, ${FILES})
FILESS	=	 $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(FILESS)
	@$(MAKE) -C ./libft
	@cp libft/libft.a $(NAME)
	@gcc $(FLAGS) $(SRCS) libft/srcs/*.c -o $(AOUT)
	@ar -rc $(NAME) $^

.c.o:
	@gcc $(FLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(FILESS)
	@$(MAKE) clean -C ./libft

fclean: clean
	@$(RM) $(AOUT)
	@$(RM) includes/push_swap.h.gch
	@$(RM) $(NAME)
	@$(MAKE) fclean -C ./libft

re: fclean all