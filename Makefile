# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/09 11:34:07 by yabdulha          #+#    #+#              #
#    Updated: 2018/11/20 18:48:02 by yabdulha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

all: $(NAME)

$(NAME):
	gcc filler.c libft/libft.a libft/get_next_line.c read_piece.c add_co.c create_square.c debug.c calc_distance.c get_piece_size.c check_piece.c calc_score.c sandbox/merge_sort.c
