#include "data.h"
#include "graphics.h"
#include "raylib.h"

static void	init_window(t_wndw *window);

void	init(t_data *data, t_grph *graph_data)
{
	(void)data;
	init_window(&(graph_data->window));
	InitWindow(graph_data->window.width, graph_data->window.height, "briscola");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
			draw_load_screen(graph_data);
			if (is_play_btn_clicked(graph_data->play_btn) == true)
				break ;
		EndDrawing();
	}
	CloseWindow();
}

static void	init_window(t_wndw *window)
{
	window->width = 640;
	window->height = 480;
}

