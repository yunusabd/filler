/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 15:19:07 by yabdulha          #+#    #+#             */
/*   Updated: 2018/10/20 17:51:45 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_position(t_filler *data, int x, int y)
{
	t_co	*tmp;
	int		overlap;

	overlap = 0;
	tmp = data->piece;
	output("check position");
	while (tmp)
	{
		if (map(data, tmp->x + x, tmp->y + y) == data->player && tmp->c == data->player)
		{
			output("overlap");
			overlap++;
		}
		else if (map(data, tmp->x + x, tmp->y + y) == '.' || tmp->c == '.')
			(void)0;
		else
			return (0);
		if (overlap > 1)
			return (0);
		tmp = tmp->next;
	}
	if (overlap == 1)
		return (1);
	return (0);
}

/*
**	Start from upper left corner. Try if overlap == 1. Move left and down.
*/

void	check_piece(t_filler *data)
{
	int		overlap;
	t_co	*tmp;
	t_co	*start;

	overlap = 0;
	tmp = data->piece;
	start = (t_co*)malloc(sizeof(*start));
	start->x = data->shortest->me->x - data->piece_size->x;
	start->y = data->shortest->me->y - data->piece_size->y;
	while (start->x <= data->shortest->me->x + data->piece_size->x
		&& (start->y < data->shortest->me->y + data->piece_size->y))
	{
		output("while");
		if (start->x == data->shortest->me->x + data->piece_size->x)
		{
			start->y++;
			start->x = data->shortest->me->x - data->piece_size->x;
		}
		if (check_position(data, start->x, start->y))
		{
			add_co(start->x, start->y, &data->solution, 0);
			output("huhuhuhu");
			ft_printf("12 14\n");
			return ;
		}
		start->x++;
	}
}
