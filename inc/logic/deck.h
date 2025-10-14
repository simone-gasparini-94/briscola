#ifndef DECK_H
# define DECK_H

# include <stddef.h>
# include <stdbool.h>
# include "raylib.h"

# define NUM_CARDS 40
# define NUM_SUITS 4
# define NUM_RANKS 10

typedef struct s_player t_player;

typedef enum e_suit
{
	COINS,
	SWORDS,
	CUPS,
	BATONS
}	t_suit;

typedef enum e_rank
{
	TWO,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	JACK,
	KNIGHT,
	KING,
	THREE,
	ACE
}	t_rank;

typedef struct s_card
{
	Rectangle rectangle;
	Texture2D img;
	t_suit	suit;
	t_rank	rank;
	bool	shuffle;
}	t_card;

typedef struct s_deck
{
	t_player	*player1;
	t_player	*player2;
	t_player	*first;
	t_player	*second;
	t_card		cards[NUM_CARDS];
	t_card		briscola;
	t_card		back;
	char		*ranks[NUM_RANKS];
	char		*suits[NUM_SUITS];
	size_t		values[NUM_RANKS];
	size_t		counter;
	size_t		size;
}	t_deck;

t_deck	*deck_create(t_player *player1, t_player *player2);
void	deck_shuffle(t_deck *deck);

#endif
