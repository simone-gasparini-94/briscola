#ifndef DECK_H
# define DECK_H

# include <stddef.h>

typedef enum Suit
{
	COINS,
	SWORDS,
	CUPS,
	BATONS
}	e_suit;

typedef enum Rank
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
}	e_rank;

typedef struct s_card
{
	e_suit	suit;
	e_rank	rank;
}	t_card;

typedef struct s_deck
{
	t_card	cards[40];
	size_t	counter;
	size_t	size;
}	t_deck;

t_deck	deck_create(void);

#endif
