#include <stdio.h>
#include "deck.h"
#include "play.h"

int	main(void)
{
	t_deck *deck;

	deck = deck_create();
	deck_shuffle(deck);
	play(deck);
	return (0);
}
