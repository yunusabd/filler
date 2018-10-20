/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_co.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:49:50 by yabdulha          #+#    #+#             */
/*   Updated: 2018/10/20 15:11:23 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	add_co(int x, int y, t_co **head, char c)
{
	t_co	*new;

	new = (t_co*)malloc(sizeof(*new));
	new->x = x;
	new->y = y;
	new->c = c;
	new->next = *head;
	*head = new;
}
