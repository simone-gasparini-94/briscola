#include "graphics.h"
#include "raylib.h"
#include <stdbool.h>

static void	draw_header(t_wndw *window);
static void	draw_button(t_btn *play_btn, t_wndw *window);

void	draw_load_screen(t_grph *graph_data)
{
	ClearBackground(RAYWHITE);
	draw_header(&(graph_data->window));
	draw_button(&(graph_data->play_btn), &(graph_data->window));
}

bool	is_play_btn_clicked(t_btn play_btn)
{
	Vector2 mouse;

	mouse = GetMousePosition();
	return (CheckCollisionPointRec(mouse, play_btn.rectangle) == true &&
			IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true);
}

static void	draw_header(t_wndw *window)
{
	t_txt	header;

	header.s = "BRISCOLA";
	header.font_size = 40;
	DrawText(header.s,
			(window->width - MeasureText(header.s, header.font_size)) / 2,
			((window->height - header.font_size) / 5) * 2,	
			header.font_size, DARKGRAY);
}

static void	draw_button(t_btn *play_btn, t_wndw *window)
{
	play_btn->txt.s = "PLAY";
	play_btn->txt.font_size = 24;
	play_btn->rectangle.width = 160;
	play_btn->rectangle.height = 64;
	play_btn->rectangle.x = (window->width - play_btn->rectangle.width) / 2;
	play_btn->rectangle.y = ((window->height - play_btn->rectangle.height) / 5) * 3; 
	DrawRectangle(play_btn->rectangle.x, play_btn->rectangle.y,
			play_btn->rectangle.width, play_btn->rectangle.height, YELLOW);
	DrawRectangleLinesEx(play_btn->rectangle, 4, DARKGRAY);
	DrawText(play_btn->txt.s,
			play_btn->rectangle.x +
			((play_btn->rectangle.width - 
			  MeasureText(play_btn->txt.s, play_btn->txt.font_size)) / 2),
			play_btn->rectangle.y + ((play_btn->rectangle.height - play_btn->txt.font_size) / 2),
			play_btn->txt.font_size, DARKGRAY);
}
