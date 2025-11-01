#include "data.h"
#include "deck.h"
#include "player.h"
#include "graphics.h"
#include "interaction.h"
#include "raylib.h"
#include "set_up.h"

static void draw_hand(t_data *data, t_player *player, t_grph *graph_data);
static void	draw_card(t_card card, t_grph *graph_data);
static void draw_briscola(t_deck *deck, t_grph *graph_data);
static void draw_deck(t_deck *deck, t_grph *graph_data);
static void draw_played(t_player *player1, t_player *player2, t_grph *graph_data);

void	draw_play_screen(t_data *data, t_grph *graph_data)
{
	ClearBackground(graph_data->white);
	draw_background(graph_data);
	draw_hand(data, data->player1, graph_data);
	draw_briscola(data->deck, graph_data);
	draw_deck(data->deck, graph_data);
	draw_played(data->player1, data->player2, graph_data);
}

static void draw_hand(t_data *data, t_player *player, t_grph *graph_data)
{
	t_card	card;
	size_t	i;
	size_t	hand_width;
	size_t	hand_height;

	card.rectangle.width = data->deck->cards[0].rectangle.width;
	card.rectangle.height = data->deck->cards[0].rectangle.height;
	hand_width = (card.rectangle.width * player->hand_size)
		+ (graph_data->margin * (player->hand_size - 1));
	hand_height = card.rectangle.height + graph_data->margin;
	i = 0;
	while (i < player->hand_size)
	{
		card.rectangle.x = ((graph_data->window.width - hand_width) / 2)
			+ ((card.rectangle.width + graph_data->margin) * i);
		card.rectangle.y = graph_data->window.height
			- (hand_height + graph_data->margin + graph_data->window.border);
		card.img = data->deck->cards[i].img;
		if (is_mouse_hover(card.rectangle) == true)
			card.rectangle.y -= graph_data->margin;
		draw_card(card, graph_data);
		i++;
	}
}

static void	draw_card(t_card card, t_grph *graph_data)
{
	DrawRectangleRounded(card.rectangle, 0.1f, 12, graph_data->white);
	DrawTexturePro(card.img,
					(Rectangle){0, 0, card.img.width, card.img.height},
					card.rectangle,
					(Vector2){0, 0},
					0,
					graph_data->white);
	DrawRectangleRoundedLinesEx(card.rectangle, 0.1f, 12, 2, graph_data->black);
}

static void draw_briscola(t_deck *deck, t_grph *graph_data)
{
	if (deck->counter >= deck->size)
		return ;
	deck->briscola.rectangle.x = graph_data->external_padding + graph_data->window.border
		+ (deck->briscola.rectangle.width) - (graph_data->margin * 2);
	deck->briscola.rectangle.y = (graph_data->window.height - deck->briscola.rectangle.height) / 2;
	draw_card(deck->briscola, graph_data);
}

static void draw_deck(t_deck *deck, t_grph *graph_data)
{
	size_t	i;
	float	z;

	if (deck->counter + 1 >= deck->size)
		return ;
	i = 0;
	z = 0.0f;
	while (i < deck->size - deck->counter - 1)
	{
		deck->back.rectangle.x = graph_data->external_padding + graph_data->window.border - z;
		deck->back.rectangle.y =
			(graph_data->window.height - deck->briscola.rectangle.height) / 2 - z;
		draw_card(deck->back, graph_data);
		i++;
		z += 0.2f;
	}
}

static void draw_played(t_player *player1, t_player *player2, t_grph *graph_data)
{
	player1->played.rectangle.x = (graph_data->window.width - player1->played.rectangle.width) / 2 - 80;
	player1->played.rectangle.y = (graph_data->window.height - player1->played.rectangle.height) / 2;
	draw_card(player1->played, graph_data);
	player2->played.rectangle.x = (graph_data->window.width - player2->played.rectangle.width) / 2 + 80;
	player2->played.rectangle.y = (graph_data->window.height - player2->played.rectangle.height) / 2;
	draw_card(player2->played, graph_data);
}
