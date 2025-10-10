#include "graphics.h"
#include "raylib.h"
#include <stdbool.h>

static void	draw_header(t_grph *graph_data, t_wndw *window);
static void	draw_button(t_grph *graph_data, t_btn *play_btn, t_wndw *window);
static void draw_window_border(t_grph *graph_data, t_wndw *window);

void	draw_load_screen(t_grph *graph_data)
{
	ClearBackground(graph_data->white);
	draw_header(graph_data, &(graph_data->window));
	draw_button(graph_data, &(graph_data->play_btn), &(graph_data->window));
	draw_window_border(graph_data, &(graph_data->window));
}

bool	is_play_btn_clicked(t_btn play_btn)
{
	Vector2 mouse;

	mouse = GetMousePosition();
	return (CheckCollisionPointRec(mouse, play_btn.rectangle) == true &&
			IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true);
}

static void	draw_header(t_grph *graph_data, t_wndw *window)
{
	t_txt	header;

	header.s = "Briscola";
	header.font_size = 64;
	DrawTextEx(graph_data->font, header.s,
			(Vector2)
			{
				(window->width -
				 	MeasureTextEx(graph_data->font, header.s, header.font_size, 0).x) / 2,
				((window->height - header.font_size) / 5) * 2
			},
			header.font_size, 0, graph_data->black);
}

static void	draw_button(t_grph *graph_data, t_btn *play_btn, t_wndw *window)
{
	play_btn->txt.s = "play";
	play_btn->txt.font_size = 32;
	play_btn->rectangle.width = 160;
	play_btn->rectangle.height = 64;
	play_btn->rectangle.x = (window->width - play_btn->rectangle.width) / 2;
	play_btn->rectangle.y = ((window->height - play_btn->rectangle.height) / 5) * 3; 
	DrawRectangle(play_btn->rectangle.x, play_btn->rectangle.y,
			play_btn->rectangle.width, play_btn->rectangle.height, graph_data->orange);
	DrawRectangleLinesEx(play_btn->rectangle, 10, graph_data->black);
	DrawRectangleLinesEx(play_btn->rectangle, 8, graph_data->red);
	DrawRectangleLinesEx(play_btn->rectangle, 2, graph_data->black);
	DrawTextEx(graph_data->font, play_btn->txt.s,
			(Vector2)
			{
				play_btn->rectangle.x +
				((play_btn->rectangle.width - 
			  		MeasureTextEx(graph_data->font, play_btn->txt.s,
						play_btn->txt.font_size, 0).x) / 2),
				play_btn->rectangle.y + ((play_btn->rectangle.height - play_btn->txt.font_size) / 2)
			},
			play_btn->txt.font_size, 2, graph_data->black);
}

static void draw_window_border(t_grph *graph_data, t_wndw *window)
{
	Rectangle border;

	border = (Rectangle){0, 0, window->width, window->height};
	DrawRectangleLinesEx(border, 26, graph_data->black);
	DrawRectangleLinesEx(border, 24, graph_data->yellow);
	DrawRectangleLinesEx(border, 14, graph_data->black);
	DrawRectangleLinesEx(border, 12, graph_data->blue);
	DrawRectangleLinesEx(border, 2, graph_data->black);
}
