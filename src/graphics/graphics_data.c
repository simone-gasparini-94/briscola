#include <stdlib.h>
#include "graphics.h"
#include "raylib.h"

void	init_window(t_window *window);
void	init_header(t_text *header);

t_graph	*create_graph_data(void)
{
	t_graph *graph_data;

	graph_data = malloc(sizeof(t_graph));
	if (graph_data == NULL)
		return (NULL);
	init_window(&(graph_data->window));
	init_header(&(graph_data->header));
	return (graph_data);
}

void	init_window(t_window *window)
{
	window->width = 800;
	window->height = 450;
}

void	init_header(t_text *header)
{
	header->str = "BRISCOLA";
	header->font_size = 40;
}

void	destroy_graph_data(t_graph *graph_data)
{
	if (graph_data != NULL)
		free(graph_data);
}
