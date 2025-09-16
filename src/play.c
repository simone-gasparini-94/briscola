#include "deck.h"
#include "player.h"
#include <stdio.h>

static void draw(t_player *player, t_deck *deck, size_t i);

void	play(t_deck *deck, t_player *player1, t_player *player2)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		draw(player1, deck, i);
		draw(player2, deck, i);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		printf("%s %s\n", deck->ranks[player1->hand[i].rank],
				deck->suits[player1->hand[i].suit]);
		i++;
	}
}

static void	draw(t_player *player, t_deck *deck, size_t i)
{
	player->hand[i] = deck->cards[deck->counter++];
}
