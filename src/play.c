#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "deck.h"
#include "play.h"
#include "player.h"
#include "print.h"
#include "get_input.h"
#include "set_up.h"

static void play_card(t_deck *deck, t_player *player);
static void	check_winner(t_deck *deck, t_player *player1, t_player *player2);
static void	gets_hand(t_deck *deck, t_player *winner, t_player *loser);
static t_card *update_hand(t_player *player);

void	play(t_deck *deck, t_player *player1, t_player *player2)
{
	t_player 	*first;
	t_player 	*second;

	set_up(deck, player1, player2);
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
		print_divider();
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
		print_divider();
		print_briscola(deck);
		first->hand = update_hand(first);	
		second->hand = update_hand(second);
		print_hand(deck, player1);
	}
}

void	draw(t_player *player, t_deck *deck, size_t i)
{
	player->hand[i] = deck->cards[deck->counter++];
}

static void	play_card(t_deck *deck, t_player *player)
{

	size_t	i;

	if (strncmp(player->name, "PLAYER2", strlen(player->name)) == 0)
		i = rand() % 3;
	else
		i = get_input(player, deck);
	printf("%s PLAYED:	", player->name);
	print_card(deck, player, i);
	player->index = i;
	player->played = player->hand[player->index];
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
