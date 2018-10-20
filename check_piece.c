/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 15:19:07 by yabdulha          #+#    #+#             */
/*   Updated: 2018/10/20 16:15:20 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_position(t_filler *data, int x, int y)
{
	t_co	*tmp;
	int		overlap;

	overlap = 0;
	tmp = data->piece;
	while (tmp)
	{
		if (map(data, tmp->x, tmp->y) == data->player)
			overlap++;
		else if (map(data, tmp->x, tmp->y) == '.')
			(void)0;
		else
			return (0);
		if (overlap > 1)
			return (0);
		tmp = tmp->next;
	}
	if (!tmp && overlap == 1)
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
	char *nb1 = ft_itoa(data->shortest->me->x);
	char *nb2 = ft_itoa(data->shortest->me->y);
	output(nb1);
	output(nb2);

	nb1 = ft_itoa(start->x);
	nb2 = ft_itoa(start->y);
	output(nb1);
	output(nb2);
	while (start->x < data->shortest->me->x + data->piece_size->x &&
			start->y < data->shortest->me->y + data->piece_size->y)
		if (check_position(data, start->x++, start->y))
		{
			char *nb1 = ft_itoa(start->x);
			char *nb2 = ft_itoa(start->y);
			output(nb1);
			output(nb2);
			ft_printf("%d %d\n", start->x, start->y);
		}
}
