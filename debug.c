/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:25:27 by yabdulha          #+#    #+#             */
/*   Updated: 2018/10/24 15:32:09 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

//remove
#include <fcntl.h>

void	debug(t_filler *data, char *line, char *msg)
{
	FILE	*fd = fopen("./debug", "a");
	int		i = 0;
	t_co	*tmp;
	t_dist	*d;
	t_co	*my;

/*	if (msg)
		fprintf(fd, "msg: %s, ", msg);
	fprintf(fd, "line: %s\n", line);
	fprintf(fd, "x: %d\n", data->max_x);
	fprintf(fd, "y: %d\n", data->max_y);
	while (i < (data->max_x) * (data->max_y))
	{
		if (i % data->max_x == 0)
			fprintf(fd, "\n%3.3d ", i / data->max_x);
		fprintf(fd, "%c", (data->map[i]) ? data->map[i] : '?');
		i++;
	}
	fprintf(fd, "\n");
	fprintf(fd, "player: %c\n", data->player);
	fprintf(fd, "opponent: %c\n", data->opponent);
	*/
	fprintf(fd, "up: %d, down: %d, left: %d, right: %d\n", data->up, data->lo, data->le, data->ri);
	tmp = data->square;
	while (tmp)
	{
		fprintf(fd, "square point: %d %d\n", tmp->x, tmp->y);
		tmp = tmp->next;
	}
	if (data->shortest)
		fprintf(fd, "shortest: %d\n", data->shortest->dist);
	d = data->dist;
	while (d)
	{
		fprintf(fd, "distance: %d, me: %d %d enemy %d %d\n", d->dist, d->me->x, d->me->y, d->enemy->x, d->enemy->y);
		d = d->next;
	}
	fprintf(fd, "\n");
	my = data->my;
	while (my)
	{
		fprintf(fd, "my point: %d %d\n", my->x, my->y);
		my = my->next;
	}
	fprintf(fd, "-------------\n");
	my = data->piece;
	while (my)
	{
		fprintf(fd, "piece point: %d %d [%c]\n", my->x, my->y, my->c);
		my = my->next;
	}
	fprintf(fd, "piece size: %d %d\n", data->piece_size->x, data->piece_size->y);

	fclose(fd);
}

void	output(char *msg)
{
	FILE    *fd = fopen("dot", "a");

	if (msg)
		fprintf(fd, "debug msg: %s\n", msg);
	fclose(fd);
}

void	output_c(char msg)
{
	FILE    *fd = fopen("dot", "a");

	if (msg)
		fprintf(fd, "debug msg: %c\n", msg);
	fclose(fd);
}



void	print(t_filler *data, char *line, char *msg)
{
	int    fd = open("/dev/ttys003", O_RDWR);

	write(fd, "sasd\n", 5);
	int		i = 0;
	t_co	*tmp;
	t_dist	*d;
	t_co	*my;
	t_co	*piece;

	if (msg)
		dprintf(fd, "msg: %s, ", msg);
	dprintf(fd, "line: %s\n", line);
	dprintf(fd, "x: %d\n", data->max_x);
	dprintf(fd, "y: %d\n", data->max_y);
	while (i < (data->max_x) * (data->max_y))
	{
		if (i % data->max_x == 0)
			dprintf(fd, "\n%3.3d ", i / data->max_x);
		dprintf(fd, "%c", (data->map[i]) ? data->map[i] : '?');
		i++;
	}
	dprintf(fd, "\n");
	dprintf(fd, "player: %c\n", data->player);
	dprintf(fd, "opponent: %c\n", data->opponent);
	dprintf(fd, "up: %d, down: %d, left: %d, right: %d\n", data->up, data->lo, data->le, data->ri);
	tmp = data->square;
	while (tmp)
	{
		dprintf(fd, "square point: %d %d\n", tmp->x, tmp->y);
		tmp = tmp->next;
	}
	if (data->shortest)
		dprintf(fd, "shortest: %d\n", data->shortest->dist);
	d = data->dist;
	while (d)
	{
		dprintf(fd, "distance: %d, me: %d %d enemy %d %d\n", d->dist, d->me->x, d->me->y, d->enemy->x, d->enemy->y);
		d = d->next;
	}
	dprintf(fd, "\n");
	my = data->my;
	while (my)
	{
		dprintf(fd, "my point: %d %d\n", my->x, my->y);
		my = my->next;
	}
	dprintf(fd, "-------------\n");
	my = data->piece;
	while (my)
	{
		dprintf(fd, "piece point: %d %d [%c]\n", my->x, my->y, my->c);
		my = my->next;
	}
	printf("-------------\n");
	close(fd);
}
