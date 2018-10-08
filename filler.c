/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:30:31 by yabdulha          #+#    #+#             */
/*   Updated: 2018/10/08 11:38:46 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

//remove
#include <fcntl.h>

void	get_size(char *line, t_filler *data)
{
	FILE	*fd = fopen("./size", "w");

	fprintf(fd, "GETTING SIZE: %s\n", line);
	if (ft_strlen(line) > 10 && ft_strstr(line, "Plateau "))
	{
		data->y = ft_atoi(ft_strchr(line, ' '));
		data->x = ft_atoi(ft_strrchr(line, ' '));
		fprintf(fd, "data->x: %d\n", data->x);
		fprintf(fd, "data->y: %d\n", data->y);
	}
	fclose(fd);
}

void	loop(char *line, t_filler *data)
{
	FILE	*fd = fopen("./myoutput", "w");
	fprintf(fd, "looping %s\n", line);
	while (get_next_line(0, &line) > -1)
	{
		fprintf(fd, "loop line %s\n", line);
		if (!data->x)
			get_size(line, data);
		else if (line[0] == '$')
		{
			fprintf(fd, "line %s\n", line);
			ft_printf("12 14\n");
		}
		else
			fprintf(fd, "line %s\n", line);
	}
	fclose(fd);
}

int	main(int ac, char **av)
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
			data->player = (*(ft_strstr(line, av[0])) == ']') ? line[10] : 0;
		loop(line, data);
	}
}
