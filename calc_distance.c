/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:00:04 by yabdulha          #+#    #+#             */
/*   Updated: 2018/10/22 17:38:13 by yabdulha         ###   ########.fr       */
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

int		check_sorted(t_dist *head)
{
	t_dist	*tmp;

	tmp = head;
	while (tmp && tmp->next)
	{
		if (tmp->dist > tmp->next->dist)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	swap(t_filler *data, t_dist *first, t_dist *second)
{
	t_dist	*tmp;

	if (first == data->dist)
		data->dist = second;
	first->next = second->next;
	second->next = first;
}

void	sort_distance(t_filler *data)
{
	t_dist	*tmp;
	t_dist	*before = NULL;

	tmp = data->dist;
	while (tmp && tmp->next)
	{
		if (tmp->dist > 0 && tmp->dist > tmp->next->dist)
		{
			if (before)
				before->next = tmp->next;
			swap(data, tmp, tmp->next);
			tmp = data->dist;
		}
		else
		{
			before = tmp;
			tmp = tmp->next;
		}
	}
	if (!(check_sorted(data->dist)))
		sort_distance(data);
}

void	calc_distance(t_filler *data)
{
	t_co	*tmp;
	t_co	*tmp2;
	t_dist	*d;

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
