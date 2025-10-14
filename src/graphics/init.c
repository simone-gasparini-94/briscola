#include "data.h"
#include "deck.h"
#include "graphics.h"
#include "interaction.h"
#include "raylib.h"
#include "set_up.h"
#include <stdio.h>

static void	init_window(t_wndw *window);
static void	init_colors(t_grph *graph_data);
static void	init_font(t_grph *graph_data);
static void	init_background(t_grph *graph_data);
static void	init_dimensions(t_grph *graph_data);
static void	init_card_size(t_deck *deck);
static void	upload_card_img(t_deck *deck);

void	init(t_data *data, t_grph *graph_data)
{
	t_screen screen;

	screen = LOAD_SCREEN;
	init_window(&(graph_data->window));
	InitWindow(graph_data->window.width, graph_data->window.height, "briscola");
	init_colors(graph_data);
	init_font(graph_data);
	init_dimensions(graph_data);
	init_background(graph_data);
	init_card_size(data->deck);
	upload_card_img(data->deck);
	deck_shuffle(data->deck);
	set_up(data->deck, data->player1, data->player2);
	SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		if (screen == LOAD_SCREEN)
		{
			draw_load_screen(graph_data);
			if (is_btn_clicked(graph_data->play_btn.rectangle) == true)
				screen = PLAY_SCREEN;
		}
		else if (screen == PLAY_SCREEN)
			draw_play_screen(data, graph_data);
		EndDrawing();
	}
	CloseWindow();
}

static void	init_window(t_wndw *window)
{
	window->width = 1280;
	window->height = 720;
}

static void	init_background(t_grph *graph_data)
{
	graph_data->background =
	LoadTexture("assets/textures/decrepit/decrepit_wallpaper_diff_4k.jpg");
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

static void init_dimensions(t_grph *graph_data)
{
	graph_data->margin = 10;
	graph_data->external_padding = 100;
}

static void	init_card_size(t_deck *deck)
{
	size_t	i;
	size_t	width;
	size_t	height;

	width = 102;
	height = 164;
	i = 0;
	while (i < deck->size)
	{
		deck->cards[i].rectangle.width = width;
		deck->cards[i].rectangle.height = height;
		i++;
	}
	deck->briscola.rectangle.width = width;
	deck->briscola.rectangle.height = height;
	deck->back.rectangle.width = width;
	deck->back.rectangle.height = height;
}

static void	upload_card_img(t_deck *deck)
{
	char	path[64];
	size_t	i;

	i = 1;
	while (i <= deck->size)
	{
		snprintf(path, sizeof(path), "assets/images/%zu.jpg", i);
		deck->cards[i].img = LoadTexture(path);
		i++;
	}
	deck->back.img = LoadTexture("assets/images/back.jpg");
}
