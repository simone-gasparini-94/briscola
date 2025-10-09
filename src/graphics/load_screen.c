#include "graphics.h"
#include "raylib.h"

void	draw_load_screen(t_graph *graph_data)
{
		ClearBackground(RAYWHITE);
		DrawText("BRISCOLA",
				(graph_data->window.width - MeasureText("BRISCOLA", 40)) / 2,
				(graph_data->window.height - 40) / 2,
				40, DARKGRAY);
}

