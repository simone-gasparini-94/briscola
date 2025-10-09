#include <stdlib.h>
#include "graphics.h"
#include "raylib.h"

t_grph	*create_graph_data(void)
{
	t_grph *graph_data;

	graph_data = malloc(sizeof(t_grph));
	if (graph_data == NULL)
		return (NULL);
	return (graph_data);
}


void	destroy_graph_data(t_grph *graph_data)
{
	if (graph_data != NULL)
		free(graph_data);
}
