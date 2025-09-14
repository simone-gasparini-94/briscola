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
	array_create(deck);
	return (deck);
}

void	array_create(t_deck *deck)
{
	deck->suits[0] = "COINS";
	deck->suits[1] = "SWORDS";
	deck->suits[2] = "CUPS";
	deck->suits[3] = "BATONS";
	deck->ranks[0] = "TWO";
	deck->ranks[1] = "FOUR";
	deck->ranks[1] = "FOUR";
	deck->ranks[2] = "FIVE";
	deck->ranks[3] = "SIX";
	deck->ranks[4] = "SEVEN";
	deck->ranks[5] = "JACK";
	deck->ranks[6] = "KNIGHT";
	deck->ranks[7] = "KING";
	deck->ranks[8] = "THREE";
	deck->ranks[9] = "ACE";
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
