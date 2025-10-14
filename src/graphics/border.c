#include "graphics.h"
#include "raylib.h"

void draw_window_border(t_grph *graph_data, t_wndw *window)
{
	Rectangle border;

	border = (Rectangle){0, 0, window->width, window->height};
	DrawRectangleLinesEx(border, 26, graph_data->black);
	DrawRectangleLinesEx(border, 24, graph_data->yellow);
	DrawRectangleLinesEx(border, 14, graph_data->black);
	DrawRectangleLinesEx(border, 12, graph_data->blue);
	DrawRectangleLinesEx(border, 2, graph_data->black);
	window->border = 26;
}
