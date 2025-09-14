#include "deck.h"
#include <stdio.h>

void	play(t_deck *deck)
{
	printf("Hand:\n");
	while (deck->counter < 3)
	{
		printf("%s %s\n",
			deck->ranks[deck->cards[deck->counter].rank],
			deck->suits[deck->cards[deck->counter].suit]);
		deck->counter++;
	}
}
