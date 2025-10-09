#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <sys/types.h>
# include "raylib.h"

typedef struct s_data	t_data;

typedef struct s_window
{
	size_t	width;
	size_t	height;
}	t_window;

typedef struct s_text
{
	char	*str;
	size_t	font_size;
	size_t	size;
}	t_text;

typedef struct s_graph
{
	t_window	window;	
	t_text		header;
}	t_graph;

t_graph *create_graph_data(void);
void	destroy_graph_data(t_graph *graph_data);
void	init(t_data *data, t_graph *graph_data);

#endif
