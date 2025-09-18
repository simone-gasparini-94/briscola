#include <stdio.h>
#include "deck.h"
#include "player.h"

void	print_hand(t_deck *deck, t_player *player)
{
	size_t	i;

	printf("HAND:		");
	i = 0;
	while (i < 3)
	{
		printf("%zu: %s %s\n		", i, deck->ranks[player->hand[i].rank],
				deck->suits[player->hand[i].suit]);
		i++;
	}
	printf("\n");
}

void	print_card(t_deck *deck, t_player *player, size_t i)
{
	printf("%zu: %s %s\n\n", i, deck->ranks[player->hand[i].rank],
			deck->suits[player->hand[i].suit]);
}

void	print_briscola(t_deck *deck)
{
	printf("BRISCOLA:	%s %s\n\n", deck->ranks[deck->briscola.rank],
			deck->suits[deck->briscola.suit]);
}
