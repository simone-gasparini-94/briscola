#include <stdio.h>
#include "deck.h"
#include "player.h"
#include "print.h"

static void draw_initial(t_deck *deck, t_player *player1, t_player *player2);
static void draw(t_player *player, t_deck *deck, size_t i);
static void turn_briscola(t_deck *deck);
static void play_card(t_deck *deck, t_player *player);

void	play(t_deck *deck, t_player *player1, t_player *player2)
{
	draw_initial(deck, player1, player2);
	turn_briscola(deck);
	play_card(deck, player1);
}

static void draw_initial(t_deck *deck, t_player *player1, t_player *player2)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		draw(player1, deck, i);
		draw(player2, deck, i);
		i++;
	}
	print_hand(deck, player1);
}

static void turn_briscola(t_deck *deck)
{
	deck->briscola = deck->cards[deck->counter++];
	print_briscola(deck);
}

static void	play_card(t_deck *deck, t_player *player)
{
	size_t	i;

	printf("\nPLAY A CARD:	");
	scanf("%zu", &i);
	printf("\n%s PLAYED:	", player->name);
	print_card(deck, player, i);
	player->index_played = i;
}

static void	draw(t_player *player, t_deck *deck, size_t i)
{
	player->hand[i] = deck->cards[deck->counter++];
}
