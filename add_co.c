/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_co.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:49:50 by yabdulha          #+#    #+#             */
/*   Updated: 2018/10/17 14:25:14 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	add_co(int x, int y, t_co **head, char c)
{
	t_co	*new;

	new = (t_co*)malloc(sizeof(*new));
	new->x = x;
	new->y = y;
	new->next = *head;
	*head = new;
}
