#include <stdio.h>
#include "deck.h"
#include "play.h"
#include "player.h"
#include "print.h"
#include "raylib.h"

int	main(void)
{
	t_deck *deck;
	t_player *player1;
	t_player *player2;
	
	player1 = player_create("PLAYER1");
	player2 = player_create("PLAYER2");
	deck = deck_create(player1, player2);
	deck_shuffle(deck);
	play(deck, player1, player2);
	print_score(player1, player2);
	return (0);
}
