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

void	play(t_deck *deck, t_player *player1, t_player *player2)
{
	t_player *first;
	t_player *second;
	pick_dealer(player1, player2);
	draw_initial(deck, player1, player2);
	turn_briscola(deck);
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
		draw(first, deck, first->index);
		draw(second, deck, second->index);
		print_hand(deck, player1);
	}
}

static void check_winner(t_deck *deck, t_player *player1, t_player *player2)
{
	if (player1->played.suit == player2->played.suit)
	{
		if (player1->hand[player1->index].rank
				> player2->hand[player2->index].rank)
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
