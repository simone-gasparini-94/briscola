#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h"
#include "player.h"
#include "print.h"

static void	pick_dealer(t_player *player1, t_player *player2);
static void draw_initial(t_deck *deck, t_player *player1, t_player *player2);
static void draw(t_player *player, t_deck *deck, size_t i);
static void turn_briscola(t_deck *deck);
static void play_card(t_deck *deck, t_player *player);
static void	check_winner(t_deck *deck, t_player *player1, t_player *player2);
static void	gets_hand(t_deck *deck, t_player *winner, t_player *loser);
static t_card *update_hand(t_player *player);

void	play(t_deck *deck, t_player *player1, t_player *player2)
{
	t_player 	*first;
	t_player 	*second;

	pick_dealer(player1, player2);
	turn_briscola(deck);
	draw_initial(deck, player1, player2);
	while (deck->counter < deck->size)
	{
		if (player1->first == true)
		{
			first = player1;
			second = player2;
		}
		else
		{
			first = player2;
			second = player1;
		}
		play_card(deck, first);
		play_card(deck, second);
		check_winner(deck, player1, player2);
		print_briscola(deck);
		draw(first, deck, first->index);
		draw(second, deck, second->index);
		print_hand(deck, player1);
	}
	while (first->hand_size > 0)
	{
		play_card(deck, first);
		play_card(deck, second);
		check_winner(deck, player1, player2);
		first->hand = update_hand(first);	
		second->hand = update_hand(second);
		print_hand(deck, player1);
	}
}

static t_card *update_hand(t_player *player)
{
	t_card *new_hand;
	size_t	i;
	size_t	j;

	player->hand_size--;
	new_hand = malloc(sizeof(t_card) * player->hand_size);
	if (new_hand == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < player->hand_size + 1)
	{
		if (!(player->hand[i].suit == player->played.suit
					&& player->hand[i].rank == player->played.rank))
			new_hand[j++] = player->hand[i++];
		else
			i++;
	}
	free(player->hand);
	return (new_hand);
}

static void check_winner(t_deck *deck, t_player *player1, t_player *player2)
{
	if (player1->played.suit == player2->played.suit)
	{
		if (player1->played.rank > player2->played.rank)
			gets_hand(deck, player1, player2);
		else
			gets_hand(deck, player2, player1);
	}
	else
	{
		if (player1->played.suit == deck->briscola.suit)
			gets_hand(deck, player1, player2);
		else if (player2->played.suit == deck->briscola.suit)
			gets_hand(deck, player2, player1);
		else
		{
			if (player1->first == true)
				gets_hand(deck, player1, player2);
			else
				gets_hand(deck, player2, player1);
		}
	}
}

static void	gets_hand(t_deck *deck, t_player *winner, t_player *loser)
{
	winner->first = true;
	loser->first = false;
	winner->points += deck->values[winner->played.rank];
	loser->points += deck->values[loser->played.rank];
	printf("%s TAKES\n\n", winner->name);
}


static void	pick_dealer(t_player *player1, t_player *player2)
{
	size_t	i;

	printf("\n");
	i = rand() % 2;
	if (i == 0)
	{
		player1->dealer = true;
		player2->dealer = false;
		player1->first = false;
		player2->first = true;
		printf("%s IS THE DEALER\n\n", player1->name);
		printf("%s STARTS\n\n", player2->name);
	}
	else
	{
		player1->dealer = false;
		player2->dealer = true;
		player1->first = true;
		player2->first = false;
		printf("%s IS THE DEALER\n\n", player2->name);
		printf("%s STARTS\n\n", player1->name);
	}
}

static void draw_initial(t_deck *deck, t_player *player1, t_player *player2)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		draw(player1, deck, i);
		draw(player2, deck, i);
		i++;
	}
	print_hand(deck, player1);
}

static void turn_briscola(t_deck *deck)
{
	deck->briscola = deck->cards[deck->size - 1];
	print_briscola(deck);
}

static void	play_card(t_deck *deck, t_player *player)
{
	size_t	i;

	if (strncmp(player->name, "PLAYER2", strlen(player->name)) == 0)
	{
		i = rand() % 3;
	}
	else
	{
		printf("PLAY A CARD:	");
		scanf("%zu", &i);
		printf("\n");
	}
	printf("%s PLAYED:	", player->name);
	print_card(deck, player, i);
	player->index = i;
	player->played = player->hand[player->index];
}

static void	draw(t_player *player, t_deck *deck, size_t i)
{
	player->hand[i] = deck->cards[deck->counter++];
}
