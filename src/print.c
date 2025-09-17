#include "deck.h"
#include "player.h"
#include <stdio.h>

void	print_hand(t_deck *deck, t_player *player)
{
	size_t	i;

	printf("\nHAND:		");
	i = 0;
	while (i < 3)
	{
		printf("%s %s		", deck->ranks[player->hand[i].rank],
				deck->suits[player->hand[i].suit]);
		i++;
	}
	printf("\n");
}

void	print_briscola(t_deck *deck)
{
	printf("\nBRISCOLA:	%s %s\n\n", deck->ranks[deck->briscola.rank],
			deck->suits[deck->briscola.suit]);
}
