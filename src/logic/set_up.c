#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "play.h"
#include "player.h"
#include "print.h"

static void	pick_dealer(t_player *player1, t_player *player2);
static void draw_initial(t_deck *deck, t_player *player1, t_player *player2);
static void turn_briscola(t_deck *deck);

void	set_up(t_deck *deck, t_player *player1, t_player *player2)
{
	pick_dealer(player1, player2);
	turn_briscola(deck);
	draw_initial(deck, player1, player2);
	player1->played = deck->cards[10];
	player2->played = deck->cards[25];
}

static void	pick_dealer(t_player *player1, t_player *player2)
{
	size_t	i;

	printf("\n");
	i = rand() % 2;
	if (i == 0)
	{
		player1->dealer = true;
		player2->dealer = false;
		player1->first = false;
		player2->first = true;
		printf("%s IS THE DEALER\n\n", player1->name);
		printf("%s STARTS\n\n", player2->name);
	}
	else
	{
		player1->dealer = false;
		player2->dealer = true;
		player1->first = true;
		player2->first = false;
		printf("%s IS THE DEALER\n\n", player2->name);
		printf("%s STARTS\n\n", player1->name);
	}
}

static void turn_briscola(t_deck *deck)
{
	deck->briscola = deck->cards[deck->size - 1];
	print_briscola(deck);
}

static void draw_initial(t_deck *deck, t_player *player1, t_player *player2)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		draw(player1, deck, i);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		draw(player2, deck, i);
		i++;
	}
	print_hand(deck, player1);
}
