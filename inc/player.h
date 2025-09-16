#ifndef PLAYER_H
# define PLAYER_H

# include "deck.h"

typedef struct s_player
{
	t_card	hand[3];
	size_t	points;
}	t_player;

t_player *player_create(void);

#endif
