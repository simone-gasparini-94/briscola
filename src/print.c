#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "deck.h"
#include "player.h"

void	print_hand(t_deck *deck, t_player *player)
{
	size_t	i;

	printf("HAND:		");
	i = 0;
	while (i < player->hand_size)
	{
		printf("%zu: %s %s\n		", i + 1, deck->ranks[player->hand[i].rank],
				deck->suits[player->hand[i].suit]);
		i++;
	}
	printf("\n");
}

void	print_card(t_deck *deck, t_player *player, size_t i)
{
	printf("%zu: %s %s\n\n", i + 1, deck->ranks[player->hand[i].rank],
			deck->suits[player->hand[i].suit]);
}

void	print_briscola(t_deck *deck)
{
	printf("BRISCOLA:	%s %s\n\n", deck->ranks[deck->briscola.rank],
			deck->suits[deck->briscola.suit]);
}

void	print_score(t_player *player1, t_player *player2)
{
	if (player1->points > player2->points)
		printf("%s WON WITH %zu POINTS\n\n", player1->name, player1->points);
	else if (player2->points > player1->points)
		printf("%s WON WITH %zu POINTS\n\n", player2->name, player2->points);
	else
		printf("DRAW\n\n");
}

void	print_divider(void)
{
	struct winsize w;
	size_t	i;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1)
	{
		perror("ioctl");
		return ;
	}
	i = 0;
	while (i++ < w.ws_col)
	{
		putchar('*');
		fflush(stdout);
		usleep(4000);
	}
	printf("\n\n");
}
