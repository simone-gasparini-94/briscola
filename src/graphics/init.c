#include "data.h"
#include "graphics.h"
#include "raylib.h"

static void	init_window(t_wndw *window);
static void	init_colors(t_grph *graph_data);
static void	init_font(t_grph *graph_data);

void	init(t_data *data, t_grph *graph_data)
{
	(void)data;
	init_window(&(graph_data->window));
	InitWindow(graph_data->window.width, graph_data->window.height, "briscola");
	init_colors(graph_data);
	init_font(graph_data);
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

static void	init_colors(t_grph *graph_data)
{
	graph_data->white = (Color){247, 247, 235, 255};
	graph_data->yellow = (Color){220, 191, 0, 255};
	graph_data->orange = (Color){224, 140, 0, 255};
	graph_data->red = (Color){214, 0, 13, 255};
	graph_data->blue = (Color){0, 60, 133, 255};
	graph_data->black = (Color){0, 0, 0, 255};
}

static void	init_font(t_grph *graph_data)
{
	graph_data->font = LoadFontEx("assets/typeface/deutsch_gothic/Deutsch.ttf", 120, 0, 0);
}
