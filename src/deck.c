#include "deck.h"

t_deck	deck_create(void)
{
	t_deck deck;
	size_t	i;

	deck.size = 40;
	deck.counter = 0;
	i = 0;
	while (i < deck.size)
	{
		deck.cards[i].suit = i / 10;
		deck.cards[i].rank = i % 10;
		i++;
	}
	return (deck);
}
