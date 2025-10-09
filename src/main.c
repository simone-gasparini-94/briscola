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
	init(data, graph_data);
	destroy_graph_data(graph_data);
	#endif
	#if CLI
	play(data->deck, data->player1, data->player2);
	#endif
	destroy_data(data);
	return (0);
}
