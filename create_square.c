/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:13:31 by yabdulha          #+#    #+#             */
/*   Updated: 2018/10/24 15:40:31 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
void	shrink(t_filler *data, int *inc, int *move)
{
}
*/

/*
**	Create a square surrounding the enemy player. Start from top left and create
**	points towards the bottom right.
*/

void	create_square(t_filler *data)
{
	t_co	*start;

	start = (t_co*)malloc(sizeof(*start));
	start->x = data->le;
	start->y = data->up;
	add_co(start->x, start->y, &data->square, 0);
	while (start->y < data->lo)
	{
		while (start->y != data->lo && start->x <= data->ri)
		{
			if (map(data, start->x, start->y) == '.'
				   || map(data, start->x, start->y) == data->player)
				start->x++;
			else
			{
				add_co(start->x - 1, start->y, &data->square, 0);
				start->x = data->le;
				break ;
			}
		}
		start->y++;
	}
	start->x = data->le;
	while (start->x <= data->ri)
	{
		while (start->x != data->ri && start->y >= data->up)
		{
			if (map(data, start->x, start->y) == '.'
				   || map(data, start->x, start->y) == data->player)
				start->y--;
			else
			{
				add_co(start->x, start->y + 1, &data->square, 0);
				start->y = data->up;
				break ;
			}
		}
		start->x++;
	}
	start->x = data->le;
	start->y = data->up;
	while (start->x <= data->ri)
	{
		while (start->x != data->ri && start->y <= data->lo)
		{
			if (map(data, start->x, start->y - 1) == '.'
				   || map(data, start->x, start->y) == data->player)
				start->y++;
			else
			{
				add_co(start->x, start->y - 1, &data->square, 0);
				start->y = data->up;
				break ;
			}
		}
		start->x++;
	}
	start->y = data->up;
	while (start->y < data->lo)
	{
		while (start->y != data->up && start->x <= data->ri)
		{
			if (map(data, start->x, start->y) == '.'
				   || map(data, start->x, start->y) == data->player)
				start->x--;
			else
			{
				add_co(start->x + 1, start->y, &data->square, 0);
				start->x = data->ri;
				break ;
			}
		}
		start->y++;
	}
}
