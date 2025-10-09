#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <sys/types.h>

typedef struct s_window
{
	size_t	width;
	size_t	height;
}	t_window;

typedef struct s_graph
{
	t_window	window;	
}	t_graph;

t_graph *create_graph_data(void);
void	destroy_graph_data(t_graph *graph_data);

#endif
