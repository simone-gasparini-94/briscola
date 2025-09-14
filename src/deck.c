#include "deck.h"
#include <stdlib.h>
#include <time.h>

t_deck	*deck_create(void)
{
	t_deck *deck;
	size_t	i;

	deck = malloc(sizeof(*deck));
	if (deck == NULL)
		return (NULL);
	deck->size = 40;
	deck->counter = 0;
	i = 0;
	while (i < deck->size)
	{
		deck->cards[i].suit = i / 10;
		deck->cards[i].rank = i % 10;
		deck->cards[i].shuffle = false;
		i++;
	}
	return (deck);
}

void	deck_shuffle(t_deck *deck)
{
	t_card	deck_shuffle[40];
	size_t	i;
	size_t	random_value;

	srand(time(NULL));
	random_value = rand() % 40;
	i = 0;
	while (i < deck->size)
	{
		while (deck->cards[random_value].shuffle == true)
			random_value = rand() % 40;
		deck_shuffle[i] = deck->cards[random_value];
		deck->cards[random_value].shuffle = true;
		i++;
	}
	i = 0;
	while (i < deck->size)
	{
		deck->cards[i] = deck_shuffle[i];
		i++;
	}
}
