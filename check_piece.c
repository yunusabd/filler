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
		if (map(data, tmp->x + x, tmp->y + y) == data->player && tmp->c == '*')
			overlap++;
		else if (map(data, tmp->x + x, tmp->y + y) == '.' || tmp->c == '.')
		{
			output("dot");
		}
		else
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

void	check_piece(t_filler *data)
{
	int		overlap;
	int	max_x;
	int	max_y;
	int	max;
	t_co	*tmp;
	t_co	*start;

	overlap = 0;
	tmp = data->piece;
	char *nb = ft_itoa(data->shortest->me->x);
	output(ft_strjoin("shortest x: ", nb));
	nb = ft_itoa(data->shortest->me->y);
	output(ft_strjoin("shortest y", nb));
	start = (t_co*)malloc(sizeof(t_co));
	max_x = data->shortest->me->x + data->piece_size->x - 1;
	max_y = data->shortest->me->y + data->piece_size->y - 1;
	start->x = data->shortest->me->x - data->piece_size->x + 1;
	start->y = data->shortest->me->y - data->piece_size->y + 1;
	while (start->x <= max_x && start->y <= max_y)
	{
		if (start->x == max_x)
		{
			start->y++;
			start->x = data->shortest->me->x - data->piece_size->x;
		}
		nb = ft_itoa(data->piece_size->x);
		output(ft_strjoin("piece_size->x: ", nb));
		nb = ft_itoa(data->piece_size->y);
		output(ft_strjoin("data->piece_size->y", nb));
		nb = ft_itoa(start->x);
		output(ft_strjoin("start->x: ", nb));
		nb = ft_itoa(start->y);
		output(ft_strjoin("start->y", nb));
		if (check_position(data, start->x, start->y))
		{
			output("found");
			ft_printf("%d %d\n", start->y, start->x);
			return ;
		}
		start->x++;
	}
}
