/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:30:31 by yabdulha          #+#    #+#             */
/*   Updated: 2018/10/08 17:53:40 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

//remove
#include <fcntl.h>

void	debug(t_filler *data, char *line, char *msg)
{
	FILE	*fd = fopen("./debug", "a");

	if (msg)
		fprintf(fd, "msg: %s, ", msg);
	fprintf(fd, "line: %s\n", line);
	fprintf(fd, "x: %d\n", data->max_x);
	fprintf(fd, "y: %d\n", data->max_y);
	fprintf(fd, "map: %s\n", data->map);
	fprintf(fd, "player: %c\n", data->player);

	fprintf(fd, "-------------\n");
	fclose(fd);
}

void	create_map(char *line, t_filler *data)
{
	if (ft_strlen(line) > 10 && ft_strstr(line, "Plateau "))
	{
		data->max_y = ft_atoi(ft_strchr(line, ' ')) - 1;
		data->max_x = ft_atoi(ft_strrchr(line, ' ')) - 1;
	}
	data->player = (data->player == '1') ? 'o' : 'x';
	data->opponent = (data->player == 'o') ? 'x' : 'o';
	data->map = (char*)malloc(sizeof(char) * (data->max_x + 1) * (data->max_y + 1));
	ft_bzero(data->map, sizeof(char) * (data->max_x + 1) * (data->max_y + 1));
}

void	insert_map(t_filler *data, int x, int y, char c)
{
	data->map[(data->max_x + 1) * x + y] = c;
}

char	map(t_filler *data, int x, int y)
{
	return (data->map[(data->max_x + 1) * x + y]);
}

void	parse_line(char *line, t_filler *data)
{
	int	i;
	int	start;

	start = ft_atoi(line);
	line = ft_strchr(line, ' ');
	i = 0;
	while (i <= (data->max_x + 1))
	{
		if (line[i] == 'o' || line[i] == 'O')
			insert_map(data, start, i, 'o');
		else if (line[i] == 'x' || line[i] == 'X')
			insert_map(data, start, i, 'x');
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
	while (i <= (data->max_y + 1) * (data->max_x + 1))
	{
		fprintf(fd, "%c", data->map[i]);
		if (i % (data->max_x + 1) == 0)
			fprintf(fd, "\n");
		i++;
	}
	fclose(fd);
}

void	loop(char *line, t_filler *data)
{
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] > 47 && line[0] < 58)
			parse_line(line, data);
		if (data->player && data->max_x == 0)
			create_map(line, data);
		ft_strdel(&line);
	}
	print_map(data);
	ft_printf("12 14\n");
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
	debug(data, line, "2akopsakdopas\n");
}
