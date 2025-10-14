#include "deck.h"
#include <stdlib.h>
#include <time.h>

static void	array_str_create(t_deck *deck);
static void array_values_create(t_deck *deck);

t_deck	*deck_create(t_player *player1, t_player *player2)
{
	t_deck *deck;
	size_t	i;

	deck = malloc(sizeof(*deck));
	if (deck == NULL)
		return (NULL);
	deck->player1 = player1;
	deck->player2 = player2;
	deck->size = NUM_CARDS;
	deck->counter = 0;
	i = 0;
	while (i < deck->size)
	{
		deck->cards[i].suit = i / NUM_RANKS;
		deck->cards[i].rank = i % NUM_RANKS;
		deck->cards[i].shuffle = false;
		i++;
	}
	array_str_create(deck);
	array_values_create(deck);
	return (deck);
}

static void	array_str_create(t_deck *deck)
{
	deck->suits[0] = "COINS";
	deck->suits[1] = "CUPS";
	deck->suits[2] = "SWORDS";
	deck->suits[3] = "BATONS";
	deck->ranks[0] = "TWO";
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

static void array_values_create(t_deck *deck)
{
	deck->values[0] = 0;
	deck->values[1] = 0;
	deck->values[2] = 0;
	deck->values[3] = 0;
	deck->values[4] = 0;
	deck->values[5] = 2;
	deck->values[6] = 3;
	deck->values[7] = 4;
	deck->values[8] = 10;
	deck->values[9] = 11;
}

void	deck_shuffle(t_deck *deck)
{
	t_card	deck_shuffle[NUM_CARDS];
	size_t	i;
	size_t	random_value;

	srand(time(NULL));
	random_value = rand() % NUM_CARDS;
	i = 0;
	while (i < deck->size)
	{
		while (deck->cards[random_value].shuffle == true)
			random_value = rand() % NUM_CARDS;
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
