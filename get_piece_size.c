/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:01:55 by yabdulha          #+#    #+#             */
/*   Updated: 2018/10/17 15:13:07 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_piece_size(t_filler *data, char *line)
{
	add_co(ft_atoi(ft_strchr(line, ' ')), ft_atoi(ft_strrchr(line, ' '))
			, &data->piece_size, 0);
}
