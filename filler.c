/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:30:31 by yabdulha          #+#    #+#             */
/*   Updated: 2018/10/04 19:40:52 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	loop(char *line)
{
	while (get_next_line(0, &line) > -1)
	{
		if (line[0] == '$')
			ft_printf("12 14\n");
		else
		{
			ft_printf("line %s\n", line);
		}
	}
}

int	main(int ac, char **av)
{
	char		*line;
	t_filler	*data;

	line = NULL;

	data = (t_filler*)malloc(sizeof(*data));
	ft_bzero(data, sizeof(*data));
	if (get_next_line(0, &line) && line && ft_strlen(line) > 10
			&& !ft_strncmp(line, "$$$ exec p", 9)
			&& (line[10] == '1' || line[10] == '2'))
	{
		if (data->player == 0)
			data->player = (ft_strstr(line, av[0]) == ']') ? line[10] : 0;
		// loop gnl
		loop(line);
	}
}
