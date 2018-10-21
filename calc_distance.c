/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:00:04 by yabdulha          #+#    #+#             */
/*   Updated: 2018/10/17 12:56:00 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	add_dist(t_co *me, t_co *enemy, int dist, t_filler *data)
{
	t_dist	*new;

	if (!(new = ((t_dist*)malloc(sizeof(*new)))))
		exit(1);
	//TODO error handler
	new->me = me;
	new->enemy = enemy;
	new->dist = dist;
	new->next = data->dist;
	data->dist = new;
}

void	sort_distance(t_filler *data)
{
	t_dist	*tmp;

	tmp = data->dist;

}

void	calc_distance(t_filler *data)
{
	t_co	*tmp;
	t_co	*tmp2;

	tmp = data->square;
	tmp2 = data->my;
	while (tmp)
	{
		tmp2 = data->my;
		while (tmp2)
		{
			add_dist(tmp2, tmp,
			ABS(tmp->x - tmp2->x)
			+ ABS(tmp->y - tmp2->y), data);
			tmp2 = tmp2->next;	
		}
		tmp = tmp->next;
	}
}
