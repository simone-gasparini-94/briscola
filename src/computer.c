#include <stdio.h>
#include <stdlib.h>
#include "computer.h"
#include "deck.h"

static size_t	take(t_deck *deck);
static size_t	leave(t_deck *deck);

size_t	handle_computer_choice(t_deck *deck)
{
	size_t	i;

	if (deck->first == deck->player2)
		return (rand() % 3);
	else if (deck->second == deck->player2)
	{
		if (is_points(deck->player1->played) == true)
			i = take(deck);
		else
			i = leave(deck);
	}
	return (i);
}

static size_t	take(t_deck *deck);
static size_t	leave(t_deck *deck);
