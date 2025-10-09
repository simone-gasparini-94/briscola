#include <stdio.h>
#include "data.h"
#include "deck.h"
#include "play.h"
#include "player.h"
#include "print.h"
#include "raylib.h"

#define RAYLIB 0
#define CLI 1

int	main(void)
{
	t_data *data;

	data = create_data();
	#if RAYLIB
	InitWindow(800, 450, "briscola");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("Briscola", 190, 200, 20, LIGHTGRAY);
		EndDrawing();
	}
	CloseWindow();
	#endif
	#if CLI
	play(data->deck, data->player1, data->player2);
	#endif
	destroy_data(data);
	return (0);
}
