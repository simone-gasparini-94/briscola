#include "data.h"
#include "graphics.h"
#include "raylib.h"

void	init(t_data *data, t_graph *graph_data)
{
	(void)data;
	InitWindow(graph_data->window.width, graph_data->window.height, "briscola");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText(graph_data->header.str,
					(graph_data->window.width
					 - MeasureText(graph_data->header.str,
						 graph_data->header.font_size)) / 2,
					(graph_data->window.height - graph_data->header.font_size) / 2,
					graph_data->header.font_size,
					DARKGRAY);
		EndDrawing();
	}
	CloseWindow();
}
