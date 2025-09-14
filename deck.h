#ifndef DECK_H
# define DECK_H

enum e_suit
{
	COINS,
	SWORDS,
	CUPS,
	BATONS
};

enum e_rank
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
};

typedef struct s_card
{
	enum e_suit;
	enum e_rank;
}	t_card;

typedef struct s_deck
{
	t_card cards[40];
	uint counter;
}	t_deck;
