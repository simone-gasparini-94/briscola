#include "data.h"
#include "graphics.h"
#include "raylib.h"

static void	init_window(t_window *window);

void	init(t_data *data, t_graph *graph_data)
{
	(void)data;
	init_window(&(graph_data->window));
	InitWindow(graph_data->window.width, graph_data->window.height, "briscola");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
			draw_load_screen(graph_data);
		EndDrawing();
	}
	CloseWindow();
}

static void	init_window(t_window *window)
{
	window->width = 800;
	window->height = 450;
}

