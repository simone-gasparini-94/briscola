#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "computer.h"
#include "deck.h"
#include "player.h"

static bool		is_points(t_deck *deck);
static size_t	take(t_deck *deck);
static size_t	leave(t_deck *deck);

size_t	handle_computer_choice(t_deck *deck)
{
	size_t	i;

	if (deck->player2->first == true)
		return (rand() % 3);
	else
	{
		if (is_points(deck) == true)
			i = take(deck);
		else
			i = leave(deck);
	}
	return (i);
}

static bool		is_points(t_deck *deck)
{
	if (deck->player1->played.rank > 4)
		return (true);
	else
		return (false);
}

static size_t	take(t_deck *deck)
{
	size_t	i;
	size_t	card_index;
	bool	higher_rank;
	bool	briscola;

	higher_rank = false;
	briscola = false;
	card_index = 0;
	i = 0;
	while (i < deck->player2->hand_size)
	{
		if (deck->player2->hand[i].rank > deck->player1->played.rank
				&& deck->player2->hand[i].suit == deck->player1->played.suit)
		{
			card_index = i;
			higher_rank = true;
		}
		i++;
	}
	if (higher_rank == false)
	{
		i = 0;
		while (i < deck->player2->hand_size)
		{
			if (deck->player2->hand[i].suit == deck->briscola.suit)
			{
				card_index = i;
				briscola = true;
			}
			i++;
		}
	}
	if (higher_rank == false && briscola == false)
	{
		i = 0;
		while (i < deck->player2->hand_size)
		{
			if (deck->player2->hand[i].rank < 5
					&& deck->player2->hand[i].suit != deck->briscola.suit)
				card_index = i;
			i++;
		}
	}
	return (card_index);
}

static size_t	leave(t_deck *deck)
{
	(void)deck;
	return (0);
}
