#include "data.h"
#include "player.h"
#include "graphics.h"
#include "raylib.h"
#include "set_up.h"

static void draw_hand(t_player *player, t_grph *graph_data);

void	draw_play_screen(t_data *data, t_grph *graph_data)
{
	ClearBackground(graph_data->white);	
	draw_hand(data->player1, graph_data);
}

static void draw_hand(t_player *player, t_grph *graph_data)
{
	t_crd	card;
	size_t	i;
	size_t	hand_width;
	size_t	hand_height;
	size_t	margin;

	margin = 10;
	card.rectangle.width = graph_data->card.rectangle.width;
	card.rectangle.height = graph_data->card.rectangle.height;
	hand_width = (card.rectangle.width * player->hand_size)
		+ (margin * (player->hand_size - 1));
	hand_height = card.rectangle.height + margin;
	i = 0;
	while (i < player->hand_size)
	{
		card.rectangle.x = ((graph_data->window.width - hand_width) / 2)
			+ ((card.rectangle.width + margin) * i);
		card.rectangle.y = graph_data->window.height - hand_height;
		DrawRectangleRounded(card.rectangle, 0.3f, 12, graph_data->white);
		DrawRectangleRoundedLinesEx(card.rectangle, 0.3f, 12, 2, graph_data->black);
		i++;
	}
}
