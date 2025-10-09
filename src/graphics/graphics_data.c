#include <stdlib.h>
#include "graphics.h"
#include "raylib.h"

t_graph	*create_graph_data(void)
{
	t_graph *graph_data;

	graph_data = malloc(sizeof(t_graph));
	if (graph_data == NULL)
		return (NULL);
	return (graph_data);
}


void	destroy_graph_data(t_graph *graph_data)
{
	if (graph_data != NULL)
		free(graph_data);
}
