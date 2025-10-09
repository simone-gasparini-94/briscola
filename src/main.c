#include <stdio.h>
#include "data.h"
#include "deck.h"
#include "graphics.h"
#include "play.h"
#include "player.h"
#include "print.h"
#include "raylib.h"

#define RAYLIB 1
#define CLI 0

int	main(void)
{
	t_data *data;
	t_graph *graph_data;

	data = create_data();
	#if RAYLIB
	graph_data = create_graph_data();
	InitWindow(800, 450, "briscola");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(DARKBROWN);
			DrawText("Briscola", 400, 225, 20, LIGHTGRAY);
		EndDrawing();
	}
	destroy_graph_data(graph_data);
	CloseWindow();
	#endif
	#if CLI
	play(data->deck, data->player1, data->player2);
	#endif
	destroy_data(data);
	return (0);
}
