#include <stdio.h>
#include <time.h>
#include "deck.h"

int	main(void)
{
	t_deck *deck;

	deck = deck_create();
	deck_shuffle(deck);
	for (int i = 0; i < 40; i++)
		printf("suit:%d - rank:%d\n", deck->cards[i].suit, deck->cards[i].rank);
	return (0);
}
