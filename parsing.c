/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:30:31 by yabdulha          #+#    #+#             */
/*   Updated: 2018/10/16 15:23:30 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

//remove
#include <fcntl.h>

void	create_map(char *line, t_filler *data)
{
	if (ft_strlen(line) > 10 && ft_strstr(line, "Plateau "))
	{
		data->max_y = ft_atoi(ft_strchr(line, ' '));
		data->max_x = ft_atoi(ft_strrchr(line, ' '));
	}
	data->player = (data->player == '1') ? 'o' : 'x';
	data->opponent = (data->player == 'o') ? 'x' : 'o';
	data->map = (char*)malloc(sizeof(char) * (data->max_x + 1) * (data->max_y + 1) + data->max_y);
	ft_bzero(data->map, sizeof(char) * (data->max_x + 1) * (data->max_y + 1));
}

void	insert_map(t_filler *data, int x, int y, char c)
{
	data->map[data->max_x * x + y] = c;
}

char	map(t_filler *data, int x, int y)
{
	return (data->map[data->max_x * x + y]);
}

void	check_opponent(t_filler *data, char *line)
{

}

void	parse_line(t_filler *data, char *line)
{
	int	i;
	int	start;

	start = ft_atoi(line);
	line = ft_strchr(line, ' ');
	i = 0;
	while (i <= data->max_x)
	{
		check_opponent(data, line);
		if (line[i] == 'o' || line[i] == 'O')
			insert_map(data, start, i, 'o');
		else if (line[i] == 'x' || line[i] == 'X')
			insert_map(data, start, i, 'x');
		else
			insert_map(data, start, i, '.');
		i++;
	}
}

void	loop(char *line, t_filler *data)
{
	while (get_next_line(0, &line))
	{
		if (line[0] > 47 && line[0] < 58)
			parse_line(data, line);
		if (data->player && data->max_x == 0)
			create_map(line, data);
		ft_strdel(&line);
	}
	print_map(data);
	ft_printf("12 14\n");
}
