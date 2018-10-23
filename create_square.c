/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:13:31 by yabdulha          #+#    #+#             */
/*   Updated: 2018/10/23 11:51:13 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Create a square surrounding the enemy player. Start from top left and create
**	points towards the bottom right.
*/

void	create_square(t_filler *data)
{
	t_co	*start;
	int		x;
	int		y;

	start = (t_co*)malloc(sizeof(*start));
	start->x = data->le;
	start->y = data->up;
	while (start->y > -1 && start->y < data->lo)
	{
		if (map(data, start->x, start->y) == '.')
			add_co(start->x, start->y, &data->square, 0);
		start->y++;
	}
	while (start->x > -1 && start->x <= data->ri)
	{
		if (map(data, start->x, start->y) == '.')
			add_co(start->x, start->y, &data->square, 0);
		start->x++;
	}
	start->x = data->le;
	start->y = data->up;
	while (start->x > -1 && start->x < data->ri)
	{
		if (map(data, start->x, start->y) == '.')
			add_co(start->x, start->y, &data->square, 0);
		start->x++;
	}
	while (start->y > -1 && start->y <= data->lo - 1)
	{
		if (map(data, start->x, start->y) == '.')
			add_co(start->x, start->y, &data->square, 0);
		start->y++;
	}
	start->x = data->le;
	start->y = data->up;
}
