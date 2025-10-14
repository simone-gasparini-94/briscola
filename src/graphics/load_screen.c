#include "graphics.h"
#include "raylib.h"
#include <stdbool.h>

static void	draw_header(t_grph *graph_data, t_wndw *window);
static void	draw_button(t_grph *graph_data, t_btn *play_btn, t_wndw *window);
static void draw_images(t_grph *graph_data);

void	draw_load_screen(t_grph *graph_data)
{
	ClearBackground(graph_data->white);
	draw_header(graph_data, &(graph_data->window));
	draw_button(graph_data, &(graph_data->play_btn), &(graph_data->window));
	draw_images(graph_data);
}

static void	draw_header(t_grph *graph_data, t_wndw *window)
{
	t_txt	header;

	header.s = "Briscola";
	header.font_size = 80;
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
			play_btn->rectangle.width, play_btn->rectangle.height, graph_data->yellow);
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

static void draw_images(t_grph *graph_data)
{
	DrawTexturePro(graph_data->coin,
					(Rectangle){0, 0, graph_data->coin.width, graph_data->coin.height},
					(Rectangle){0, 0, 100, 100},
					(Vector2){0, 0}, 0, graph_data->white);
	DrawTexturePro(graph_data->coin,
					(Rectangle){0, 0, graph_data->coin.width, graph_data->coin.height},
					(Rectangle)
					{0, graph_data->window.height - 100,
					100, 100},
					(Vector2){0, 0}, 0, graph_data->white);
	DrawTexturePro(graph_data->coin,
					(Rectangle){0, 0, graph_data->coin.width, graph_data->coin.height},
					(Rectangle)
					{graph_data->window.width - 100,
					0, 100, 100},
					(Vector2){0, 0}, 0, graph_data->white);
	DrawTexturePro(graph_data->coin,
					(Rectangle){0, 0, graph_data->coin.width, graph_data->coin.height},
					(Rectangle)
					{graph_data->window.width - 100,
					graph_data->window.height - 100,
					100, 100},
					(Vector2){0, 0}, 0, graph_data->white);
}

