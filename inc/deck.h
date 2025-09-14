#ifndef DECK_H
# define DECK_H

# include <stddef.h>
# include <stdbool.h>

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
	bool	shuffle;
}	t_card;

typedef struct s_deck
{
	t_card	cards[40];
	size_t	counter;
	size_t	size;
	char	*suits[4];
	char	*ranks[10];
}	t_deck;

t_deck	*deck_create(void);
void	array_create(t_deck *deck);
void	deck_shuffle(t_deck *deck);

#endif
