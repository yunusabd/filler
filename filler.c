/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:30:31 by yabdulha          #+#    #+#             */
/*   Updated: 2018/10/17 17:15:30 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

//remove
#include <fcntl.h>

void	init_co(t_filler *data)
{
	data->up = -1;
	data->lo = -1;
	data->le = -1;
	data->ri = -1;
}

void	create_map(t_filler *data, char *line)
{
	if (ft_strlen(line) > 10 && ft_strstr(line, "Plateau "))
	{
		data->max_y = ft_atoi(ft_strchr(line, ' '));
		data->max_x = ft_atoi(ft_strrchr(line, ' '));
	}
	data->map = (char*)malloc(sizeof(char) * (data->max_x + 1)
			* (data->max_y + 1) + data->max_y);
	ft_bzero(data->map, sizeof(char) * (data->max_x + 1)
			* (data->max_y + 1) + data->max_y);
}

void	insert_map(t_filler *data, int x, int y, char c)
{
	data->map[data->max_x * x + y] = c;
}

char	map(t_filler *data, int x, int y)
{
	if (x <= data->max_x && y <= data->max_y)
		return (data->map[data->max_x * x + y]);
	else
		return (-1);
}

/*
**	Get four points (upper, lower, left, right) for the maximum extent of the opponent.
*/

void	get_opponent(t_filler *data, int y, int x)
{
	if (data->up == -1 || y <= data->up)
		data->up = (y == 0) ? 0 : y - 1;
	if (data->lo == -1 || y >= data->lo)
		data->lo = (y == 0) ? 0 : y + 1;
	if (data->le == -1 || x <= data->le)
		data->le = (x == 0) ? 0 : x - 1;
	if (data->ri == -1 || x >= data->ri)
		data->ri = (x == 0) ? 0 : x + 1;
}

void	parse_line(t_filler *data, char *line)
{
	int	i;
	int	start;

	start = ft_atoi(line);
	line = ft_strchr(line, ' ');
	line++;
	i = 0;
	while (i <= data->max_x)
	{
		if (line[i] == data->player || ft_tolower(line[i]) == data->player)
		{
			insert_map(data, start, i, data->player);
			add_co(i, start, &data->my, 0);
		}
		else if (line[i] == data->opponent || ft_tolower(line[i]) == data->opponent)
		{
			insert_map(data, start, i, data->opponent);
			add_co(i, start, &data->enemy, 0);
			get_opponent(data, start, i);
		}
		else
			insert_map(data, start, i, '.');
		i++;
	}
}

void	print_map(t_filler *data)
{
	int	i;
	FILE	*fd = fopen("./map", "a");

	i = 0;
	fprintf(fd, "printing map");
	fclose(fd);
	fd = fopen("./map", "a");
	while (i <= data->max_y * data->max_x)
	{
		fprintf(fd, "%c", data->map[i]);
		if (i % data->max_x == 0)
			fprintf(fd, "\n");
		i++;
	}
	fclose(fd);
}

int		check_piece(t_filler *data, int x, int y)
{
	int		overlap;
	t_co	*tmp;

	overlap = 0;
	tmp = data->piece;
	while (tmp)
	{
		if (tmp->c == '.' || (map(data, tmp->x + x, tmp->y + y) == '.'))
			continue ;
		else if (map(data, tmp->x + x, tmp->y + x) == data->player)
			overlap++;
		else
			return (0);
		if (overlap > 1)
			break ;
		tmp = tmp->next;
	}
	if (overlap == 1)
		return (1);
	return (0);
}

void	get_piece(t_filler *data, char *line)
{
	int		i;
	int		j;

	i = 0;
	while (get_next_line(0, &line) > 1)
	{
		j = 0;
		while (line[j])
		{
			add_co(j, i, &(data->piece), line[j]);
			j++;
		}
		i++;
	}
}

void	loop(char *line, t_filler *data)
{
	int	res;

	while ((res = get_next_line(0, &line)) > 0)
	{
		if (line[0] > 47 && line[0] < 58)
			parse_line(data, line);
		else if (ft_strncmp(line, "Piece", 5) == 0)
		{
			get_piece_size(data, line);
			get_piece(data, line);
			break ;
		}
		if (data->player && data->max_x == 0)
		{
			create_map(data, line);
			data->player = (data->player == '1') ? 'o' : 'x';
			data->opponent = (data->player == 'o') ? 'x' : 'o';
			init_co(data);
		}
	}
}

int		main(int ac, char **av)
{
	char		*line;
	t_filler	*data;

	line = NULL;
	(void)ac;
	data = (t_filler*)malloc(sizeof(*data));
	ft_bzero(data, sizeof(*data));
	if (get_next_line(0, &line) && line && ft_strlen(line) > 10
			&& !ft_strncmp(line, "$$$ exec p", 9)
			&& (line[10] == '1' || line[10] == '2'))
	{
		if (data->player == 0)
			data->player = ((ft_strstr(line, av[0]))) ? line[10] : 0;
		loop(line, data);
	}
	ft_printf("12 14\n");
	create_square(data);
	calc_distance(data);
	print(data, line, "enf od loop\n");
}
