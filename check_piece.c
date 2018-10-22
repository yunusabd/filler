/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 15:19:07 by yabdulha          #+#    #+#             */
/*   Updated: 2018/10/22 17:36:56 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_around(t_filler *data, int x, int y)
{
	if (!(map(data, x + 1, y) == '.'
				|| map(data, x + 1, y + 1) == '.'
				|| map(data, x + 1, y - 1) == '.'
				|| map(data, x - 1, y) == '.'
				|| map(data, x - 1, y + 1) == '.'
				|| map(data, x - 1, y - 1) == '.'
				|| map(data, x, y + 1) == '.'
				|| map(data, x, y - 1) == '.'
			)
	   )
		return (0);
	return (1);

}

static int	check_position(t_filler *data, int x, int y)
{
	t_co	*tmp;
	int		overlap;

	overlap = 0;
	tmp = data->piece;
	output("check position");
	if (!(check_around(data, x, y)))
	{
		output("full");
		return (0);
	}
	while (tmp)
	{
		if (map(data, tmp->x + x, tmp->y + y) == data->player && tmp->c == '*')
			overlap++;
		else if (!(map(data, tmp->x + x, tmp->y + y) == '.' || tmp->c == '.'))
			return (0);
		if (overlap > 1)
			return (0);
		tmp = tmp->next;
	}
	output("ended checking");
	if (overlap == 1)
		return (1);
	return (0);
}

/*
**	Start from upper left corner. Try if overlap == 1. Move left and down.
*/

static int	try_piece(t_filler *data, t_dist *shortest)
{
	int		overlap;
	int	max_x;
	int	max_y;
	int	max;
	t_co	*tmp;
	t_co	*start;

	overlap = 0;
	tmp = data->piece;
	char *nb = ft_itoa(shortest->me->x);
	output(ft_strjoin("shortest x: ", nb));
	nb = ft_itoa(shortest->me->y);
	output(ft_strjoin("shortest y", nb));
	start = (t_co*)malloc(sizeof(t_co));
	max_x = shortest->me->x + data->piece_size->x;
	max_y = shortest->me->y + data->piece_size->y;
	start->x = shortest->me->x - data->piece_size->x;
	start->y = shortest->me->y - data->piece_size->y;
	while (start->x <= max_x && start->y <= max_y)
	{
		if (check_position(data, start->x, start->y))
		{
			ft_printf("%d %d\n", start->y, start->x);
			return (1);
		}
		start->y++;
		if (start->y == max_y)
		{
			start->x++;
			start->y = shortest->me->y - data->piece_size->y;
		}

	}
	return (0);
}

void	check_pieces(t_filler *data)
{
	t_dist	*tmp;

	tmp = data->dist;
	while (tmp && try_piece(data, tmp) == 0)
		tmp = tmp->next;
	if (!tmp)
	{
		output("no result");
		ft_printf("0 0\n");
	}
	output("tried all positions");
}
