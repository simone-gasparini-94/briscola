#include "graphics.h"
#include "raylib.h"

void	draw_background(t_grph *graph_data)
{
	DrawTexture(graph_data->background, 0, 0, graph_data->white);
}
