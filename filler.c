/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:30:31 by yabdulha          #+#    #+#             */
/*   Updated: 2018/11/12 19:35:32 by yabdulha         ###   ########.fr       */
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
	data->map = (int*)malloc(sizeof(int) * data->max_x
			* data->max_y + data->max_y);
	ft_bzero(data->map, sizeof(char) * data->max_x
			* data->max_y + data->max_y);
}

void	insert_map(t_filler *data, int x, int y, int n)
{
	data->map[data->max_x * x + y] = n;
}

int		map(t_filler *data, int x, int y)
{
	if (x >= 0 && y >=0 && x < data->max_x && y < data->max_y)
		return (data->map[data->max_x * x + y]);
	else
		return (-1);
}

/*
**	Get four points (upper, lower, left, right) for the maximum
**	extent of the opponent.
*/

void	get_opponent(t_filler *data, int y, int x)
{
	output(ft_strjoin(ft_strjoin("square calc, x: ", ft_itoa(x)), ft_strjoin(" y: ", ft_itoa(y))));
	if (y >= 0 && (y < data->up || data->up == -1))
		data->up = (y == 0) ? 0 : y;
	if (y >= 0 && (y > data->lo || data->lo == -1))
		data->lo = (y == 0) ? 0 : y;
	if (x >= 0 && (x < data->le || data->le == -1))
		data->le = (x == 0) ? 0 : x;
	if (x >= 0 && (x > data->ri || data->ri == -1))
		data->ri = (x == 0) ? 0 : x;
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
			insert_map(data, i, start, data->player);
			add_co(i, start, &data->my, 0);
		}
		else if (line[i] == data->opponent || ft_tolower(line[i]) == data->opponent)
		{
			insert_map(data, i, start, data->opponent);
			add_co(i, start, &data->enemy, 0);
			get_opponent(data, start, i);
		}
		else
			insert_map(data, i, start, '.');
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

/*
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
*/

void	free_co(t_filler *data, t_co **head)
{
	t_co	*tmp;
	t_co	*tmp2;

	tmp = *head;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*head = NULL;
}

void	get_piece(t_filler *data, char *line)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->piece_size->y)
	{
		get_next_line(0, &line);
		j = 0;
		while (line && line[j])
		{
			if (line[j] == '*')
				add_co(j, i, &(data->piece), line[j]);
			j++;
		}
		i++;
	}
}

void	print_square(t_filler *data)
{
	t_co	*tmp;

	tmp = data->square;
	while (tmp)
	{
		output(ft_strjoin(ft_strjoin("square x: ", ft_itoa(tmp->x)), 
					ft_strjoin(", y: ", ft_itoa(tmp->y))));
		tmp = tmp->next;
	}
}

void	loop(char *line, t_filler *data)
{
	int	res;
	int	i = 0;

	while ((res = get_next_line(0, &line)) > 0)
	{
		char *nb = ft_itoa(i++);
		output(ft_strjoin("reading line ", nb));
		if (line[0] > 47 && line[0] < 58)
			parse_line(data, line);
		else if (ft_strncmp(line, "Piece", 5) == 0)
		{
			get_piece_size(data, line);
			get_piece(data, line);
			create_square(data);
			print_square(data);
			calc_distance(data);
			sort_distance(data);
			debug(data, NULL, NULL);
			check_pieces(data);
			free_co(data, &data->piece);
			free_co(data, &data->square);
			free_co(data, &data->piece_size);
			free_co(data, &data->solution);
			free_co(data, &data->my);
			free_co(data, &data->enemy);
			free(data->dist);
			data->dist = NULL;
			free(data->shortest);
			data->shortest = NULL;
			output("all freed");
			continue ;
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
}
