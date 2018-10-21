#ifndef FT_FILLER
# define FT_FILLER

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include "libft/includes/get_next_line.h"

# define ABS(x) ((x < 0) ? -(x) : (x))

typedef	struct	s_co
{
	int			x;
	int			y;
	char		c;
	struct s_co	*next;
}				t_co;

typedef	struct	s_dist
{
	t_co			*me;
	t_co			*enemy;
	int				dist;
	struct s_dist	*next;
}				t_dist;

typedef struct	s_filler
{
	int		max_x;
	int		max_y;
	char	player;
	char	opponent;
	char	*map;
	int		up;
	int		lo;
	int		le;
	int		ri;
	t_co	*my;
	t_co	*enemy;
	t_co	*square;
	t_dist	*dist;
	t_dist	*shortest;
	t_co	*piece;
	t_co	*piece_size;
	t_co	*solution;
}				t_filler;

/* ------------ DEBUG --------------- */
void	debug(t_filler *data, char *line, char *msg);
void	output(char *msg);
void	output_c(char msg);
/* ----------- /DEBUG --------------- */

void	print(t_filler *data, char *line, char *msg);
void	print(t_filler *data, char *line, char *msg);
void	get_piece_size(t_filler *data, char *line);
void	print_map(t_filler *data);
void	add_co(int x, int y, t_co **head, char c);
void	create_square(t_filler *data);
void	calc_distance(t_filler *data);
void	check_piece(t_filler *data);
char	map(t_filler *data, int x, int y);
# endif
