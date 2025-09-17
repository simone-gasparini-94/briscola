#include <stdio.h>
#include "deck.h"
#include "play.h"
#include "player.h"

int	main(void)
{
	t_deck *deck;
	t_player *player1;
	t_player *player2;

	player1 = player_create("player1");
	player2 = player_create("player2");
	deck = deck_create();
	deck_shuffle(deck);
	play(deck, player1, player2);
	return (0);
}
