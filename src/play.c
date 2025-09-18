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

void	play(t_deck *deck, t_player *player1, t_player *player2)
{
	pick_dealer(player1, player2);
	draw_initial(deck, player1, player2);
	turn_briscola(deck);
	if (player1->dealer == true)
	{
		play_card(deck, player2);
		play_card(deck, player1);
	}
	else
	{
		play_card(deck, player1);
		play_card(deck, player2);
	}
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
		printf("%s IS THE DEALER\n\n", player1->name);
		printf("%s STARTS\n\n", player2->name);
	}
	else
	{
		player1->dealer = false;
		player2->dealer = true;
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
	deck->briscola = deck->cards[deck->counter++];
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
	player->index_played = i;
}

static void	draw(t_player *player, t_deck *deck, size_t i)
{
	player->hand[i] = deck->cards[deck->counter++];
}
