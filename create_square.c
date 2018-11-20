/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:13:31 by yabdulha          #+#    #+#             */
/*   Updated: 2018/11/14 20:58:52 by yabdulha         ###   ########.fr       */
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

	start = (t_co*)malloc(sizeof(*start));
	start->x = data->le;
	start->y = data->up;
	add_co(start->x, start->y, &data->square, 0);
	while (start->y < data->lo)
	{
		if (map(data, start->x, start->y) == '.')
			add_co(start->x, start->y, &data->square, 0);
		start->y++;
	}
	start->x = data->le;
	while (start->x <= data->ri)
	{
		if (map(data, start->x, start->y) == '.')
			add_co(start->x, start->y, &data->square, 0);
		start->x++;
	}
	start->x = data->le;
	start->y = data->up;
	while (start->x < data->ri)
	{
		if (map(data, start->x, start->y) == '.')
			add_co(start->x, start->y, &data->square, 0);
		start->x++;
	}
	start->y = data->up;
	while (start->y <= data->lo)
	{
		if (map(data, start->x, start->y) == '.')
			add_co(start->x, start->y, &data->square, 0);
		start->y++;
	}
}
