/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:13:31 by yabdulha          #+#    #+#             */
/*   Updated: 2018/10/17 15:11:49 by yabdulha         ###   ########.fr       */
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
	while (start->y < data->lo)
		add_co(start->x, start->y++, &data->square, 0);
	while (start->x <= data->ri)
		add_co(start->x++, start->y, &data->square, 0);
	start->x = data->le + 1;
	start->y = data->up;
	while (start->x < data->ri)
		add_co(start->x++, start->y, &data->square, 0);
	while (start->y <= data->lo - 1)
		add_co(start->x, start->y++, &data->square, 0);
	start->x = data->le;
	start->y = data->up;
}
